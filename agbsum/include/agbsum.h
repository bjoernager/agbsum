/*
	Copyright 2022 Gabriel Jensen.

	This file is part of agbsum.

	agbsum is free software: you can redistribute it and/or modify it under the terms of the GNU Affero General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.

	agbsum is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for more details.

	You should have received a copy of the GNU Affero General Public License along with agbsum. If not, see <https://www.gnu.org/licenses/>.
*/

#if !defined(agbsum_hdr)
#define agbsum_hdr

#include <stdint.h>
#include <stdio.h>

/* Temporary C2x support: */
#define constexpr static const /* This can make arrays variadic-length. */
#define nullptr NULL
#define typeof __typeof__

constexpr uint_least64_t agbsum_ver = 0x2u;

constexpr size_t agbsum_romstart = 0xA0u;

constexpr size_t agbsum_chksumoff = 0xBDu - agbsum_romstart;

typedef enum {
	agbsum_stat_err,
	agbsum_stat_ok,
} agbsum_stat;

extern struct {
	bool         dopat;
	char const * pth;
	bool         sil;
	FILE *       rom;
} agbsum_dat;

             unsigned char agbsum_calc(     void const *  rom);
             void          agbsum_chkparams(int           argc,  char const * const * argv);
[[noreturn]] void          agbsum_exit(     agbsum_stat   stat);
             void          agbsum_help(     void);
             void          agbsum_initdat(  void);
             void          agbsum_open(     void);
             void          agbsum_pat(      unsigned char chksum);
             void          agbsum_rd(       void  *       buf);

#endif
