#include "../../common.h"

typedef struct
{
    u8 pad[0x2D4];
    Vec3 posCurr;
} DriverPosCurrView;
typedef struct
{
    u8 flags;
    u8 pad01[0x1C - 0x01];
    void *levInstData;
} HitInstanceView;
typedef struct
{
    u8 pad00[0x2C];
    s32 modelData;
    u8 pad30[0x3C - 0x30];
    s16 modelId;
} LevInstDataView;

M2C_UNK COLL_FIXED_BotsSearch();
LevModelMetaView *COLL_LevModelMeta(unsigned int arg0);
extern GameTracker *gT;

typedef struct
{
    s16 x;
    s16 y;
    s16 z;
} Vec3s;

void BOTS_LevInstColl(Thread *arg0)
{
    Vec3s sp10;
    Vec3s sp18;
    M2C_UNK (*collisionFunc)(s32, void *, M2C_UNK);
    s32 modelData;
    s32 temp_model;
    LevInstDataView *levInstData;
    LevModelMetaView *levModelMeta;
    DriverPosCurrView *driver;
    HitInstanceView *hitInstance;
    BotsLevInstCollScratch *scratch;
    void *temp_modelPtr;

    scratch = (BotsLevInstCollScratch *)0x1F800108;
    temp_modelPtr = M2C_FIELD(gT, void **, 0x160);
    driver = M2C_FIELD(arg0, DriverPosCurrView **, 0x30);
    temp_model = *(s32 *)temp_modelPtr;

    scratch->collisionFlags = 1;
    scratch->unk0C = 0x3F;
    scratch->unk24 = 0;
    scratch->unk28 = 0;
    scratch->bboxRadius = 0x19;
    scratch->levelRootValue = temp_model;

    /* Confirmed driver position fields, kept as offset reads for matching. */
    sp10.x =  M2C_FIELD(driver, s32 *, 0x2D4) >> 8;
    sp10.y = (M2C_FIELD(driver, s32 *, 0x2D8) >> 8) + 0x19;
    sp10.z = M2C_FIELD(driver, s32 *, 0x2DC) >> 8;

    sp18.x =  M2C_FIELD(driver, s32 *, 0x2E0) >> 8;
    sp18.y = ( M2C_FIELD(driver, s32 *, 0x2E4) >> 8) + 0x19;
    sp18.z =   M2C_FIELD(driver, s32 *, 0x2E8) >> 8;

    COLL_FIXED_BotsSearch(&sp10, &sp18, scratch);

    if (scratch->foundHitType != 0)
    {
        hitInstance = scratch->hitInstance;
        scratch->collisionFlags &= 0xFFF7;
        if (hitInstance->flags & 0x80)
        {
            levInstData = hitInstance->levInstData;
            modelData = levInstData->modelData;
            if (modelData != 0)
            {
                levModelMeta = COLL_LevModelMeta(levInstData->modelId);
                if (levModelMeta != NULL)
                {
                    collisionFunc = levModelMeta->collisionFunc;
                    if (collisionFunc != NULL)
                    {
                        collisionFunc(modelData, arg0, scratch);
                    }
                }
            }
        }
    }
}
