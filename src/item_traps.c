#include "global.h"
#include "modding.h"

#include "apcommon.h"

#include "overlays/actors/ovl_En_Bom/z_en_bom.h"

void func_80833B18(PlayState* play, Player* this, s32 arg2, f32 speed, f32 velocityY, s16 arg5, s32 invincibilityTimer);
void func_80169ECC(PlayState* this);
s32 func_80834534(PlayState* play, Player* this);

void TriggerIceTrap(PlayState* play, Player* player) {
   func_80833B18(play, player, 3, 0.0f, 0.0f, 0, 20);
}

void TriggerBurnTrap(PlayState* play, Player* player) {
    func_80834534(play, player);
}

void TriggerElectrocutionTrap(PlayState* play, Player* player) {
    func_80833B18(play, player, 4, 0.0f, 0.0f, 0, 20);
}

void TriggerRespawnTrap(PlayState* play, Player* player) {
    Audio_PlaySfx(NA_SE_VO_LI_FALL_L);
    gSaveContext.respawn[RESPAWN_MODE_DOWN].tempSwitchFlags = play->actorCtx.sceneFlags.switches[2];
    gSaveContext.respawn[RESPAWN_MODE_DOWN].unk_18 = play->actorCtx.sceneFlags.collectible[1];
    gSaveContext.respawn[RESPAWN_MODE_DOWN].tempCollectFlags = play->actorCtx.sceneFlags.collectible[2];
    play->nextEntrance = gSaveContext.respawn[RESPAWN_MODE_DOWN].entrance;
    // gSaveContext.respawnFlag = 1;
    gSaveContext.respawnFlag = 0;
    func_80169ECC(play);
    play->transitionTrigger = TRANS_TRIGGER_START;
    play->transitionType = TRANS_TYPE_FADE_BLACK;
}

void TriggerBombTrap(PlayState* play, Player* player) {
    EnBom* bomb;
    bomb = (EnBom*)Actor_Spawn(&play->actorCtx, play, ACTOR_EN_BOM, player->actor.world.pos.x, player->actor.world.pos.y,
                       player->actor.world.pos.z, BOMB_EXPLOSIVE_TYPE_BOMB, 0, 0, BOMB_TYPE_BODY);
    if (bomb != NULL) {
        bomb->timer = 0;
    }
}