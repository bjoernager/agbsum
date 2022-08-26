/*
	Copyright 2022 Gabriel Jensen.

	This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <agbsum.h>

#include <stdio.h>

void agbsum_pat(unsigned char _chksum) {
	fseek(agbsum_dat.rom,(long)(agbsum_romstart + agbsum_chksumoff),SEEK_SET);
	if (fwrite(&_chksum,0x1u,0x1u,agbsum_dat.rom) != 0x1u) {
		fprintf(stderr,"Unable to patch ROM \"%s\"\n",agbsum_dat.pth);
		agbsum_exit(agbsum_stat_err);
	}
}
