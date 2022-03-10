#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include <unistd.h>

#include "handleState.h"

void loadROM(cpuState *state, const char *filePath, const uint16_t memOffset);

int main(void) {

    cpuState state = initState();

    //uint8_t mem[] = {0x31,0x04,0x00,0x01,0xBB,0xAA,0x21,0xDD,0xCC,0xC5,0xE5};

    //memcpy(state.memory, mem, 11);



    // PATH definition is the cwd as found by cmake
    // TODO: Check to make sure this is OS independent, I think it is.
    loadROM(&state, PATH "/testing_roms/cpudiag.bin", 0x0100);

    // TESTING CODE FROM http://www.emulator101.com/full-8080-emulation.html
    //Fix the first instruction to be JMP 0x100
    state.memory[0] = 0xc3;
    state.memory[1] = 0;
    state.memory[2] = 0x01;

    // Fix the stack pointer from 0x6ad to 0x7ad
    // this 0x06 byte 112 in the code, which is
    // byte 112 + 0x100 = 368 in memory
    state.memory[368] = 0x7;

    //Skip DAA test
    state.memory[0x59c] = 0xc3;//JMP
    state.memory[0x59d] = 0xc2;
    state.memory[0x59e] = 0x05;

    //dumpState(&state, "TestFileRom");

    while (1) {
        emulateState(&state);
    }

    //return EXIT_SUCCESS;
}


void loadROM(cpuState *state, const char *filePath, const uint16_t memOffset) {

    FILE *rfp;

    rfp = fopen(filePath, "rb");

    if (NULL == rfp) {
        printf("Could not open %s\nQuitting...\n", filePath);
        exit(EXIT_FAILURE);
    }

    fseek(rfp, 0, SEEK_END);
    size_t fileSize = ftell(rfp);
    fseek(rfp, 0, SEEK_SET);

    if (UINT16_MAX < fileSize + memOffset) {
        printf("The ROM cannot fit in program memory.\n Quitting...");
        exit(EXIT_FAILURE);
    }

    fread(state->memory + memOffset, 1, fileSize, rfp);
}