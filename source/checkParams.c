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

#include <inttypes.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

noreturn static void
agb_expectedParamValue (char const charParam)
{
	fprintf (stderr, "Expected value for character parameter '%c'\n", charParam);
	agb_exit (agb_Cnd_Error, NULL);
}

static bool
agb_checkCharParam (struct agb_Data* const restrict data, char const* const restrict param)
{
	// Returns true if the rest of the parameter is
	// used as a value.

	char const charParam = param[0x0];
	if (charParam == '\x0') {return true;}

	char const* const restrict paramval = &param[0x1];

	switch (charParam) {
	default:
		fprintf (stderr, "Invalid character parameter '%c'\n", charParam);
		agb_exit (agb_Cnd_Error, NULL);

	case 'h':
		agb_help ();
		agb_exit (agb_Cnd_Ok, NULL);

	case 'i':
		{
			if (paramval[0x0] == '\x0') {agb_expectedParamValue (charParam);}
			data->path = paramval;
		}
		return true;

	case 'p':
		data->doPatch = true;
		return false;

	case 's':
		data->silent = true;
		return false;
	}
}

void
agb_checkParams (struct agb_Data* const restrict data, int const argc, char const* const* const argv) {
	if (argc < 0x2) {
		agb_help ();
		agb_exit (agb_Cnd_Ok, NULL);
	}

	size_t const numParams = argc; // Prettier.

	for (ptrdiff_t index = 0x1; index < (ptrdiff_t)numParams; ++index) {
		// Iterate over the parameters. One hyphen denotes character parameters (-h) whilst two denote long paramters (--help).

		char const* const param = argv[index];
		if (param[0x0] == '-') {
			if (param[0x1] == '-') {
				char const* const longParam = &param[0x2];

				// Check long parameters.

				if (longParam[0x0] == '\x0') {
					fputs ("Missing long parameter after '--' sequence\n", stderr);
					agb_exit (agb_Cnd_Error, NULL);
				}

				if (!strcmp (longParam, "help")) {
					agb_help ();
					agb_exit (agb_Cnd_Ok, NULL);
				}

				if (!strcmp (longParam, "version")) {
					agb_copyright();
					agb_exit (agb_Cnd_Ok, NULL);
				}

				fprintf (stderr, "Invalid long parameter \"%s\"\n", longParam);
				agb_exit (agb_Cnd_Error, NULL);
			}

			if (param[0x1] == '\x0') {
				fputs ("Missing character parameter after '-'\n", stderr);
				agb_exit (agb_Cnd_Error, NULL);
			}

			// Check character parameters.

			for (char const* charIndex = &param[0x1];; ++charIndex) { if (agb_checkCharParam (data, charIndex)) { break; } }

			continue;
		}

		// We did not find the 'i' parameter, so we don't know where the ROM is.

		if (data->path == NULL) {
			fputs ("ROM not set (missing character parameter 'i')\n", stderr);
			agb_exit (agb_Cnd_Error, NULL);
		}
	}
}
