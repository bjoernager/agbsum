/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

static_assert(CHAR_WIDTH == 0x8u,"agbsum only support 8-bit byte systems");

int main(int const argc,char const * const * const argv) {
	agbsum_dat dat;

	agbsum_initdat(&dat);

	agbsum_chkparams(&dat,argc,argv);

	dat.rom = agbsum_open(dat.pth);

	unsigned char buf[agbsum_chksumoff+0x1u];

	agbsum_rd(buf,dat.rom);

	unsigned char const chksum    = agbsum_calc(buf);
	unsigned char const romchksum = buf[agbsum_chksumoff];

	if (romchksum == chksum || !dat.dopat) {
		if (!dat.sil) {printf("\"%s\": %hhX (%hhX in file)\n",dat.pth,chksum,romchksum);}
		agbsum_exit(agbsum_stat_ok,dat.rom);
	}

	agbsum_pat(dat.rom,chksum);

	if (!dat.sil) {printf("\"%s\" @ %zX: %hhX => %hhX\n",dat.pth,agbsum_romstart+agbsum_chksumoff,romchksum,chksum);}

	agbsum_exit(agbsum_stat_ok,dat.rom);
}
