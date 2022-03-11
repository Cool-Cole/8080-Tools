#ifndef INC_8080EMU_HANDLESTATE_H
#define INC_8080EMU_HANDLESTATE_H

#include <stdint.h>

typedef struct cpuFlags {

    // TODO: look into using bit fields and a union to uint8_t
    // Pros: will make Pop/Push_PSW look nicer, will save space
    // Cons: possibly slower

    // https://retrocomputing.stackexchange.com/questions/12300/bit-one-of-the-intel-8080s-flags-register

    union {
        uint8_t flagByte;
        struct {
            uint8_t sign : 1;
            uint8_t zero : 1;
            uint8_t _alwaysZero1 : 1;
            uint8_t auxCarry : 1;
            uint8_t _alwaysZero2 : 1;
            uint8_t parity : 1;
            uint8_t _alwaysOne : 1;
            uint8_t carry : 1;
        };
    };

/*
    uint8_t sign;
    uint8_t zero;
    uint8_t auxCarry;
    uint8_t parity;
    uint8_t carry;
*/

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

    // TODO: change name to stateFlags
    struct cpuFlags flags;

    uint8_t *memory;

    struct cpuStateSnapshot *stateSnapshot;

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
    //struct cpuStateSnapshot *_nextSnapshot;
    struct cpuStateSnapshot *_previousSnapshot;

} cpuStateSnapshot;

struct cpuState initState(void);
int emulateState(struct cpuState *state);
int dumpState(struct cpuState *state, char *filename);

#endif//INC_8080EMU_HANDLESTATE_H
