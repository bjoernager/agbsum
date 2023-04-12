/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdio.h>
#include <string.h>

[[noreturn]] static void agbsum_expectparamval(char const chrparam) {
	fprintf(stderr,"Expected value for character parameter '%c'\n",chrparam);
	agbsum_exit(agbsum_stat_err,nullptr);
}

static bool agbsum_chkchrparam(agbsum_dat * const dat,char const * const param) {
	char const chrparam = param[0x0u];
	if (chrparam == '\x0') {return true;}

	char const * const paramval = &param[0x1];
	
	switch (chrparam) {
	default:
		fprintf(stderr,"Invalid character parameter '%c'\n",chrparam);
		agbsum_exit(agbsum_stat_err,nullptr);
	case 'h':
		agbsum_help();
		agbsum_exit(agbsum_stat_ok,nullptr);
	case 'i':
		{
			if (paramval[0x0u] == '\x0') {agbsum_expectparamval(chrparam);}
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

void agbsum_chkparams(agbsum_dat * const dat,int const _argc,char const * const * const _argv) {
	if (_argc < 0x2) {
		agbsum_help();
		agbsum_exit(agbsum_stat_ok,nullptr);
	}
	else {
		size_t const numparam = _argc;

		for (size_t pos = 0x1u;pos < numparam;++pos) {

			char const * const param = _argv[pos];
			if (param[0x0u] == '-') {
				if (param[0x1u] == '-') {
					char const * const lngparam = &param[0x2u];

					if (lngparam[0x0u] == '\x0') {
						fputs("Missing long parameter after '--' sequence\n",stderr);
						agbsum_exit(agbsum_stat_err,nullptr);
					}

					if (!strcmp(lngparam,"help")) {
						agbsum_help();
						agbsum_exit(agbsum_stat_ok,nullptr);
					}
					
					fprintf(stderr,"Invalid long parameter \"%s\"\n",lngparam);
					agbsum_exit(agbsum_stat_err,nullptr);
				}

				if (param[0x1u] == '\x0') {
					fputs("Missing character parameter after '-'\n",stderr);
					agbsum_exit(agbsum_stat_err,nullptr);
				}

				for (char const * chrpos = &param[0x1u];;++chrpos) {if (agbsum_chkchrparam(dat,chrpos)) {break;}}

				continue;
			}
		}

		if (dat->pth == nullptr) {
			fputs("ROM not set (missing character parameter 'i')\n",stderr);
			agbsum_exit(agbsum_stat_err,nullptr);
		}
	}
}
