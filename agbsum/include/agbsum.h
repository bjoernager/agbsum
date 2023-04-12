/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef agbsum_hdr
#define agbsum_hdr

#include <stdint.h>
#include <stdio.h>

// Temporary C23 support:
#define constexpr static const // This can make arrays variadic-length.
#ifndef __clang__
#define bool _Bool
#define false ((bool)+0x0u)
#define nullptr (NULL)
#define static_assert _Static_assert
#define true ((bool)+0x1u)
#define typeof __typeof__
#endif

constexpr uint_least64_t agbsum_ver = 0x7u;

constexpr size_t agbsum_romstart  = 0xA0u;
constexpr size_t agbsum_chksumoff = 0xBDu-agbsum_romstart;

typedef enum {
	agbsum_stat_err,
	agbsum_stat_ok,
} agbsum_stat;

typedef struct {
	bool         dopat;
	char const * pth;
	bool         sil;
	FILE *       rom;
} agbsum_dat;

uint8_t agbsum_calc(void const * rom);

void agbsum_help(void);

void agbsum_chkparams(agbsum_dat * dat,int argc,char const * const * argv);

void agbsum_initdat(agbsum_dat * dat);

FILE * agbsum_open(char const * pth);
void   agbsum_pat( FILE *   rom,    unsigned char chksum);
void   agbsum_rd(  void  *  buf,    FILE *        rom);

[[noreturn]] void agbsum_exit(agbsum_stat stat,FILE * rom);

#endif
