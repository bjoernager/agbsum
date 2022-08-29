/*
	Copyright 2022 Gabriel Jensen.

	This program is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with this program. If not, see <https://www.gnu.org/licenses/>. 
*/

#include <agbsum.h>

#include <stdio.h>
#include <stdlib.h>

void agbsum_exit(agbsum_stat const _stat) {
	if (agbsum_dat.rom != nullptr) {fclose(agbsum_dat.rom);}
	exit(_stat == agbsum_stat_ok ? EXIT_SUCCESS : EXIT_FAILURE);
}
