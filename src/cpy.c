/*
	Copyright 2022-2023 Gabriel Jensen.

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

#include <inttypes.h>
#include <stdio.h>

void
agb_cpy (void)
{
	printf (
		"agbsum #%" PRIX64 " - Copyright 2022-2023 Gabriel Jensen.\n"
		"\n"
		"This program is free software: you can redistribute it and/or modify it under\n"
		"the terms of the GNU General Public License as published by the Free Software\n"
		"Foundation, either version 3 of the License, or (at your option) any later\n"
		"version.\n"
		"\n"
		"This program is distributed in the hope that it will be useful, but WITHOUT ANY\n"
		"WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A\n"
		"PARTICULAR PURPOSE. See the GNU General Public License for more details.\n"
		"\n"
		"You should have received a copy of the GNU General Public License along with\n"
		"this program. If not, see <https://www.gnu.org/licenses/>.\n",
		agb_rel
	);
}
