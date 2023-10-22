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

#include <stdint.h>

uint8_t
agb_getSum (void const* const restrict imagePtr)
{
	uint8_t const* restrict image = imagePtr;
	uint8_t                 sum   = UINT8_C(0x0);

	for (char unsigned const* restrict position = image; position != image + agb_sumOffset; ++position) { sum += *position; }

	sum = -(UINT8_C(0x19) + sum);

	return sum;
}
