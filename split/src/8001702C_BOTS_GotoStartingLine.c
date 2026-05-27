#include "../../common.h"

extern s32 D_8008D698;
extern u8 D_8008D69C[];
extern u8 D_8008D680[];
extern void *D_8008DAE0[];
extern s32 D_8008CF80;
extern s32 D_8008D668;

void VehBirth_TeleportSelf(Driver *driver, s32 arg1, s32 arg2);
void BOTS_SetRotation(Driver *driver, s32 arg1);
s32 RngDeadCoed(void *arg0);

void FUN_8001702c(Driver *driver)
{
    u8 spawnOrder;
    s32 posX;
    s32 posY;
    s32 posZ;
    void *navFrame;
    s32 pathIndex;
    s32 randomValue;
    s32 rotation;
    s32 flags;
    s32 accelValue;
    s32 accelIndex;
    u8 *accelPtr;

    D_8008D698 = 0;
    VehBirth_TeleportSelf(driver, 3, 0);

    spawnOrder = driver->driverId;
    posZ = driver->posCurr.z;
    accelIndex = D_8008D69C[spawnOrder];
    posX = driver->posCurr.x;
    posY = driver->posCurr.y;

    driver->botData.aiPosBackup[2] = posZ;
    driver->botData.aiVelAxis[2] = 0;
    driver->botData.aiVelAxis[1] = 0;
    driver->botData.aiVelAxis[0] = 0;
    driver->botData.aiAccelAxis[2] = 0;
    driver->botData.aiAccelAxis[1] = 0;
    driver->botData.aiAccelAxis[0] = 0;
    driver->botData.aiSpeedLinear = 0;
    driver->botData.aiSpeedY = 0;
    driver->botData.unk5CC = 0;
    driver->botData.aiPosBackup[1] = posY;
    driver->botData.aiPosBackup[0] = posX;

    pathIndex = driver->botData.botPath;
    navFrame = D_8008DAE0[pathIndex];
    driver->botData.unk5A8 = 0;
    driver->botData.botNavFrame = navFrame;

    BOTS_SetRotation(driver, 1);

    accelPtr = &D_8008D680[accelIndex];
    spawnOrder = *accelPtr;
    accelValue = D_8008CF80 * spawnOrder;

    driver->rotCurr[2] = 0;
    driver->rotPrev[2] = 0;
    driver->botData.aiRot4[2] = 0;
    driver->rotCurr[0] = 0;
    driver->rotPrev[0] = 0;
    driver->botData.aiRot4[0] = 0;

    flags = driver->actionsFlagSet;
    rotation = driver->botData.estimateRotNav[1] << 4;

    driver->turnAngleCurr = 0;
    driver->actionsFlagSet = flags | 0x100000;

    driver->botData.aiRotY608 = rotation;
    driver->angle = rotation;
    driver->rotCurr[1] = rotation;
    driver->rotPrev[1] = rotation;
    driver->botData.aiRot4[1] = rotation;

    driver->botData.botAccel = accelValue;

    randomValue = RngDeadCoed(&D_8008D668);
    randomValue = (randomValue >> 8) & 0xFF;
    driver->botData.weaponCooldown = randomValue + 300;
}
