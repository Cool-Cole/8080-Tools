cmake_minimum_required(VERSION 3.16)
project(8080EMU C)

set(CMAKE_C_STANDARD 11)

add_compile_definitions(PATH="${CMAKE_CURRENT_LIST_DIR}")

add_executable(8080EMU ./src/main.c ./src/handleState.c ./src/handleState.h ./src/opcodes.c ./src/opcodes.h src/handleSnapshots.c src/handleSnapshots.h)

add_compile_options(-fsanitize=address -O3)
add_link_options(-fsanitize=address)