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

#include <limits.h>
#include <stdint.h>
#include <stdio.h>

#if CHAR_BIT != 0x8
#error "agbsum only support 8-bit byte systems"
#endif

int main (int const argc, char const* const* const argv)
{
	struct agb_Data data;
	agb_initdata (&data);
	agb_checkParams (&data, argc, argv);

	data.image = agb_open (data.path);

	char unsigned buffer[agb_sumOffset + 0x1];

	agb_read (buffer, data.image);

	{
		char unsigned const sum      = agb_getSum (buffer);
		char unsigned const imageSum = buffer[agb_sumOffset];

		if (imageSum == sum || !data.doPatch) {
			// Don't patch the ROM if it's already okay or we're not allowed to.
			if (!data.silent) {printf ("\"%s\": %hhX (%hhX in file)\n", data.path, sum, imageSum);}
			agb_exit (agb_Cnd_Ok, data.image);
		}

		agb_patch (data.image, sum);

		// If we aren't supposed to print anything then
		// don't.
		if (!data.silent) { printf ("\"%s\" @ %zX: %hhX => %hhX\n", data.path, agb_sumDataStart + agb_sumOffset, imageSum, sum); }
	}

	agb_exit (agb_Cnd_Ok, data.image);
}
