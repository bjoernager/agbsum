/*
	Copyright 2022 Gabriel Jensen.

	This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <agbsum.h>

#include <stdio.h>

void agbsum_rd(void * const _buf) {
	fseek(agbsum_dat.rom,agbsum_romstart,SEEK_SET); /* We only need to read the part of the ROM that is used for the checksum. */
	size_t const num = agbsum_chksumoff + 0x1u;
	if (fread(_buf,0x1u,num,agbsum_dat.rom) != num) {
		fprintf(stderr,"Unable to read ROM \"%s\"\n",agbsum_dat.pth);
		agbsum_exit(agbsum_stat_err);
	}
}
