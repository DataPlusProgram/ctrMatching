#include "../../common.h"

extern GameTracker *gT;
extern s16 D_80086E84[];

Terrain *VehAfterColl_GetTerrain(s32 terrainId);

void VehBirth_TireSprites(Thread *thread)
{
    Driver *driver;

    driver = thread->object;
    driver->wheelSprites = (Icon **)((s8 *)M2C_FIELD(gT, void **, 0x2114) + 0x14);

    driver->wheelSize = 0xCCC;

    if ((D_80086E84[driver->driverId] == 0xF) &&
        (gT->levelID != 0x27))
    {
        driver->wheelSize = 0;
    }

    driver->tireColor = 0x2E808080;
    driver->unkSpeedValue1 = 0xA00;
    driver->heldItemId = 0xF;
    driver->unk47B = 2;
    driver->axisAngle1NormalVec.y = 0x1000;
    driver->axisAngle2NormalVec[1] = 0x1000;
    driver->unk412 = 0x600;
    driver->numFramesSpentSteering = 10000;
    driver->terrainMeta1 = VehAfterColl_GetTerrain(0xA);
    driver->battleHud.numLives = gT->battleLifeLimit;
    driver->battleHud.teamId = driver->driverId;
    driver->quip1 = -1;
    driver->quip3 = -1;
}
