#include "modding.h"
#include "global.h"

struct ObjDemo;

typedef void (*ObjDemoActionFunc)(struct ObjDemo*, PlayState*);

#define OBJDEMO_GET_SWITCH_FLAG_MASK(thisx) ((thisx)->params & 0xFF)
#define OBJDEMO_GET_SWITCH_FLAG(thisx) ((thisx)->params)

typedef struct ObjDemo {
    /* 0x000 */ Actor actor;
    /* 0x144 */ ObjDemoActionFunc actionFunc;
    /* 0x148 */ s32 unk_148;
    /* 0x14C */ f32 xzRange;
    /* 0x150 */ f32 yRange;
} ObjDemo; // size = 0x154

#define THIS ((ObjDemo*)thisx)

RECOMP_PATCH void ObjDemo_Init(Actor* thisx, PlayState* play) {
    ObjDemo* this = THIS;

    thisx->params = OBJDEMO_GET_SWITCH_FLAG_MASK(thisx);
    if (OBJDEMO_GET_SWITCH_FLAG(thisx) != 0xFF) {
        Actor_Kill(&this->actor);
        return;
    }
}