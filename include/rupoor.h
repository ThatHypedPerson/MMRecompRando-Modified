#include "ultra64.h"
#include "global.h"

Gfx gGiRupoorInnerColorDL[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0x80, 20, 20, 20, 255),
    gsDPSetEnvColor(0, 0, 0, 255),
    gsSPEndDisplayList(),
};

Gfx gGiRupoorOuterColorDL[] = {
    gsDPPipeSync(),
    gsDPSetPrimColor(0, 0x80, 20, 20, 20, 255),
    gsDPSetEnvColor(30, 30, 30, 255),
    gsSPEndDisplayList(),
};