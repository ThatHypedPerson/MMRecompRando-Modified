#include "modding.h"
#include "global.h"

#include "overlays/actors/ovl_Bg_Haka_Curtain/z_bg_haka_curtain.h"

void func_80B6DE80(BgHakaCurtain* this);

RECOMP_PATCH void func_80B6DCAC(BgHakaCurtain* this, PlayState* play) {
    if (Flags_GetClear(play, this->dyna.actor.room)) {
        // func_80B6DCEC(this);
		func_80B6DE80(this);
    }
}