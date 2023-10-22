/*
	Copyright 2022-2023 Gabriel Bjørnager Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it
	and/or modify it under the terms of the GNU
	Affero General Public License as published by
	the Free Software Foundation, either version 3
	of the License, or (at your option) any later
	version.

	agbsum is distributed in the hope that it will
	be useful, but WITHOUT ANY WARRANTY; without
	even the implied warranty of MERCHANTABILITY
	or FITNESS FOR A PARTICULAR PURPOSE. See the
	GNU Affero General Public License for more
	details.

	You should have received a copy of the GNU
	Affero General Public License along with agbsum.
	If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdio.h>

void
agb_read (void* const restrict buffer, FILE* restrict image)
{
	// We only need to read the part of the image
	// that is used for the checksum.
	fseek (image, agb_sumDataStart, SEEK_SET);

	size_t const count = agb_sumOffset + 0x1u;

	if (fread (buffer, 0x1u, count, image) != count) {
		fputs ("Unable to read ROM\n", stderr);
		agb_exit (agb_Cnd_Error, image);
	}
}
