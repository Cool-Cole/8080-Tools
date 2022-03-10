//
// Created by Cole on 3/10/2022.
//

#ifndef INC_8080EMU_HANDLESNAPSHOTS_H
#define INC_8080EMU_HANDLESNAPSHOTS_H

#include <stdlib.h>

#include "handleState.h"

int takeStateSnapshot(struct cpuState *state);

#endif//INC_8080EMU_HANDLESNAPSHOTS_H
