cmake_minimum_required(VERSION 3.16)
project(8080EMU C)

set(CMAKE_C_STANDARD 11)

option(BUILD_ASAN "Build with -fsanitize=address" ON)
option(BUILD_DEBUG "Build with debug symbols" ON)
option(BUILD_FAST "Build with -O3" ON)

if(BUILD_ASAN)
    add_compile_options(-fsanitize=address)
    add_link_options(-fsanitize=address)
endif(BUILD_ASAN)

if(BUILD_DEBUG)
    add_compile_options(-g)
endif(BUILD_DEBUG)

if(BUILD_FAST)
    add_compile_options(-O3)
endif(BUILD_FAST)

add_compile_definitions(PATH="${CMAKE_CURRENT_LIST_DIR}")

add_executable(8080EMU ./src/main.c ./src/handleState.c ./src/handleState.h ./src/opcodes.c ./src/opcodes.h src/handleSnapshots.c src/handleSnapshots.h)