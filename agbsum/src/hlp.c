/*
	Copyright 2022-2023 Gabriel Jensen.

	This file is part of agbsum.
	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <inttypes.h>
#include <stdio.h>

void agb_hlp(void) {
	fprintf(stderr,
		"agbsum - Calculate GBA ROM header checksums.\n"
		"Release #%" PRIXLEAST64 ". Copyright 2022-2023 Gabriel Jensen.\n"
		"\n"
		"Usage: agbsum [options] <ROM>\n"
		"Options:\n"
		"    --help -h    Print the help screen\n"
		"    -p           Patch the ROM\n"
		"    -s           Don't print the results\n"
		"\n"
		"Built at " __TIME__ ", " __DATE__ ".\n",
		agb_rel
	);
}
