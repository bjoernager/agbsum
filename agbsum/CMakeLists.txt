cmake_minimum_required(VERSION 3.21)

set(CMAKE_C_STANDARD 23)

add_executable(
	agbsum

	"src/calc.c"
	"src/chkparams.c"
	"src/exit.c"
	"src/help.c"
	"src/initdat.c"
	"src/main.c"
	"src/open.c"
	"src/pat.c"
	"src/rd.c"
)

target_include_directories(
	agbsum PRIVATE

	"include"
)

target_compile_definitions(
	agbsum PRIVATE

	_FORTIFY_SOURCE=$<IF:$<STREQUAL:"${CMAKE_BUILD_TYPE}","Debug">,0x0,0x2>
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
