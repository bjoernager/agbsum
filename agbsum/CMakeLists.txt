cmake_minimum_required(
	VERSION
	3.21
)

set(
	CMAKE_C_STANDARD
	23
)

set(
	CMAKE_C_STANDARD_REQUIRED
)

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
	agbsum
	PRIVATE
	"include"
)

target_link_libraries(
	agbsum
	PRIVATE
	zap
)

if(
	"${CMAKE_C_COMPILER_ID}"
	MATCHES
	"Clang|GNU"
)
	target_compile_options(
		agbsum
		PRIVATE
		-Ofast
		-Wall
		-Wextra
		-fPIC
		-fdiagnostics-color=always
		-gdwarf-2 # Clang 16 uses a different format.
		-march=native
		-pedantic-errors
	)
endif()
