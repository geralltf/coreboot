/*
 * This file is part of the coreboot project.
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of
 * the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <device/device.h>
#include <device/pci.h>
#include <console/console.h>
#include <arch/io.h>
#include <device/mmio.h>
#include <cpu/x86/smm.h>
#include <cpu/intel/smm_reloc.h>
#include <soc/iomap.h>
#include <soc/pmc.h>
#include <soc/smm.h>

/* Save settings which will be committed in SMI functions. */
static uint32_t smm_save_params[SMM_SAVE_PARAM_COUNT];

void smm_southcluster_save_param(int param, uint32_t data)
{
	smm_save_params[param] = data;
}

void smm_southbridge_clear_state(void)
{
	uint32_t smi_en;

	/* Log events from chipset before clearing */
	if (CONFIG(ELOG))
		southcluster_log_state();

	printk(BIOS_DEBUG, "Initializing Southbridge SMI...");
	printk(BIOS_SPEW, " pmbase = 0x%04x\n", get_pmbase());

	smi_en = inl(get_pmbase() + SMI_EN);
	if (smi_en & APMC_EN) {
		printk(BIOS_INFO, "SMI# handler already enabled?\n");
		return;
	}

	/* Dump and clear status registers */
	clear_smi_status();
	clear_pm1_status();
	clear_tco_status();
	clear_gpe_status();
	clear_alt_status();
	clear_pmc_status();
}

static void smm_southcluster_route_gpios(void)
{
	u32 *gpio_rout = (u32 *)(PMC_BASE_ADDRESS + GPIO_ROUT);
	const unsigned short alt_gpio_smi = ACPI_BASE_ADDRESS + ALT_GPIO_SMI;
	uint32_t alt_gpio_reg = 0;
	uint32_t route_reg = smm_save_params[SMM_SAVE_PARAM_GPIO_ROUTE];
	int i;

	printk(BIOS_DEBUG, "GPIO_ROUT = %08x\n", route_reg);

	/* Start the routing for the specific gpios. */
	write32(gpio_rout, route_reg);

	/* Enable SMIs for the gpios that are set to trigger the SMI. */
	for (i = 0; i < 16; i++) {
		if ((route_reg & ROUTE_MASK) == ROUTE_SMI) {
			alt_gpio_reg |= (1 << i);
		}
		route_reg >>= 2;
	}
	printk(BIOS_DEBUG, "ALT_GPIO_SMI = %08x\n", alt_gpio_reg);

	outl(alt_gpio_reg, alt_gpio_smi);
}

void smm_southbridge_enable_smi(void)
{
	uint16_t pm1_events = PWRBTN_EN | GBL_EN;

	printk(BIOS_DEBUG, "Enabling SMIs.\n");
	if (!smm_save_params[SMM_SAVE_PARAM_PCIE_WAKE_ENABLE])
		pm1_events |= PCIEXPWAK_DIS;
	enable_pm1(pm1_events);
	disable_gpe(PME_B0_EN);

	/* Set up the GPIO route. */
	smm_southcluster_route_gpios();

	/* Enable SMI generation:
	 *  - on APMC writes (io 0xb2)
	 *  - on writes to SLP_EN (sleep states)
	 *  - on writes to GBL_RLS (bios commands)
	 * No SMIs:
	 *  - on TCO events
	 *  - on microcontroller writes (io 0x62/0x66)
	 */
	enable_smi(APMC_EN | SLP_SMI_EN | GBL_SMI_EN | EOS);
}

void smm_setup_structures(void *gnvs, void *tcg, void *smi1)
{
	/*
	 * Issue SMI to set the gnvs pointer in SMM.
	 * tcg and smi1 are unused.
	 *
	 * EAX = APM_CNT_GNVS_UPDATE
	 * EBX = gnvs pointer
	 * EDX = APM_CNT
	 */
	asm volatile (
		"outb %%al, %%dx\n\t"
		: /* ignore result */
		: "a" (APM_CNT_GNVS_UPDATE),
		  "b" ((uint32_t)gnvs),
		  "d" (APM_CNT)
	);
}
