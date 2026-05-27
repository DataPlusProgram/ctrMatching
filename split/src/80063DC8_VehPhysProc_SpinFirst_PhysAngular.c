#include "../../common.h"

s16 VehCalc_InterpBySpeed();         /* extern */
M2C_UNK VehPhysForce_RotAxisAngle(); /* extern */
extern GameTracker *gT;

void VehPhysProc_SpinFirst_PhysAngular(Thread *thread, Driver *driver) {
    s32 tempLo;
    u16 tempA0;
    u16 tempA0_2;
    u16 tempV0;
    u16 tempV1;
    volatile u16 *spinVel;

    spinVel = (volatile u16 *)&driver->rotationSpinRate;

    tempA0 = *spinVel;
    driver->numFramesSpentSteering = 0x2710;

    tempV0 = driver->turnAngleCurr;
    tempV1 = driver->kartStates.spinning.driftSpinRate;

    tempA0 = tempA0 - ((s32)(tempA0 << 0x10) >> 0x13);
    tempV0 = (tempV0 + tempV1 + 0x800) & 0xFFF;

    *spinVel = tempA0;

    tempA0_2 = driver->unk3D4[0];
    tempV1 = driver->rotationSpinRate;

    driver->turnAngleCurr = tempV0 - 0x800;

    tempA0_2 = tempA0_2 - ((s32)(tempA0_2 << 0x10) >> 0x13);
    driver->ampTurnState = tempV1;
    driver->unk3D4[0] = tempA0_2;

    tempLo = (s16)tempV1 * M2C_FIELD(gT, s32 *, 0x1D04);

    tempV0 = (driver->angle + (tempLo >> 0xD)) & 0xFFF;
    driver->angle = tempV0;

    driver->rotCurr[1] =
        driver->unk3D4[0] + (tempV0 + driver->turnAngleCurr);

    driver->rotCurr[3] =
        VehCalc_InterpBySpeed(
            driver->rotCurr[3],
            (M2C_FIELD(gT, s32 *, 0x1D04) << 5) >> 5,
            0,
            tempLo
        );

    VehPhysForce_RotAxisAngle(
        &driver->matrixMovingDir,
        &driver->axisAngle1NormalVec.x,
        driver->angle
    );
}
