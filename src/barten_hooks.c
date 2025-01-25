#include "modding.h"
#include "global.h"

#include "apcommon.h"

// why is this a seperate function???
RECOMP_PATCH s32 func_80BE0D38(Actor* thisx, PlayState* play) {
    // return Inventory_HasEmptyBottle();
    return rando_shopsanity_enabled();
}