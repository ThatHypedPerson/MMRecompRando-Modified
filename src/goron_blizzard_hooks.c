#include "modding.h"
#include "global.h"

typedef enum ObjectDaiLimb {
    /* 0x00 */ OBJECT_DAI_LIMB_NONE,
    /* 0x01 */ OBJECT_DAI_LIMB_01,
    /* 0x02 */ OBJECT_DAI_LIMB_02,
    /* 0x03 */ OBJECT_DAI_LIMB_03,
    /* 0x04 */ OBJECT_DAI_LIMB_04,
    /* 0x05 */ OBJECT_DAI_LIMB_05,
    /* 0x06 */ OBJECT_DAI_LIMB_06,
    /* 0x07 */ OBJECT_DAI_LIMB_07,
    /* 0x08 */ OBJECT_DAI_LIMB_08,
    /* 0x09 */ OBJECT_DAI_LIMB_09,
    /* 0x0A */ OBJECT_DAI_LIMB_0A,
    /* 0x0B */ OBJECT_DAI_LIMB_0B,
    /* 0x0C */ OBJECT_DAI_LIMB_0C,
    /* 0x0D */ OBJECT_DAI_LIMB_0D,
    /* 0x0E */ OBJECT_DAI_LIMB_0E,
    /* 0x0F */ OBJECT_DAI_LIMB_0F,
    /* 0x10 */ OBJECT_DAI_LIMB_10,
    /* 0x11 */ OBJECT_DAI_LIMB_11,
    /* 0x12 */ OBJECT_DAI_LIMB_12,
    /* 0x13 */ OBJECT_DAI_LIMB_MAX
} ObjectDaiLimb;

struct EnDai;

typedef void (*EnDaiActionFunc)(struct EnDai*, PlayState*);

typedef struct EnDaiEffect {
    /* 0x00 */ u8 isEnabled;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ UNK_TYPE1 unk_03[0xD];
    /* 0x10 */ Vec3f unk_10;
    /* 0x1C */ Vec3f unk_1C;
    /* 0x28 */ Vec3f unk_28;
    /* 0x34 */ f32 unk_34;
    /* 0x38 */ f32 unk_38;
} EnDaiEffect; // size = 0x3C

#define EN_DAI_EFFECT_COUNT 32

typedef struct EnDai {
    /* 0x000 */ Actor actor;
    /* 0x144 */ SkelAnime skelAnime;
    /* 0x188 */ EnDaiActionFunc actionFunc;
    /* 0x18C */ MtxF unk_18C;
    /* 0x1CC */ u8 cueId;
    /* 0x1CD */ u8 unk_1CD;
    /* 0x1CE */ u16 unk_1CE;
    /* 0x1D0 */ s32 unk_1D0;
    /* 0x1D4 */ s16 unk_1D4;
    /* 0x1D6 */ s16 unk_1D6;
    /* 0x1D8 */ s16 unk_1D8;
    /* 0x1DA */ s16 unk_1DA;
    /* 0x1DC */ s16 unk_1DC;
    /* 0x1E0 */ f32 unk_1E0;
    /* 0x1E4 */ Vec3f unk_1E4;
    /* 0x1F0 */ Vec3f unk_1F0;
    /* 0x1FC */ Vec3f unk_1FC;
    /* 0x208 */ Vec3s jointTable[OBJECT_DAI_LIMB_MAX];
    /* 0x27A */ Vec3s morphTable[OBJECT_DAI_LIMB_MAX];
    /* 0x2EC */ EnDaiEffect effects[EN_DAI_EFFECT_COUNT];
    /* 0xA6C */ s32 unk_A6C;
    /* 0xA70 */ s32 animIndex;
} EnDai; // size = 0xA74

RECOMP_PATCH void func_80B3EE8C(EnDai* this, PlayState* play) {
    // s16 csId = this->actor.csId;

    // if (CutsceneManager_IsNext(csId)) {
    //     CutsceneManager_StartWithPlayerCs(csId, &this->actor);
    // } else {
    //     CutsceneManager_Queue(csId);
    // }

    Audio_PlaySfx(NA_SE_SY_CORRECT_CHIME);
    SET_WEEKEVENTREG(WEEKEVENTREG_30_01);
    Actor_Kill(&this->actor);
}