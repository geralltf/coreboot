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
#include <ec/acpi/ec.h>
#include <northbridge/intel/ironlake/ironlake.h>
#include <southbridge/intel/bd82x6x/pch.h>
#include "dock.h"
#include <drivers/intel/gma/int15.h>
#include <cpu/x86/lapic.h>
#include <drivers/lenovo/lenovo.h>

static void fill_ssdt(struct device *device)
{
	drivers_lenovo_serial_ports_ssdt_generate("\\_SB.PCI0.LPCB", 0);
}

static void mainboard_enable(struct device *dev)
{
	dev->ops->acpi_fill_ssdt_generator = fill_ssdt;

	/* If we're resuming from suspend, blink suspend LED */
	if (acpi_is_wakeup_s3())
		ec_write(0x0c, 0xc7);

	install_intel_vga_int15_handler(GMA_INT15_ACTIVE_LFP_INT_LVDS,
					GMA_INT15_PANEL_FIT_DEFAULT,
					GMA_INT15_BOOT_DISPLAY_LFP, 2);

	init_dock();
}

struct chip_operations mainboard_ops = {
	.enable_dev = mainboard_enable,
};
