cmake_minimum_required(VERSION 3.8)

set(CMAKE_C_STANDARD 99)

add_executable(
	agbsum

	"src/chkpar.c"
	"src/exi.c"
	"src/getsum.c"
	"src/hlp.c"
	"src/inidat.c"
	"src/main.c"
	"src/opn.c"
	"src/pat.c"
	"src/red.c"
)

target_include_directories(
	agbsum PRIVATE

	"include"
)

target_compile_definitions(
	agbsum PRIVATE

	_FORTIFY_SOURCE=$<IF:$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">,0,2>
)

if("${CMAKE_C_COMPILER_ID}" MATCHES "Clang|GNU")
	target_compile_options(
		agbsum PRIVATE

		$<IF:$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">,-Og,-Ofast>
		-Wall
		-Wextra
		-Wpedantic
		-fdiagnostics-color=always
		-g
	)
endif()
