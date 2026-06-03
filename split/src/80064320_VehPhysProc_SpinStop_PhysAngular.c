#include "../../common.h"

s32 VehCalc_InterpBySpeed();          /* extern */
M2C_UNK VehPhysForce_RotAxisAngle();  /* extern */

void VehPhysProc_SpinStop_PhysAngular(Thread *thread, Driver *driver)
{
    s32 tempLo;
    u16 tempV0;

    (void)thread;

    tempLo = driver->ampTurnState * gT->elapsedTimeMS;

    tempV0 = (driver->angle + (tempLo >> 0xD)) & 0xFFF;
    driver->angle = tempV0;

    driver->rotCurr[1] =
        driver->unk3D4[0] + (tempV0 + driver->turnAngleCurr);

    driver->rotCurr[3] =
        VehCalc_InterpBySpeed(
            driver->rotCurr[3],
            (gT->elapsedTimeMS << 5) >> 5,
            0
        );

    driver->turnAngleCurr =
        VehCalc_InterpBySpeed(
            driver->turnAngleCurr,
            (gT->elapsedTimeMS << 7) >> 5,
            0
        );

    VehPhysForce_RotAxisAngle(
        &driver->matrixMovingDir,
        &driver->axisAngle1NormalVec.x,
        driver->angle
    );
}
