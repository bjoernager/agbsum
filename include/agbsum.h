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

#ifndef agb_hdr
#define agb_hdr

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>

#if __STDC_VERSION__ >= 201112
#include <stdnoreturn.h>
#elif defined(__GNUC__)
#define noreturn __attribute__ ((__noreturn__))
#elif defined (_MSC_VER)
#define noreturn __declspec (noreturn)
#else
#define noreturn
#endif

#define agb_rel ((uint64_t)+0xEu)

#define agb_iptsrt ((size_t)+0xA0u) // The part of the header used for calculating the checksum.
#define agb_sumoff ((size_t)+0xBDu - agb_iptsrt)

enum agb_cnd {
	agb_cnd_err,
	agb_cnd_oky,
};

struct agb_dat {
	bool        dopat;
	char const* pth;
	bool        sil;
	FILE*       img;
};

uint8_t
agb_getsum (void const* restrict img);

void
agb_pat (FILE* restrict img, char unsigned sum);

void
agb_cpy (void);

void
agb_hlp (void);

void
agb_chkpar (struct agb_dat* restrict dat, int argc, char const* const* restrict argv);

void
agb_inidat (struct agb_dat* restrict dat);

FILE*
agb_opn (char const* restrict pth);

void
agb_red (void* restrict buf, FILE* restrict img);

noreturn void
agb_exi (enum agb_cnd stat, FILE* img);

#endif
