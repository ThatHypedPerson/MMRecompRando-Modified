#include "modding.h"
#include "global.h"

struct DoorShutter;

typedef void (*DoorShutterActionFunc)(struct DoorShutter*, PlayState*);

#define DOORSHUTTER_GET_1F(thisx) ((thisx)->params & 0x1F)
#define DOORSHUTTER_GET_SWITCH_FLAG(thisx) ((thisx)->params & 0x7F)
#define DOORSHUTTER_GET_380(thisx) (((thisx)->params >> 7) & 7)

typedef struct SlidingDoorActor {
    /* 0x000 */ DynaPolyActor dyna;
    /* 0x15C */ s16 unk_15C;
    /* 0x15E */ s16 unk_15E;
} SlidingDoorActor; // size = 0x160

typedef struct DoorShutter {
    /* 0x000 */ SlidingDoorActor slidingDoor;
    /* 0x160 */ s16 csId;
    /* 0x0162 */ u8 doorType;
    /* 0x0163 */ u8 unk_163;
    /* 0x0164 */ u8 unk_164;
    /* 0x0165 */ s8 objectSlot;
    /* 0x0166 */ s8 unk_166;
    /* 0x0167 */ s8 unk_167;
    /* 0x0168 */ f32 unk_168;
    /* 0x016C */ DoorShutterActionFunc actionFunc;
} DoorShutter; // size = 0x170

void DoorShutter_SetupAction(DoorShutter* this, DoorShutterActionFunc actionFunc);
void func_808A1684(DoorShutter* this, PlayState* play);
s32 func_808A0E28(DoorShutter* this, PlayState* play);

RECOMP_PATCH void func_808A1090(DoorShutter* this, PlayState* play) {
    if (this->slidingDoor.unk_15C != 0) {
        DoorShutter_SetupAction(this, func_808A1684);
        this->slidingDoor.dyna.actor.velocity.y = 0.0f;
        if (this->unk_166 != 0) {
            Flags_SetSwitch(play, DOORSHUTTER_GET_SWITCH_FLAG(&this->slidingDoor.dyna.actor));
            if (this->doorType != 5) {
                DUNGEON_KEY_COUNT(gSaveContext.mapIndex) = DUNGEON_KEY_COUNT(gSaveContext.mapIndex) - 1;
                Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK);
            } else {
                Actor_PlaySfx(&this->slidingDoor.dyna.actor, NA_SE_EV_CHAIN_KEY_UNLOCK_B);
            }
        }
    } else {
        s32 doorDirection = func_808A0E28(this, play);

        if (doorDirection != 0) {
            Player* player = GET_PLAYER(play);

            player->doorType = PLAYER_DOORTYPE_SLIDING;
            player->doorDirection = doorDirection;
            player->doorActor = &this->slidingDoor.dyna.actor;

            if (this->unk_163 == 7) {
                player->doorTimer = 12;
            } else {
                player->doorTimer = 0;
            }

            if (this->doorType == 6) {
                // if (gSaveContext.save.saveInfo.playerData.healthCapacity <
                //     (DOORSHUTTER_GET_1F(&this->slidingDoor.dyna.actor) * 0x10)) {
                //     player->doorType = PLAYER_DOORTYPE_TALKING;
                //     this->slidingDoor.dyna.actor.textId = 0x14FC;
                // }
            } else if (this->unk_166 != 0) {
                if (this->doorType == 5) {
                    if (!CHECK_DUNGEON_ITEM(DUNGEON_BOSS_KEY, gSaveContext.mapIndex)) {
                        player->doorType = PLAYER_DOORTYPE_TALKING;
                        this->slidingDoor.dyna.actor.textId = 0x1803;
                    }
                    player->doorTimer += 10;
                } else if (DUNGEON_KEY_COUNT(gSaveContext.mapIndex) <= 0) {
                    player->doorType = PLAYER_DOORTYPE_TALKING;
                    this->slidingDoor.dyna.actor.textId = 0x1802;
                } else {
                    player->doorTimer += 10;
                }
            }
            func_80122F28(player);
        }
    }
}