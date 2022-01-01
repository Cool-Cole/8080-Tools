#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdint.h>

#include "handleState.h"

void loadROM(cpuState *state, const char *filePath, const uint16_t memOffset);

int main() {

    cpuState state = initState();

    uint8_t m[15] = {0x3E, 0x01, 0x0F};

    memcpy(state.memory, m, 3);
/*
    loadROM(&state, "C:\\Users\\Cole\\Sync\\CLion_Laptop\\8080EMU\\cpudiag.bin", 0x0100);


    // TESTING CODE FROM http://emulator101.com/
    //Fix the first instruction to be JMP 0x100
    state.memory[0] = 0xc3;
    state.memory[1] = 0;
    state.memory[2] = 0x01;

    //Fix the stack pointer from 0x6ad to 0x7ad
    // this 0x06 byte 112 in the code, which is
    // byte 112 + 0x100 = 368 in memory
    state.memory[368] = 0x7;

    //Skip DAA test
    state.memory[0x59c] = 0xc3;//JMP
    state.memory[0x59d] = 0xc2;
    state.memory[0x59e] = 0x05;
*/
    while (1) {
        emulateState(&state);

        // Look into usleep instead
        //sleep(1);
    }

    return EXIT_SUCCESS;
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