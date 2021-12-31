cmake_minimum_required(VERSION 3.20)
project(8080EMU C VERSION 0.1.0 LANGUAGES C)

set(CMAKE_C_STANDARD 11)

add_executable(8080EMU ./src/main.c ./src/handleState.c ./src/handleState.h ./src/opcodes.c ./src/opcodes.h)