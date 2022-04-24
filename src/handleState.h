#ifndef INC_8080EMU_HANDLESTATE_H
#define INC_8080EMU_HANDLESTATE_H

#include "intDefs.h"

typedef struct cpuFlags {

    // TODO: look into using bit fields and a union to u8
    // Pros: will make Pop/Push_PSW look nicer, will save space
    // Cons: possibly slower

    // https://retrocomputing.stackexchange.com/questions/12300/bit-one-of-the-intel-8080s-flags-register

    union {
        u8 flagByte;
        struct {
            u8 sign : 1;
            u8 zero : 1;
            u8 _alwaysZero1 : 1;
            u8 auxCarry : 1;
            u8 _alwaysZero2 : 1;
            u8 parity : 1;
            u8 _alwaysOne : 1;
            u8 carry : 1;
        };
    };

} cpuFlags;

typedef struct cpuState {
    // WARNING: Little Endian dependant use of unions below
    // WARNING: This code is not portable to Big Endian platforms.

    // HL register
    union {
        u16 HL;
        struct {
            u8 L, H;
        };
    };

    // DE register
    union {
        u16 DE;
        struct {
            u8 E, D;
        };
    };

    // BC register
    union {
        u16 BC;
        struct {
            u8 C, B;
        };
    };

    u8 A;

    u16 SP;
    u16 PC;

    // TODO: change name to stateFlags
    struct cpuFlags flags;

    u8 *memory;

    u64 totalInstructionCounter;

} cpuState;

struct cpuState initState(void);
int emulateState(struct cpuState *state);
int dumpState(struct cpuState *state, char *filename);

#endif//INC_8080EMU_HANDLESTATE_H
