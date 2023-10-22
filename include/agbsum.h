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

#ifndef agb_header
#define agb_header

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

#define agb_release ((uint64_t)UINT64_C(+0xF))

#define agb_sumDataStart ((size_t)+0xA0u) // The part of the header used for calculating the checksum.
#define agb_sumOffset    ((size_t)+0xBDu - agb_sumDataStart)

enum agb_Condition {
	agb_Cnd_Error,
	agb_Cnd_Ok,
};

struct agb_Data {
	bool        doPatch;
	char const* path;
	bool        silent;
	FILE*       image;
};

uint8_t
agb_getSum (void const* restrict image);

void
agb_patch (FILE* restrict image, char unsigned sum);

void
agb_copyright (void);

void
agb_help (void);

void
agb_checkParams (struct agb_Data* restrict dat, int argc, char const* const* restrict argv);

void
agb_initdata (struct agb_Data* restrict dat);

FILE*
agb_open (char const* restrict path);

void
agb_read (void* restrict buf, FILE* restrict image);

noreturn void
agb_exit (enum agb_Condition stat, FILE* image);

#endif
