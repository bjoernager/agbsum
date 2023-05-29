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
# include <stdnoreturn.h>
#elif defined(__GNUC__)
# define noreturn __attribute__ ((__noreturn__))
#elif defined (_MSC_VER)
# define noreturn __declspec (noreturn)
#else
# define noreturn
#endif

#define agb_rel ((uint64_t)+0xBu)

#define agb_romsrt    ((size_t)+0xA0u)
#define agb_chksumoff ((size_t)+0xBDu-agb_romsrt)

typedef enum {
	agb_cnd_err,
	agb_cnd_oky,
} agb_cnd;

typedef struct {
	bool        dopat;
	char const* pth;
	bool        sil;
	FILE *      rom;
} agb_dat;

uint8_t
agb_getsum (void const* restrict rom);

void
agb_pat (FILE * restrict rom, unsigned char chksum);

void
agb_hlp (void);

void
agb_chkpar (agb_dat * restrict dat, int argc, char const* const* restrict argv);

void
agb_inidat (agb_dat * restrict dat);

FILE *
agb_opn (char const* restrict pth);

void
agb_red (void * restrict buf, FILE * restrict rom);

noreturn void agb_exi (agb_cnd stat, FILE * rom);

#endif
