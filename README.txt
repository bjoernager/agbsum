- AGBSUM

AGB image header checksum patcher.

- ABOUT

Patches the image header checksum of an AGB image.

The checksum is located at the offset 0xBD. See USAGE for more information.

- USAGE

agbsum [options] <image>

Options:
    --help -h    Print the help screen
    -p           Patch the image file
    -s           Don't print results
    --version    Print the version number

- COPYRIGHT & LICENSE

Copyright 2022-2023 Gabriel Jensen.

This program is free software: you can redistribute it and/or modify it under
the terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later
version.

This program is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE. See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License along with
this program. If not, see <https://www.gnu.org/licenses/>.
