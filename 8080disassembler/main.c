#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Disassemble8080.h"

void disas(char *filename){
    char *codeBuffer;
    FILE *rfp;

    rfp = fopen(filename,"rb");

    if(rfp == NULL){
        printf("Could not open %s\nQuitting...\n", filename);
        exit(1);
    }

    fseek(rfp, 0, SEEK_END);
    size_t fileSize = ftell(rfp);
    fseek(rfp, 0, SEEK_SET);

    codeBuffer = (char *)malloc(fileSize * sizeof(char));

    fread(codeBuffer, 1, fileSize, rfp);

    int currentInstruction = 0;
    int opbytes;

    while(currentInstruction < fileSize){
        opbytes = Disassemble(codeBuffer, currentInstruction);

        currentInstruction += opbytes;
    }
}

void print_help(){
    printf("An Intel 8080 disassembler written by Cole.\n"
           "Please provide a single filename as an argument.\n");
}

int main(int argc, char *argv[]) {

    char path[PATH_MAX + 1];

    getcwd(path, PATH_MAX + 1);

    if(2 != argc){
        print_help();
        exit(EXIT_SUCCESS);
    }

    // A forward slash or backslash needs to be appended to the end of the cwd string
    // This is OS dependent
#ifdef _WIN32
    strcat(path, "\\");
#elif __linux__
    strcat(path, "/");
#endif

    strncat_s(path, PATH_MAX + 1, argv[1], PATH_MAX);

    disas(path);

    return EXIT_SUCCESS;
}
