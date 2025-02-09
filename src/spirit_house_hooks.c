#include "modding.h"
#include "global.h"

#include "apcommon.h"

#define LOCATION_SPIRIT_HOUSE 0x0701DE

struct EnGb2;

typedef void (*EnGb2ActionFunc)(struct EnGb2*, PlayState*);

#define OBJECT_PS_LIMB_MAX 0xC

typedef struct EnGb2 {
    /* 0x0000 */ Actor actor;
    /* 0x144 */ SkelAnime skelAnime;
    /* 0x188 */ Vec3s jointTable[OBJECT_PS_LIMB_MAX];
    /* 0x1D0 */ Vec3s morphTable[OBJECT_PS_LIMB_MAX];
    /* 0x218 */ EnGb2ActionFunc actionFunc;
    /* 0x21C */ ColliderCylinder collider;
    /* 0x268 */ Actor* unk_268;
    /* 0x26C */ u16 unk_26C;
    /* 0x26E */ u16 unk_26E;
    /* 0x270 */ Vec3s unk_270;
    /* 0x276 */ Vec3s unk_276;
    /* 0x27C */ s16 unk_27C;
    /* 0x27E */ s16 unk_27E;
    /* 0x280 */ s16 unk_280;
    /* 0x282 */ s16 csIdList[3];
    /* 0x288 */ s16 unk_288;
    /* 0x28A */ u8 unk_28A;
    /* 0x28C */ s32 unk_28C;
    /* 0x290 */ s16 csIdIndex;
} EnGb2; // size = 0x294

void func_80B109DC(EnGb2* this, PlayState* play);
void func_80B0FD8C(EnGb2 *this, PlayState *play);
void func_80B0FE7C(PlayState *play);
void func_80B10240(EnGb2 *this, PlayState *play);

RECOMP_PATCH void func_80B10924(EnGb2* this, PlayState* play) {
    s32 getItemId;

    // if (CHECK_WEEKEVENTREG(WEEKEVENTREG_54_40)) {
    //     getItemId = GI_RUPEE_PURPLE;
    // } else {
    //     getItemId = GI_HEART_PIECE;
    // }

    if (Actor_HasParent(&this->actor, play)) {
        this->actor.parent = NULL;
        // if (getItemId == GI_HEART_PIECE) {
        //     SET_WEEKEVENTREG(WEEKEVENTREG_54_40);
        // } else {
        //     Rupees_ChangeBy(50);
        // }
        this->actionFunc = func_80B109DC;
    } else {
        Actor_OfferGetItem(&this->actor, play, GI_HEART_PIECE, 300.0f, 300.0f);
        // Actor_OfferGetItem(&this->actor, play, getItemId, 300.0f, 300.0f);
    }
}

// @ap lower heart requirement to new minimum (1)
RECOMP_PATCH u16 func_80B0F7FC(EnGb2* this) {
    switch (this->unk_26E) {
        case 0x14D0:
            return 0x14D1;

        case 0x14D1:
            if (CHECK_EVENTINF(EVENTINF_47)) {
                return 0x14E4;
            }

            // if (gSaveContext.save.saveInfo.playerData.health > 0x30) {
            if (gSaveContext.save.saveInfo.playerData.health >= 0x10) {
                return 0x14D2;
            }

            this->unk_26C |= 2;
            return 0x14D3;

        case 0x14E4:
            // if (gSaveContext.save.saveInfo.playerData.health > 0x30) {
            if (gSaveContext.save.saveInfo.playerData.health >= 0x10) {
                return 0x14D2;
            }

            this->unk_26C |= 2;
            return 0x14D3;

        case 0x14D2:
            if (CHECK_EVENTINF(EVENTINF_47)) {
                return 0x14E5;
            }
            return 0x14D4;

        case 0x14D4:
        case 0x14E5:
            return 0x14D5;

        case 0x14D8:
            return 0x14D9;

        case 0x14D9:
            return 0x14DA;

        default:
            return 0;
    }
}

RECOMP_PATCH void func_80B10344(EnGb2* this, PlayState* play) {
    if (this->unk_280 == 1) {
        func_80B0FD8C(this, play);
    }

    if (this->unk_280 == 2) {
        if ((this->unk_268 != NULL) && (this->unk_268->update == NULL)) {
            this->unk_268 = NULL;
            this->unk_26C |= 0x400;
        }
    }

    if ((this->actor.child != NULL) && (this->actor.child->update == NULL)) {
        this->actor.child = NULL;
        this->unk_26C |= 0x200;
    }

    if (this->unk_26C & 0x200) {
        if (this->unk_280 == 3) {
            this->unk_26C &= ~0x200;
            gSaveContext.timerStates[TIMER_ID_MINIGAME_1] = TIMER_STATE_STOP;
            Environment_StartTime();
            SET_EVENTINF(EVENTINF_46);
            func_80B0FE7C(play);
        } else if (this->unk_280 == 2) {
            if (this->unk_26C & 0x400) {
                this->unk_280++;
                this->unk_26C &= ~0x200;
                this->unk_26C &= ~0x400;
                this->actionFunc = func_80B10240;
            }
        } else {
            this->unk_280++;
            this->unk_26C &= ~0x200;
            this->actionFunc = func_80B10240;
        }
    }

    // if (gSaveContext.save.saveInfo.playerData.health <= 0x30) {
    if (gSaveContext.save.saveInfo.playerData.health < 0x10) {
        gSaveContext.timerStates[TIMER_ID_MINIGAME_1] = TIMER_STATE_STOP;
        SET_EVENTINF(EVENTINF_46);
        SET_EVENTINF(EVENTINF_45);

        if ((this->unk_268 != NULL) && (this->unk_268->update == NULL)) {
            this->unk_268 = NULL;
        }

        if ((this->actor.child != NULL) && (this->actor.child->update == NULL)) {
            this->actor.child = NULL;
        }

        func_80B0FE7C(play);
    } else if (gSaveContext.timerCurTimes[TIMER_ID_MINIGAME_1] == SECONDS_TO_TIMER(0)) {
        gSaveContext.timerStates[TIMER_ID_MINIGAME_1] = TIMER_STATE_STOP;
        SET_EVENTINF(EVENTINF_46);
        SET_EVENTINF(EVENTINF_44);

        if ((this->unk_268 != NULL) && (this->unk_268->update == NULL)) {
            this->unk_268 = NULL;
        }

        if ((this->actor.child != NULL) && (this->actor.child->update == NULL)) {
            this->actor.child = NULL;
        }

        func_80B0FE7C(play);
    }
}