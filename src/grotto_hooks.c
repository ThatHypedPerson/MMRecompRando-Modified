#include "modding.h"
#include "global.h"

#include "apcommon.h"

struct DoorAna;

typedef void (*DoorAnaActionFunc)(struct DoorAna*, PlayState*);

typedef struct DoorAna {
    /* 0x000 */ Actor actor;
    /* 0x144 */ ColliderCylinder bombCollider;
    /* 0x190 */ DoorAnaActionFunc actionFunc;
} DoorAna; // size = 0x194

#define DOORANA_TYPE_BITMASK            0x300
#define DOORANA_TYPE_VISIBLE            0x000
#define DOORANA_TYPE_HIDDEN_STORMS      0x100 // Incomplete, leftover from OoT 
#define DOORANA_TYPE_HIDDEN_BOMB        0x200
#define DOORANA_TYPE_VISIBLE_SCENE_EXIT 0x300 // Destination dependent on scene exit list

#define DOORANA_GET_TYPE(thisx) ((thisx)->params & DOORANA_TYPE_BITMASK)
#define DOORANA_GET_ENTRANCE(thisx) ((((thisx)->params >> 12) & 0x7) - 1) 
#define DOORANA_GET_EX_ENTRANCE(thisx) ((thisx)->home.rot.z + 1)
#define DOORANA_GET_EXIT_INDEX(thisx) ((thisx)->params & 0x1F)
#define DOORANA_GET_ITEMFLAGS(thisx) ((thisx)->params & 0xFF)
#define DOORANA_SET_TYPE(thisx, t) ((thisx)->params = ((thisx)->params & ~DOORANA_TYPE_BITMASK) + (t))

static u16 sEntrances[] = {
    ENTRANCE(UNSET_0D, 0), ENTRANCE(GROTTOS, 0),  ENTRANCE(GROTTOS, 1),  ENTRANCE(GROTTOS, 2),  ENTRANCE(GROTTOS, 3),
    ENTRANCE(GROTTOS, 4),  ENTRANCE(GROTTOS, 5),  ENTRANCE(GROTTOS, 6),  ENTRANCE(GROTTOS, 7),  ENTRANCE(GROTTOS, 8),
    ENTRANCE(GROTTOS, 9),  ENTRANCE(GROTTOS, 10), ENTRANCE(GROTTOS, 11), ENTRANCE(GROTTOS, 12), ENTRANCE(GROTTOS, 13),
};

void DoorAna_GrabLink(DoorAna* this, PlayState* play);
void DoorAna_SetupAction(DoorAna* this, DoorAnaActionFunc actionFunction);

u16 grottoEntrance;

RECOMP_PATCH void DoorAna_WaitOpen(DoorAna* this, PlayState* play) {
    Player* player = GET_PLAYER(play);
    s32 grottoType = DOORANA_GET_TYPE(&this->actor);

    if (Math_StepToF(&this->actor.scale.x, 0.01f, 0.001f)) {
        if ((this->actor.targetMode != TARGET_MODE_0) && (play->transitionTrigger == TRANS_TRIGGER_OFF) &&
            (play->transitionMode == TRANS_MODE_OFF) && (player->stateFlags1 & PLAYER_STATE1_80000000) &&
            (player->av1.actionVar1 == 0)) {

            if (grottoType == DOORANA_TYPE_VISIBLE_SCENE_EXIT) {
                s32 exitIndex = DOORANA_GET_EXIT_INDEX(&this->actor);

                play->nextEntrance = play->setupExitList[exitIndex];
            } else {
                s32 destinationIdx = DOORANA_GET_ENTRANCE(&this->actor);

                Play_SetupRespawnPoint(&play->state, RESPAWN_MODE_UNK_3, PLAYER_PARAMS(0xFF, PLAYER_INITMODE_4));

                gSaveContext.respawn[RESPAWN_MODE_UNK_3].pos.y = this->actor.world.pos.y;
                gSaveContext.respawn[RESPAWN_MODE_UNK_3].yaw = this->actor.home.rot.y;

                // Stores item and chest flag that ACTOR_EN_TORCH uses for spawning the grotto chest
                gSaveContext.respawn[RESPAWN_MODE_UNK_3].data = DOORANA_GET_ITEMFLAGS(&this->actor);

                if (destinationIdx < 0) {
                    destinationIdx = DOORANA_GET_EX_ENTRANCE(&this->actor);
                }

                play->nextEntrance = sEntrances[destinationIdx];
            }

			grottoEntrance = play->sceneId;
			
            DoorAna_SetupAction(this, DoorAna_GrabLink);

        } else if (!Play_InCsMode(play) && !(player->stateFlags1 & (PLAYER_STATE1_8000000 | PLAYER_STATE1_800000)) &&
                   (this->actor.xzDistToPlayer <= 20.0f) && (this->actor.playerHeightRel >= -50.0f) &&
                   (this->actor.playerHeightRel <= 15.0f)) {
            player->stateFlags1 |= PLAYER_STATE1_80000000;
            this->actor.targetMode = TARGET_MODE_1;

        } else {
            this->actor.targetMode = TARGET_MODE_0;
        }
    }

    Actor_SetScale(&this->actor, this->actor.scale.x);
}