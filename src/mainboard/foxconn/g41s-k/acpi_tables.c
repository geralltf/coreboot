/*
 * This file is part of the coreboot project.
 *
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#include <southbridge/intel/i82801gx/nvs.h>

void acpi_create_gnvs(global_nvs_t *gnvs)
{
	gnvs->pwrs = 1; /* Power state (AC = 1) */
	gnvs->cmap = 1; /* COM 1 port */
	gnvs->cmap = 1; /* COM 2 port */
	gnvs->lptp = 0; /* LPT port */
	gnvs->fdcp = 0; /* Floppy Disk Controller */
}
