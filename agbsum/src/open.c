/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdio.h>

FILE * agbsum_open(char const * const pth) {
	FILE * rom = fopen(pth,"r+");
	
	if (rom == nullptr) {
		fputs("Unable to open ROM\n",stderr);
		agbsum_exit(agbsum_stat_err,nullptr);
	}

	return rom;
}
