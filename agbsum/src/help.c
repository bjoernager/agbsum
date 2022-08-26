/*
	Copyright 2022 Gabriel Jensen.

	This program is free software: you can redistribute it and/or modify it under the terms of the GNU General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.

	You should have received a copy of the GNU General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <agbsum.h>

#include <inttypes.h>
#include <stdio.h>

void agbsum_help(void) {
	fputs("agbsum - Calculate GBA ROM header checksums.\n",stderr);
	fprintf(stderr,"Release #%" PRIXLEAST64 ". Copyright 2022 Gabriel Jensen.\n",agbsum_ver);
	fputc('\n',stderr);
	fputs("Usage: agbsum [options] <ROM>\n",stderr);
	fputc('\n',stderr);
	fputs("Options:\n",stderr);
	fputs("    --help -h    Print an help screen\n",stderr);
	fputs("    -p           Patch the ROM\n",stderr);
	fputs("    -s           Don't print results\n",stderr);
	fputc('\n',stderr);
	fputs("Built at " __TIME__ ", " __DATE__ ".\n",stderr);
}
