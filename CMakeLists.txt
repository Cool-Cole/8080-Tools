cmake_minimum_required(VERSION 3.20)
project(8080EMU C)

set(CMAKE_C_STANDARD 11)

add_compile_definitions(PATH="${CMAKE_CURRENT_LIST_DIR}")

add_executable(8080EMU ./src/main.c ./src/handleState.c ./src/handleState.h ./src/opcodes.c ./src/opcodes.h)