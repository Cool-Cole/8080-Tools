//
// Created by Cole on 3/10/2022.
//

#include "handleSnapshots.h"

int takeStateSnapshot(struct cpuState *state){
    cpuStateSnapshot* currentSnapshot = calloc(1, sizeof(struct cpuStateSnapshot));

    if (NULL == currentSnapshot) {
        return -1;
    }

    // Basically think of this as a sort of linked list que
    // This pushes a snapshot onto the que and sends previous snapshots back
    currentSnapshot->_previousSnapshot = state->stateSnapshot;
    state->stateSnapshot = currentSnapshot;



    return 1;
}

int restorePreviousState(){

}