//
// Created by Cole on 3/10/2022.
//

#include "handleSnapshots.h"

int takeStateSnapshot(struct cpuState *state) {
    cpuStateSnapshot *currentSnapshot = calloc(1, sizeof(struct cpuStateSnapshot));

    if (NULL == currentSnapshot) {
        return -1;
    }

    currentSnapshot->HL = state->HL;
    currentSnapshot->DE = state->DE;
    currentSnapshot->BC = state->BC;
    currentSnapshot->A = state->A;
    currentSnapshot->SP = state->SP;
    currentSnapshot->PC = state->PC;
    currentSnapshot->flags = state->flags;

    /*for(uint16_t i = 0; i <= UINT16_MAX; i++){
        if(state->memory[i] != ){
            //TODO: Figure out some way to track memory changes
        }
    }*/

    // Basically think of this as a sort of linked list que
    // This pushes a snapshot onto the que and sends previous snapshots back
    currentSnapshot->_previousSnapshot = state->stateSnapshot;
    state->stateSnapshot = currentSnapshot;

    return 1;
}

int restorePreviousState(struct cpuState *state) {

    if(NULL == state->stateSnapshot){
        return -1;
    }

    if (NULL == state->stateSnapshot->_previousSnapshot){
        return -1;
    }



    return 1;
}