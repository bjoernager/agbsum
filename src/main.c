/*
	Copyright 2022-2023 Gabriel Jensen.

	This file is part of agbsum.
	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#if CHAR_BIT != 0x8
#error "agbsum only support 8-bit byte systems"
#endif

int main (int const argc, char const* const* const argv)
{
	agb_dat dat;
	agb_inidat (&dat);
	agb_chkpar (&dat, argc, argv);

	dat.rom = agb_opn (dat.pth);

	char unsigned buf[agb_sumoff + 0x1u];

	agb_red (buf, dat.rom);

	{
		char unsigned const sum    = agb_getsum (buf);
		char unsigned const romsum = buf[agb_sumoff];

		if (romsum == sum || !dat.dopat) {
			if (!dat.sil) {printf ("\"%s\": %hhX (%hhX in file)\n", dat.pth, sum, romsum);}
			agb_exi (agb_cnd_oky, dat.rom);
		}

		agb_pat (dat.rom, sum);

		if (!dat.sil) {printf ("\"%s\" @ %zX: %hhX => %hhX\n", dat.pth, agb_romsrt + agb_sumoff, romsum, sum);}
	}

	agb_exi (agb_cnd_oky, dat.rom);
}
