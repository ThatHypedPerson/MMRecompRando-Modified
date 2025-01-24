#include "modding.h"
#include "global.h"

struct ObjSnowball;

typedef void (*ObjSnowballActionFunc)(struct ObjSnowball*, PlayState*);

typedef struct {
    /* 0x00 */ Vec3f unk_00;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ Vec3s unk_1C;
    /* 0x22 */ s16 unk_22;
    /* 0x24 */ s16 unk_24;
    /* 0x26 */ s16 unk_26;
    /* 0x28 */ CollisionPoly* unk_28;
    /* 0x2C */ u8 unk_2C;
    /* 0x2D */ u8 unk_2D;
} ObjSnowballStruct; // size = 0x30

typedef struct ObjSnowball {
    /* 0x000 */ Actor actor;
    /* 0x144 */ ColliderJntSph collider;
    /* 0x164 */ ColliderJntSphElement colliderElements[1];
    /* 0x1A4 */ ObjSnowballActionFunc actionFunc;
    /* 0x1A8 */ ObjSnowballStruct unk_1A8[2];
    /* 0x208 */ s8 unk_208;
    /* 0x209 */ s8 unk_209;
    /* 0x20A */ s8 unk_20A;
    /* 0x20B */ s8 unk_20B;
    /* 0x20C */ f32 unk_20C;
    /* 0x210 */ s8 unk_210;
    /* 0x211 */ s8 unk_211;
} ObjSnowball; // size = 0x214

void func_80B03FF8(ObjSnowball* this, PlayState* play);
void func_80B04608(ObjSnowball* this, PlayState* play);
void func_80B046E4(ObjSnowball* this, PlayState* play);

RECOMP_PATCH void func_80B0457C(ObjSnowball* this, PlayState* play) {
    if (CutsceneManager_IsNext(this->actor.csId)) {
        // CutsceneManager_StartWithPlayerCs(this->actor.csId, &this->actor);
        func_80B03FF8(this, play);
        this->unk_20B = 1;
        if (this->unk_20A == 0) {
            func_80B04608(this, play);
        } else {
            func_80B046E4(this, play);
        }
    } else {
        CutsceneManager_Queue(this->actor.csId);
    }
}