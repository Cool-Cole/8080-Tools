#ifndef INC_8080EMU_HANDLESTATE_H
#define INC_8080EMU_HANDLESTATE_H

#include <stdint.h>

typedef struct cpuFlags {
    uint8_t sign;
    uint8_t zero;
    uint8_t auxCarry;
    uint8_t parity;
    uint8_t carry;
} cpuFlags;

typedef struct cpuState {
    // WARNING: Little Endian dependant use of unions below
    // WARNING: This code is not portable to Big Endian platforms.

    // HL register
    union {
        uint16_t HL;
        struct {
            uint8_t L, H;
        };
    };

    // DE register
    union {
        uint16_t DE;
        struct {
            uint8_t E, D;
        };
    };

    // BC register
    union {
        uint16_t BC;
        struct {
            uint8_t C, B;
        };
    };

    uint8_t A;

    uint16_t SP;
    uint16_t PC;

    struct cpuFlags flags;

    uint8_t* memory;

    struct cpuStateSnapshot* stateSnapshot;

} cpuState;

typedef struct cpuStateSnapshot {

    // HL register
    union {
        uint16_t HL;
        struct {
            uint8_t L, H;
        };
    };

    // DE register
    union {
        uint16_t DE;
        struct {
            uint8_t E, D;
        };
    };

    // BC register
    union {
        uint16_t BC;
        struct {
            uint8_t C, B;
        };
    };

    uint8_t A;

    uint16_t SP;
    uint16_t PC;

    struct cpuFlags flags;

    // An instruction can only change two bytes at most
    // In the future I will make it be able to save more data at once but this is good enough for now
    uint16_t shortAddr;
    uint16_t shortWritten;

    // TODO: An underscore followed by a capital letter is reserved, what about a lower case letter?
    //struct cpuState* _nextSnapshot;
    struct cpuState* _previousSnapshot;

} cpuStateSnapshot;

struct cpuState initState(void);
int emulateState(struct cpuState *state);
int dumpState(struct cpuState* state, char *filename);

#endif//INC_8080EMU_HANDLESTATE_H
