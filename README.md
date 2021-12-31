## Intel 8080 CPU Emulator

This project is an emulator for the intel 8080 that is designed
to be interfaced with. Once full emulation is implemented I 
plan on impementing time travel debugging.

This emulator will be the backend for two projects I plan on creating,
a GDB like debugger and an emulator for Space Invaders.

## TODO

- [ ] Implement all opcodes (excluding special instructions that need to be handled at a higher level)
- [ ] Implement cycle counts & timings
- [ ] Run the emulator aginst testing roms
- [ ] Time Travel Debugging