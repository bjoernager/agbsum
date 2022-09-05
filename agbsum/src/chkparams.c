/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#include <agbsum.h>

#include <stdio.h>
#include <sus/extra.h>
#include <sus/os.h>
#include <zap/mem.h>

#if defined(sus_os_win)
#else
#include <sys/stat.h>
#endif

[[noreturn]] static void agbsum_expectparamval(char const _chrparam) {
	fprintf(stderr,"Expected value for character parameter '%c'\n",_chrparam);
	agbsum_exit(agbsum_stat_err);
}

static bool agbsum_chkchrparam(char const * const _param) {
	char const chrparam = _param[0x0u];
	if (chrparam == '\x0') {return true;}
	char const * const paramval = &_param[0x1];
	switch (chrparam) {
	default:
		fprintf(stderr,"Invalid character parameter '%c'\n",chrparam);
		agbsum_exit(agbsum_stat_err);
	case 'h':
		agbsum_help();
		agbsum_exit(agbsum_stat_ok);
	case 'i':
		{
			sus_unlikely (paramval[0x0u] == '\x0') {agbsum_expectparamval(chrparam);}
			sus_unlikely (agbsum_dat.pth != nullptr) {
				fprintf(stderr,"ROM already set (to \"%s\", now \"%s\")\n",agbsum_dat.pth,paramval);
				agbsum_exit(agbsum_stat_err);
			}
#if defined(sus_os_win)
#else
			struct stat statstruct;
			int const   statcd     = stat(paramval,&statstruct);
			bool const  exist      = statcd == 0x0;
			bool const  isdir      = S_ISDIR(statstruct.st_mode);
#endif
			if (!exist) {
				fprintf(stderr,"No such file \"%s\"\n",paramval);
				agbsum_exit(agbsum_stat_err);
			}
			if (isdir) {
				fprintf(stderr,"File \"%s\" is a directory\n",paramval);
				agbsum_exit(agbsum_stat_err);
			}
			agbsum_dat.pth = paramval;
		}
		return true;
	case 'p':
		agbsum_dat.dopat = true;
		return false;
	case 's':
		agbsum_dat.sil = true;
		return false;
	}
}

void agbsum_chkparams(int const _argc,char const * const * const _argv) {
	if (_argc < 0x2) {
		agbsum_help();
		agbsum_exit(agbsum_stat_ok);
	}
	else {
		size_t const numparam = _argc;
		for (size_t pos = 0x1;pos < numparam;++pos) {
			char const * const param = _argv[pos];
			if (param[0x0u] == '-') {
				if (param[0x1u] == '-') {
					char const * const lngparam = &param[0x2u];
					if (lngparam[0x0u] == '\x0') {
						fputs("Missing long parameter after '--' sequence\n",stderr);
						agbsum_exit(agbsum_stat_err);
					}
					if (zap_streq(lngparam,"help")) {
						agbsum_help();
						agbsum_exit(agbsum_stat_ok);
					}
					fprintf(stderr,"Invalid long parameter \"%s\"\n",lngparam);
					agbsum_exit(agbsum_stat_err);
				}
				sus_unlikely (param[0x1u] == '\x0') {
					fputs("Missing character parameter after '-'\n",stderr);
					agbsum_exit(agbsum_stat_err);
				}
				for (char const * chrpos = &param[0x1u];;++chrpos) {if (agbsum_chkchrparam(chrpos)) {break;}}
				continue;
			}
		}
		if (agbsum_dat.pth == nullptr) {
			fputs("ROM not set (missing character parameter 'i')\n",stderr);
			agbsum_exit(agbsum_stat_err);
		}
	}
}
