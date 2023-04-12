/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdio.h>

void agbsum_pat(FILE * const rom,unsigned char chksum) {
	fseek(rom,(long)(agbsum_romstart+agbsum_chksumoff),SEEK_SET);

	if (fwrite(&chksum,0x1u,0x1u,rom) != 0x1u) {
		fputs("Unable to patch ROM\n",stderr);
		agbsum_exit(agbsum_stat_err,rom);
	}
}
