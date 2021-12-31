#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <stdint.h>

#include "handleState.h"

int main() {

    // JP Test
    uint8_t m[15] = {0x3C, 0x3C, 0x3C, 0xF2, 0x0B, 0x00, 0x04, 0x04, 0xC3, 0x0D, 0x00, 0x0C, 0x0C, 0x14, 0x14};

    // PUSH and POP PSW test
    //uint8_t m[15] = {0x3C,0x3C, 0x3C,0x3C,0x3C,0xF5,0x3C,0x3C, 0x3c, 0xF1};

    cpuState state = initState();

    memset(state.memory, 0x00, UINT16_MAX);

    memcpy(state.memory, m, 15);

    /*
    FILE *rfp;

#ifdef __WIN32
    char filename[] = "C:\\Users\\Cole\\Sync\\CLion_Laptop\\disassemble8080\\invadersROM\\invaders.h";
#elif __linux__
    char filename[] = "/home/cole/Sync/CLion_Laptop/disassemble8080/invadersROM/invaders.h";
#endif

    rfp = fopen(filename,"rb");

    if(NULL == rfp){
        printf("Could not open %s\nQuitting...\n", filename);
        return EXIT_FAILURE;
    }

    fseek(rfp, 0, SEEK_END);
    size_t fileSize = ftell(rfp);
    fseek(rfp, 0, SEEK_SET);

    if(UINT16_MAX < fileSize){
        printf("The ROM cannot fit in program memory.\n Quitting...");
        return EXIT_FAILURE;
    }

    state.memory = malloc(UINT16_MAX);

    fread(state.memory, 1, fileSize, rfp);

    */


    while (1) {
        emulateState(&state);

        // Look into usleep instead
        //sleep(1);
    }

    return EXIT_SUCCESS;
}
