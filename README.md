# About

This repository contains the necessary supporting code for my 8080 time travel debugger. In this repository 
is a disassembler for the intel 8080 and an emulator for the architecture.

This repository exists because I originally developed both the disassembler and the emulator separately. I would 
like to keep standalone copies of each in this repository for future reference.

Any feedback is welcome and constructive criticism is encouraged!


# Intel 8080 CPU Emulator

This project is an emulator for the intel 8080 that is designed to be interfaced with. Once full emulation is
implemented I plan on implementing time travel debugging.

This emulator will be the backend for a GDB like debugger for the intel 8080.

## Compiling

Compiling normally

1. `cmake CMakeLists.txt`
2. `make`

Compiling with Address Sanitizer (Linux only!)

1. Set the `BUILD_ASAN` and `BUILD_DEBUG` options flags in `CMakeLists.txt` to `ON`
2. `cmake CMakeLists.txt`
3. `make`

(Note: I am not very familiar with CMake so if you try to switch between compiling a normal build and an ASAN 
build you may need to delete the `CMakeCache.txt` file)

## Running

This emulator is not meant to be used independently but running the emulator will test it against the testing rom.

`./8080emu`

## TODO

- [x] Implement all opcodes (excluding special instructions that need to be handled at a higher level)
- [x] Run the emulator against a testing rom

# Intel 8080 Disassembler

The intel 8080 disassembler, like the emulator, is written in C.

Build scripts for the disassembler are currently not included in this repository at this time.

## Sources

http://www.emulator101.com/
