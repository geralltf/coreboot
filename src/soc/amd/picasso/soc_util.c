/* SPDX-License-Identifier: GPL-2.0-only */
/* This file is part of the coreboot project. */

#include <arch/cpu.h>
#include <soc/cpu.h>
#include <soc/soc_util.h>

int soc_is_pollock(void)
{
	return soc_is_zen_plus() && CONFIG(AMD_FT5);
}

int soc_is_dali(void)
{
	return soc_is_raven2() && CONFIG(AMD_FP5);
}

int soc_is_picasso(void)
{
	return soc_is_zen_plus() && CONFIG(AMD_FP5);
}

int soc_is_raven2(void)
{
	/* mask lower model number nibble and stepping */
	return cpuid_eax(1) >> 8 == RAVEN2_CPUID >> 8;
}

int soc_is_zen_plus(void)
{
	/* mask lower model number nibble and stepping */
	return cpuid_eax(1) >> 8 == PICASSO_CPUID >> 8;
}
