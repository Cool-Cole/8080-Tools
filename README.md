## Intel 8080 CPU Emulator

This project is an emulator for the intel 8080 that is designed to be interfaced with. Once full emulation is
implemented I plan on implementing time travel debugging.

This emulator will be the backend for two projects I plan on creating, a GDB like debugger and an emulator for Space
Invaders.

Any feedback is welcome and constructive criticism is encouraged!

## Compiling

Compiling normally

1. `cmake CMakeLists.txt`
2. `make`

Compiling with Address Sanitizer (probably won't work on Windows)

1. Set the `BUILD_ASAN` and `BUILD_DEBUG` options flags in `CMakeLists.txt` to `ON`
2. `cmake CMakeLists.txt`
3. `make`

(Note: I don't know how to use CMake properly so if you try to switch between compiling a normal build and an ASAN 
build you need to delete the `CMakeCache.txt` file)

## Running

No way to config input rom yet! Sorry!

`./8080emu`

## TODO

- [x] Implement all opcodes (excluding special instructions that need to be handled at a higher level)
- [x] Run the emulator against a testing rom
- [ ] Run the emulator aginst multiple testing roms
- [ ] Time Travel Debugging

## Sources

http://www.emulator101.com/
