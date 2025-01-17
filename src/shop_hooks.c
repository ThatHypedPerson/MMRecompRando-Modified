#include "modding.h"
#include "global.h"

#include "apcommon.h"

#define LOCATION_SHOP_ITEM (0x090000 | this->actor.params)

#include "overlays/actors/ovl_En_GirlA/z_en_girla.h"

#define THIS ((EnGirlA*)thisx)

// temporarily set to 34 slots
static bool shopObjectStatic[34];
static bool shopObjectLoading[34];
static bool shopObjectLoaded[34];
static OSMesgQueue shopObjectLoadQueue[34];
static void* shopObjectSegments[34];

void EnGirlA_WaitForObject(EnGirlA* this, PlayState* play) {
    s16 getItemId = rando_get_item_id(LOCATION_SHOP_ITEM);
    s16 objectSlot = Object_GetSlot(&play->objectCtx, getObjectId(getItemId));

    if (isAP(getItemId)) {
        shopObjectStatic[this->actor.params] = true;
        shopObjectLoaded[this->actor.params] = true;
    } else if (!shopObjectLoaded[this->actor.params] && !shopObjectLoading[this->actor.params] && Object_IsLoaded(&play->objectCtx, objectSlot)) {
        this->actor.objectSlot = objectSlot;
        Actor_SetObjectDependency(play, &this->actor);
        shopObjectStatic[this->actor.params] = true;
        shopObjectLoaded[this->actor.params] = true;
    } else if (!shopObjectLoading[this->actor.params] && !shopObjectLoaded[this->actor.params]) {
        loadObject(play, &shopObjectSegments[this->actor.params], &shopObjectLoadQueue[this->actor.params], getObjectId(getItemId));
        shopObjectLoading[this->actor.params] = true;
    } else if (osRecvMesg(&shopObjectLoadQueue[this->actor.params], NULL, OS_MESG_NOBLOCK) == 0) {
        shopObjectLoading[this->actor.params] = false;
        shopObjectLoaded[this->actor.params] = true;
    }
}

RECOMP_PATCH void EnGirlA_Update(Actor* thisx, PlayState* play) {
    EnGirlA* this = THIS;

    if (!shopObjectLoaded[this->actor.params]) {
        EnGirlA_WaitForObject(this, play);
    }

    this->mainActionFunc(this, play);
}

RECOMP_PATCH void EnGirlA_Draw(Actor* thisx, PlayState* play) {
    EnGirlA* this = THIS;

    Matrix_RotateYS(this->rotY, MTXMODE_APPLY);
    if (this->drawFunc != NULL) {
        this->drawFunc(&this->actor, play, 0);
    }
    s16 getItemId = rando_get_item_id(LOCATION_SHOP_ITEM);
    if (shopObjectLoaded[this->actor.params]) {
        if (shopObjectStatic[this->actor.params]) {
            GetItem_Draw(play, getGid(getItemId));
        } else {
            GetItem_DrawDynamic(play, shopObjectSegments[this->actor.params], getGid(getItemId));
        }
    }
}

void EnGirlA_RandoBought(PlayState* play, EnGirlA* this) {
    this->isOutOfStock = true;
    this->actor.draw = NULL;
}

void EnGirlA_RandoRestock(PlayState* play, EnGirlA* this) {
    EnGirlA_RandoBought(play, this);
}

s32 EnGirlA_RandoCanBuyFunc(PlayState* play, EnGirlA* this) {
    if (gSaveContext.save.saveInfo.playerData.rupees < play->msgCtx.unk1206C) {
        return CANBUY_RESULT_NEED_RUPEES;
    }

    return CANBUY_RESULT_SUCCESS_2;
}

void EnGirlA_RandoBuyFunc(PlayState* play, EnGirlA* this) {
    rando_send_location(LOCATION_SHOP_ITEM);
}

// Fanfare is handled by the shopkeeper
void EnGirlA_RandoBuyFanfare(PlayState* play, EnGirlA* this) {
    Rupees_ChangeBy(-play->msgCtx.unk1206C);
}

RECOMP_PATCH void EnGirlA_InitItem(PlayState* play, EnGirlA* this) {
    shopObjectStatic[this->actor.params] = false;
    shopObjectLoading[this->actor.params] = false;
    shopObjectLoaded[this->actor.params] = false;

    // ShopItemEntry* shopItem = &sShopItemEntries[this->actor.params];

    this->actor.textId = 0x083F;
    // this->actor.textId = shopItem->descriptionTextId;
    this->isOutOfStock = false;
    this->actor.draw = EnGirlA_Draw;
    if (rando_location_is_checked(LOCATION_SHOP_ITEM)) {
        this->isOutOfStock = true;
        this->actor.draw = NULL;
    }
}

void EnGirlA_DoNothing(EnGirlA* this, PlayState* play);
void EnGirlA_Update2(EnGirlA* this, PlayState* play);
s32 EnGirlA_TrySetMaskItemDescription(EnGirlA* this, PlayState* play);
void EnGirlA_SetupAction(EnGirlA* this, EnGirlAActionFunc action);

RECOMP_PATCH void EnGirlA_InitalUpdate(EnGirlA* this, PlayState* play) {
    s16 params = this->actor.params;
    // ShopItemEntry* shopItem = &sShopItemEntries[params];
    s16 trueGI = rando_get_item(LOCATION_SHOP_ITEM);
    ShopItemEntry item = { getObjectId(trueGI), getGid(trueGI), NULL, 1, 0x083F, 0x0840, trueGI, EnGirlA_RandoCanBuyFunc,
      EnGirlA_RandoBuyFunc, EnGirlA_RandoBuyFanfare };
    ShopItemEntry* shopItem = &item;

    if (Object_IsLoaded(&play->objectCtx, this->objectSlot)) {
        this->actor.flags &= ~ACTOR_FLAG_10;
        this->actor.objectSlot = this->objectSlot;
        this->actor.textId = shopItem->descriptionTextId;
        this->choiceTextId = shopItem->choiceTextId;

        // EnGirlA_TrySetMaskItemDescription always returns false
        if (!EnGirlA_TrySetMaskItemDescription(this, play)) {
            EnGirlA_InitItem(play, this);
        }

        this->boughtFunc = EnGirlA_RandoBought;
        this->restockFunc = EnGirlA_RandoRestock;
        this->getItemId = shopItem->getItemId;
        this->canBuyFunc = shopItem->canBuyFunc;
        this->buyFunc = shopItem->buyFunc;
        this->buyFanfareFunc = shopItem->buyFanfareFunc;
        this->unk1C0 = 0;
        this->itemParams = shopItem->params;
        this->drawFunc = shopItem->drawFunc;
        this->getItemDrawId = shopItem->getItemDrawId;
        this->actor.flags &= ~ACTOR_FLAG_TARGETABLE;
        Actor_SetScale(&this->actor, 0.25f);
        this->actor.shape.yOffset = 24.0f;
        this->actor.shape.shadowScale = 4.0f;
        this->actor.floorHeight = this->actor.home.pos.y;
        this->actor.gravity = 0.0f;
        EnGirlA_SetupAction(this, EnGirlA_DoNothing);
        this->isInitialized = true;
        this->mainActionFunc = EnGirlA_Update2;
        this->isSelected = false;
        this->rotY = 0;
        this->initialRotY = this->actor.shape.rot.y;

        if (rando_location_is_checked(LOCATION_SHOP_ITEM)) {
            this->isOutOfStock = true;
            this->drawFunc = NULL;
        }
    }
}