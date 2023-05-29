/*
	Copyright 2022-2023 Gabriel Jensen.

	This file is part of agbsum.
	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdint.h>

uint8_t
agb_getsum (void const* const restrict romptr)
{
	uint8_t const* restrict rom = romptr;
	uint8_t                 sum = 0x0u;

	for (char unsigned const* restrict pos = rom; pos != rom + agb_sumoff; ++pos) {sum += *pos;}

	sum = 0x0u - (0x19u + sum);

	return sum;
}
