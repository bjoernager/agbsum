/*
	Copyright 2022-2023 Gabriel Jensen.

	This file is part of agbsum.
	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stddef.h>
#include <stdio.h>
#include <string.h>

noreturn static void 
agb_expparval (char const chrpar)
{
	fprintf (stderr,"Expected value for character parameter '%c'\n", chrpar);
	agb_exi (agb_cnd_err, NULL);
}

static bool
agb_chkchrpar (agb_dat * const restrict dat, char const* const restrict par)
{
	char const chrpar = par[0x0u];
	if (chrpar == '\x0') {return true;}

	char const* const restrict paramval = &par[0x1];

	switch (chrpar) {
	default:
		fprintf (stderr,"Invalid character parameter '%c'\n", chrpar);
		agb_exi (agb_cnd_err, NULL);
	case 'h':
		agb_hlp ();
		agb_exi (agb_cnd_oky, NULL);
	case 'i':
		{
			if (paramval[0x0u] == '\x0') {agb_expparval (chrpar);}
			dat->pth = paramval;
		}
		return true;
	case 'p':
		dat->dopat = true;
		return false;
	case 's':
		dat->sil = true;
		return false;
	}
}

void
agb_chkpar (agb_dat * const restrict dat, int const argc, char const* const* const argv) {
	if (argc < 0x2) {
		agb_hlp ();
		agb_exi (agb_cnd_oky, NULL);
	} else {
		size_t const numpar = argc;

		for (size_t pos = 0x1u;pos < numpar;++pos) {

			char const* const par = argv[pos];
			if (par[0x0u] == '-') {
				if (par[0x1u] == '-') {
					char const* const lngparam = &par[0x2u];

					if (lngparam[0x0u] == '\x0') {
						fputs ("Missing long parameter after '--' sequence\n", stderr);
						agb_exi (agb_cnd_err, NULL);
					}

					if (!strcmp (lngparam,"help")) {
						agb_hlp ();
						agb_exi (agb_cnd_oky, NULL);
					}
					
					fprintf (stderr,"Invalid long parameter \"%s\"\n", lngparam);
					agb_exi (agb_cnd_err, NULL);
				}

				if (par[0x1u] == '\x0') {
					fputs ("Missing character parameter after '-'\n", stderr);
					agb_exi (agb_cnd_err, NULL);
				}

				for (char const* chrpos = &par[0x1u];;++chrpos) {if (agb_chkchrpar (dat, chrpos)) {break;}}

				continue;
			}
		}

		if (dat->pth == NULL) {
			fputs ("ROM not set (missing character parameter 'i')\n", stderr);
			agb_exi (agb_cnd_err, NULL);
		}
	}
}
