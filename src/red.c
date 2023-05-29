/*
	Copyright 2022-2023 Gabriel Jensen.

	This file is part of agbsum.
	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdio.h>

void
agb_red (void * const restrict buf, FILE * restrict rom)
{
	fseek (rom, agb_romsrt, SEEK_SET); // We only need to read the part of the ROM that is used for the checksum.
	size_t const num = agb_sumoff + 0x1u;
	
	if (fread (buf,0x1u, num, rom) != num) {
		fputs ("Unable to read ROM\n", stderr);
		agb_exi (agb_cnd_err, rom);
	}
}
