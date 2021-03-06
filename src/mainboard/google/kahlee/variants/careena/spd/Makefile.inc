##
## This file is part of the coreboot project.
##
##
## This program is free software; you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation; version 2 of the License.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##

LIB_SPD_DEPS = $(foreach f, $(SPD_SOURCES), src/mainboard/$(MAINBOARDDIR)/spd/$(f).spd.hex)

SPD_SOURCES =  hynix-H5AN8G6NAFR-UH		# 0b0000
SPD_SOURCES += hynix-H5ANAG6NAMR-UH		# 0b0001
SPD_SOURCES += micron-MT40A512M16JY-083E-B	# 0b0010
SPD_SOURCES += micron-MT40A1G16KNR-075-E	# 0b0011
SPD_SOURCES += samsung-K4A8G165WB-BCRC		# 0b0100
SPD_SOURCES += samsung-K4AAG165WB-MCRC		# 0b0101
SPD_SOURCES += micron-MT40A512M16LY-075-E	# 0b0110
SPD_SOURCES += hynix-H5ANAG6NCMR-VKC		# 0b0111
SPD_SOURCES += hynix-H5AN8G6NCJR-VKC		# 0b1000
SPD_SOURCES += samsung-K4A8G165WC-BCTD		# 0b1001
SPD_SOURCES += samsung-K4AAG165WB-MCTD		# 0b1010
SPD_SOURCES += micron-MT40A512M16TB-062E-J	# 0b1011
SPD_SOURCES += samsung-K4AAG165WA-BCTD		# 0b1100
SPD_SOURCES += hynix-H5ANAG6NCMR-XNC		# 0b1101
SPD_SOURCES += micron-MT40A1G16RC-062E-B	# 0b1110
SPD_SOURCES += samsung-K4AAG165WA-BCWE		# 0b1111
