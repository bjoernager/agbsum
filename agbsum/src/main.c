/*
	Copyright 2022 Gabriel Jensen.

	This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

    This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <agbsum.h>

#include <limits.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>

_Static_assert(CHAR_WIDTH == 0x8u);

typeof (agbsum_dat) agbsum_dat;

int main(int const argc,char const * const * const argv) {
	agbsum_initdat();
	agbsum_chkparams(argc,argv);
	agbsum_open();
	unsigned char buf[agbsum_chksumoff + 0x1u];
	agbsum_rd(buf);
	unsigned char const chksum    = agbsum_calc(buf);
	unsigned char const romchksum = buf[agbsum_chksumoff];
	if (romchksum == chksum || !agbsum_dat.dopat) {
		if (!agbsum_dat.sil) {printf("\"%s\": %hhX (%hhX in file)\n",agbsum_dat.pth,chksum,romchksum);}
		agbsum_exit(agbsum_stat_ok);
	}
	agbsum_pat(chksum);
	if (!agbsum_dat.sil) {printf("\"%s\" @ %zX: %hhX => %hhX\n",agbsum_dat.pth,agbsum_romstart + agbsum_chksumoff,romchksum,chksum);}
	agbsum_exit(agbsum_stat_ok);
}
