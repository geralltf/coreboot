/*
 * This file is part of the coreboot project.
 *
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

/*
 * Onboard CPLD
 */
Scope (\_SB.PCI0.LPCB)
{
	Device (CPLD)		/* Onboard CPLD */
	{
		Name(_HID, EISAID("PNP0C01"))
		Name(_CRS, ResourceTemplate()
		{
			/* Reserve 0x280 to 0x2BF for the CPLD */
			FixedIO (0x0280, 0x40)
			IRQNoFlags () {7}
		})
	}
}
