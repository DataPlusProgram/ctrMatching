#include "../../common.h"

s16 VehCalc_InterpBySpeed();
void VehPhysForce_RotAxisAngle();
extern GameTracker *gT;

void VehStuckProc_Tumble_PhysAngular(Thread *thread, Driver *driver)
{
    s32 tempLo;
    GameTracker *gameState;
    u16 tempA0;
    u16 tempV0;
    u16 tempV1;
    u16 tempV1_2;

    tempV1 = driver->rotationSpinRate;
    tempA0 = driver->unkLerpToForwards;
    gameState = gT;

    driver->numFramesSpentSteering = 10000;

    tempV1 -= ((s32)(tempV1 << 0x10) >> 0x13);
    driver->rotationSpinRate = tempV1;

    tempA0 -= ((s32)(tempA0 << 0x10) >> 0x13);

    tempV0 = driver->turnAngleCurr;
    tempV1_2 = driver->rotationSpinRate;

    driver->unkLerpToForwards = tempA0;

    tempV0 += tempA0;
    tempV0 = (tempV0 + 0x800) & 0xFFF;

    tempA0 = driver->unk3D4[0];

    tempV0 -= 0x800;
    driver->ampTurnState = tempV1_2;

    tempLo = (s16)tempV1_2;
    driver->turnAngleCurr = tempV0;

    tempA0 -= ((s32)(tempA0 << 0x10) >> 0x13);
    driver->unk3D4[0] = tempA0;

    tempLo *= gameState->elapsedTimeMS;

    tempV0 = driver->angle;
    tempV0 = (tempV0 + (tempLo >> 0xD)) & 0xFFF;

    driver->angle = tempV0;
    driver->rotCurr[1] = driver->unk3D4[0] + (tempV0 + driver->turnAngleCurr);

    driver->rotCurr[3] = VehCalc_InterpBySpeed(
        driver->rotCurr[3],
        (gameState->elapsedTimeMS << 5) >> 5,
        0,
        tempLo
    );

    VehPhysForce_RotAxisAngle(&driver->matrixMovingDir, &driver->axisAngle1NormalVec.x, (s16)driver->angle);
}
