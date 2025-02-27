#include "modding.h"
#include "global.h"

#include "apcommon.h"

struct ObjTokeiStep;

typedef void (*ObjTokeiStepFunc)(struct ObjTokeiStep*, struct PlayState*);

typedef struct ObjTokeiStepPanel {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 posChangeY;
    /* 0x10 */ s16 startFallingTimer; // Timer for when a step starts falling after the previous step has started
                                      // bouncing during opening cutscene
    /* 0x12 */ s8 numBounces; // Counter for times the step falls below its final Y pos, and thus will bounce back up
                              // during opening cutscene
    /* 0x13 */ s8 hasSoundPlayed;
} ObjTokeiStepPanel; // size = 0x14

typedef struct ObjTokeiStep {
    /* 0x000 */ DynaPolyActor dyna;
    /* 0x15C */ ObjTokeiStepFunc actionFunc;
    /* 0x160 */ ObjTokeiStepPanel panels[7];
} ObjTokeiStep; // size = 0x1EC

ObjTokeiStep* tokei_steps = NULL;

ItemId ocarina_item;
s16 test4_scene_id;

struct EnTest4;

typedef void (*EnTest4ActionFunc)(struct EnTest4*, PlayState*);

typedef struct EnTest4 {
    /* 0x000 */ Actor actor;
    /* 0x144 */ s8 csIdIndex; // 0 on night, 1 on day
    /* 0x145 */ u8 transitionCsTimer;
    /* 0x146 */ u16 unk_146;
    /* 0x148 */ u16 nextBellTime; // Next time the bell will sound
    /* 0x14A */ u16 lastBellTime; // Last time the bell sounded
    /* 0x14C */ u8 state;
    /* 0x150 */ EnTest4ActionFunc actionFunc;
} EnTest4; // size = 0x154

RECOMP_HOOK("ObjTokeiStep_Init")
void ObjTokeiStep_Init(Actor* thisx, PlayState* play) {
    tokei_steps = (ObjTokeiStep*) thisx;
}

RECOMP_HOOK("ObjTokeiStep_Destroy")
void ObjTokeiStep_Destroy(Actor* thisx, PlayState* play) {
    tokei_steps = NULL;
}

RECOMP_HOOK("func_80A42AB8")
void setupClocktowerSkip(EnTest4* this, PlayState* play) {
    ocarina_item = gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA];
    test4_scene_id = play->sceneId;

    gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] = ITEM_OCARINA_OF_TIME;
    play->sceneId = 0;
}

void ObjTokeiStep_SetupOpen(ObjTokeiStep* this);
void ObjTokeiStep_DrawOpen(Actor* thisx, PlayState* play);

RECOMP_HOOK_RETURN("func_80A42AB8")
void resetClocktowerSkip(EnTest4* this, PlayState* play) {
    gSaveContext.save.saveInfo.inventory.items[SLOT_OCARINA] = ocarina_item;
    play->sceneId = test4_scene_id;

    if (CURRENT_DAY == 3 && gSaveContext.save.time < CLOCK_TIME(0, 1) && tokei_steps != NULL && tokei_steps->dyna.actor.draw != ObjTokeiStep_DrawOpen) {
        ObjTokeiStep_SetupOpen(tokei_steps);
        tokei_steps->dyna.actor.draw = ObjTokeiStep_DrawOpen;
    }
}