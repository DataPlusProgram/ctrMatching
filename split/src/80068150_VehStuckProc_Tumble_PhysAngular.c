#include "../../common.h"

s32 VehCalc_InterpBySpeed();
void VehPhysForce_RotAxisAngle();

void VehStuckProc_Tumble_PhysAngular(Thread *thread, Driver *driver)
{
    s32 spinAngleDelta;
    GameTracker *gameState;
    u16 lerpToForwards;
    u16 angle;
    u16 spinRate;
    u16 decayedSpinRate;

    spinRate = driver->rotationSpinRate;
    spinRate -= ((s32)(spinRate << 0x10) >> 0x13);
    driver->rotationSpinRate = spinRate;

    lerpToForwards = driver->unkLerpToForwards;
    gameState = gT;

    driver->numFramesSpentSteering = 10000;

    lerpToForwards -= ((s32)(lerpToForwards << 0x10) >> 0x13);

    angle = driver->turnAngleCurr;
    decayedSpinRate = driver->rotationSpinRate;

    driver->unkLerpToForwards = lerpToForwards;

    angle += lerpToForwards;
    angle = (angle + 0x800) & 0xFFF;

    lerpToForwards = driver->unk3D4[0];

    angle -= 0x800;
    driver->ampTurnState = decayedSpinRate;

    spinAngleDelta = (s16)decayedSpinRate;
    driver->turnAngleCurr = angle;

    lerpToForwards -= ((s32)(lerpToForwards << 0x10) >> 0x13);
    driver->unk3D4[0] = lerpToForwards;

    spinAngleDelta *= gameState->elapsedTimeMS;

    angle = driver->angle;
    angle = (angle + (spinAngleDelta >> 0xD)) & 0xFFF;

    driver->angle = angle;
    driver->rotCurr[1] = driver->unk3D4[0] + (angle + driver->turnAngleCurr);

    driver->rotCurr[3] = VehCalc_InterpBySpeed(
        driver->rotCurr[3],
        (gameState->elapsedTimeMS << 5) >> 5,
        0
    );

    VehPhysForce_RotAxisAngle(&driver->matrixMovingDir,&driver->axisAngle1NormalVec.x,(s16)driver->angle);
}