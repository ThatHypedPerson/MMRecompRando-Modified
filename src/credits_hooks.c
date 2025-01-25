#include "modding.h"
#include "global.h"

void CutsceneCmd_DestinationDefault(PlayState *play, CutsceneContext *csCtx, CsCmdDestination *cmd);

// Chooses between a cutscene or a rotating mask depending on whether the player has the corresponding mask
RECOMP_PATCH void CutsceneCmd_ChooseCreditsScenes(PlayState* play, CutsceneContext* csCtx, CsCmdChooseCreditsScene* cmd) {
    if ((csCtx->curFrame >= cmd->startFrame) && (func_801A3950(SEQ_PLAYER_BGM_MAIN, true) != 0xFF)) {
        switch (cmd->type) {
            case CS_CREDITS_DESTINATION:
                CutsceneCmd_DestinationDefault(play, csCtx, (CsCmdDestination*)cmd);
                break;

            case CS_CREDITS_MASK_KAMARO:
				// if (INV_CONTENT(ITEM_MASK_KAMARO) == ITEM_MASK_KAMARO) {
                if (true) {
                    play->nextEntrance = ENTRANCE(MILK_BAR, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF0;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_GREAT_FAIRY:
				// if (INV_CONTENT(ITEM_MASK_GREAT_FAIRY) == ITEM_MASK_GREAT_FAIRY) {
                if (true) {
                    play->nextEntrance = ENTRANCE(FAIRY_FOUNTAIN, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF0;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 1);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_ROMANI:
				// if (INV_CONTENT(ITEM_MASK_ROMANI) == ITEM_MASK_ROMANI) {
                if (true) {
                    play->nextEntrance = ENTRANCE(ROMANI_RANCH, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF1;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 2);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_BLAST:
				// if (INV_CONTENT(ITEM_MASK_BLAST) == ITEM_MASK_BLAST) {
                if (true) {
                    play->nextEntrance = ENTRANCE(WEST_CLOCK_TOWN, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF0;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 3);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_CIRCUS_LEADER:
				// if (INV_CONTENT(ITEM_MASK_CIRCUS_LEADER) == ITEM_MASK_CIRCUS_LEADER) {
                if (true) {
                    play->nextEntrance = ENTRANCE(MILK_BAR, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF1;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 5);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_BREMEN:
				// if (INV_CONTENT(ITEM_MASK_BREMEN) == ITEM_MASK_BREMEN) {
                if (true) {
                    play->nextEntrance = ENTRANCE(MILK_BAR, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF3;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 6);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_IKANA:
                play->nextEntrance = ENTRANCE(IKANA_CANYON, 0);
                gSaveContext.nextCutsceneIndex = 0xFFF3;
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_COUPLE:
				// if (INV_CONTENT(ITEM_MASK_COUPLE) == ITEM_MASK_COUPLE) {
                if (true) {
                    play->nextEntrance = ENTRANCE(TERMINA_FIELD, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF8;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 7);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_BUNNY:
				// if (INV_CONTENT(ITEM_MASK_BUNNY) == ITEM_MASK_BUNNY) {
                if (true) {
                    play->nextEntrance = ENTRANCE(CUCCO_SHACK, 0);
                    gSaveContext.nextCutsceneIndex = 0xFFF0;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 4);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            case CS_CREDITS_MASK_POSTMAN:
				// if (INV_CONTENT(ITEM_MASK_POSTMAN) == ITEM_MASK_POSTMAN) {
                if (true) {
                    play->nextEntrance = ENTRANCE(TERMINA_FIELD, 1);
                    gSaveContext.nextCutsceneIndex = 0xFFF8;
                } else {
                    play->nextEntrance = ENTRANCE(CUTSCENE, 8);
                    gSaveContext.nextCutsceneIndex = 0xFFF9;
                }
                play->transitionTrigger = TRANS_TRIGGER_START;
                break;

            default:
                break;
        }
    }
}