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

    uint8_t *memory;

} cpuState;

struct cpuState initState(void);

int emulateState(struct cpuState *state);

#endif//INC_8080EMU_HANDLESTATE_H
