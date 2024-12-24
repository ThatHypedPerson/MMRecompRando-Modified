#include "modding.h"
#include "global.h"

#include "apcommon.h"

typedef s32 (*PictoValidationFunc)(struct PlayState*, Actor*);

typedef struct {
    /* 0x000 */ Actor actor;
    /* 0x144 */ PictoValidationFunc validationFunc;
} PictoActor;

struct EnKakasi;

typedef void (*EnKakasiActionFunc)(struct EnKakasi*, PlayState*);

typedef struct EnKakasi {
    /* 0x000 */ PictoActor picto;
    /* 0x148 */ EnKakasiActionFunc actionFunc;
    /* 0x14C */ SkelAnime skelAnime;
    /* 0x190 */ s16 unk190; // camera index for song teaching angles?
    /* 0x192 */ s16 postTeachTimer;
    /* 0x194 */ s16 aboveGroundStatus; // from params, changed to 2 in init
    /* 0x196 */ s16 unkState196;
    /* 0x19A */ UNK_TYPE1 pad198[0x8];
    /* 0x1A0 */ s32 animIndex;
    /* 0x1A4 */ s32 unkCounter1A4; // counter, counts up to F while he digs away, reused elsewhere
    /* 0x1A8 */ s32 unkState1A8;
    /* 0x1AC */ s16 talkState;
    /* 0x1AE */ s16 csIdList[3];
    /* 0x1B4 */ f32 animEndFrame;
    /* 0x1B8 */ f32 unkHeight;
    /* 0x1BC */ Vec3f unk1BC; // set by post limbdraw func for one limb
    /* 0x1C8 */ UNK_TYPE1 pad1C8[0x3C];
    /* 0x204 */ s16 unk204; // set to A, F, 0x14, 0x28 frequently
    /* 0x206 */ UNK_TYPE1 pad206[2];
    /* 0x208 */ s16 subCamId;
    /* 0x20C */ f32 subCamFov;
    /* 0x210 */ f32 subCamFovNext;
    /* 0x214 */ Vec3f subCamEye;
    /* 0x220 */ Vec3f subCamAt;
    /* 0x22C */ Vec3f unk22C;
    /* 0x238 */ Vec3f subCamEyeNext;
    /* 0x244 */ Vec3f subCamAtNext;
    /* 0x250 */ f32 songSummonDist;
    /* 0x254 */ ColliderCylinder collider;
} EnKakasi; // size = 0x2A0

#define ACTOR_FLAG_LOCK_ON_DISABLED  (1 << 27)

void EnKakasi_SetupRiseOutOfGround(EnKakasi* this, PlayState* play);

RECOMP_PATCH void EnKakasi_IdleUnderground(EnKakasi* this, PlayState* play) {
    // if (CHECK_WEEKEVENTREG(WEEKEVENTREG_79_08) && (this->picto.actor.xzDistToPlayer < this->songSummonDist) &&
    //     ((BREG(1) != 0) || (play->msgCtx.ocarinaMode == OCARINA_MODE_PLAYED_SCARECROW_SPAWN))) {
    if ((this->picto.actor.xzDistToPlayer < this->songSummonDist) && ((BREG(1) != 0) || (play->msgCtx.ocarinaMode == OCARINA_MODE_ACTIVE))) {
        this->picto.actor.flags &= ~ACTOR_FLAG_LOCK_ON_DISABLED;
        play->msgCtx.ocarinaMode = OCARINA_MODE_END;
        AudioOcarina_SetOcarinaDisableTimer(0, 20);
        // Message_CloseTextbox(play);
        this->actionFunc = EnKakasi_SetupRiseOutOfGround;
    }
}