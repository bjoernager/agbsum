/*
	Copyright 2022-2023 Gabriel Jensen.

	This file is part of agbsum.
	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.
	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef agb_hdr
#define agb_hdr

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#if __STDC_VERSION__ > 199901
#include <stdnoreturn.h>
#else
#ifdef __GNUC__
#define _Noreturn __attribute__ ((noreturn))
#elif defined(_MSC_VER)
#define _Noreturn __declspec (noreturn)
#else
#define _Noreturn
#endif
#define noreturn _Noreturn
#endif

#define agb_rel ((uint_least64_t)+0x9u)

#define agb_romsrt    ((size_t)+0xA0u)
#define agb_chksumoff ((size_t)+0xBDu-agb_romsrt)

typedef enum {
	agb_cnd_err,
	agb_cnd_ok,
} agb_cnd;

typedef struct {
	bool         dopat;
	char const * pth;
	bool         sil;
	FILE *       rom;
} agb_dat;

uint8_t agb_getsum(void const * rom);

void agb_pat(FILE * rom,unsigned char chksum);

void agb_hlp(void);

void agb_chkpar(agb_dat * dat,int argc,char const * const * argv);

void agb_inidat(agb_dat * dat);

FILE * agb_opn(char const * pth);
void   agb_red(void *       buf,FILE * rom);

noreturn void agb_exi(agb_cnd stat,FILE * rom);

#endif
