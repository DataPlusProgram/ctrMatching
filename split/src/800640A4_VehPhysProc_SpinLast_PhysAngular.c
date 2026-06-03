#include "../../common.h"

M2C_UNK VehPhysForce_RotAxisAngle(); /* extern */

void VehPhysProc_SpinLast_PhysAngular(Thread *thread, Driver *driver)
{
    s32 rotVel;
    s16 rot;
    s32 tempLo;
    s32 temp;
    s32 posRot;
    s32 rotAxis;
    u16 spinRot;

    rotAxis = (u16)driver->rotationSpinRate;
    posRot = (u16)driver->unk3D4[0];
    rotVel = driver->turnAngleCurr;

    driver->numFramesSpentSteering = 0x2710;

    rotAxis = rotAxis - ((s32)(rotAxis << 0x10) >> 0x13);
    posRot = posRot - ((s32)(posRot << 0x10) >> 0x13);

    driver->rotationSpinRate = rotAxis;
    driver->unk3D4[0] = posRot;
    driver->ampTurnState = rotAxis;

    if (rotVel > 0) {
        if ((driver->kartStates.spinning.driftSpinRate < 0) && (rotVel < 0x190)) {
            temp = (s32)-(rotVel * 4) >> 3;
            driver->kartStates.spinning.driftSpinRate = temp;

            if (temp >= -0x1F) {
                driver->kartStates.spinning.driftSpinRate = -0x20;
            }
        }

        rot = (((u16)driver->turnAngleCurr + (u16)driver->kartStates.spinning.driftSpinRate + 0x800) & 0xFFF) - 0x800;
        driver->turnAngleCurr = rot;

        if ((driver->kartStates.spinning.driftSpinRate < 0) && ((rot << 0x10) < 0)) {
            driver->turnAngleCurr = 0;
        }
    } else if (rotVel < 0) {
        if ((driver->kartStates.spinning.driftSpinRate > 0) && (rotVel >= -0x18F)) {
            temp = (s32)-(rotVel * 4) >> 3;
            driver->kartStates.spinning.driftSpinRate = temp;

            if (temp < 0x20) {
                driver->kartStates.spinning.driftSpinRate = 0x20;
            }
        }

        rot = ((driver->turnAngleCurr + driver->kartStates.spinning.driftSpinRate + 0x800) & 0xFFF) - 0x800;
        driver->turnAngleCurr = rot;

        if ((driver->kartStates.spinning.driftSpinRate > 0) && ((rot << 0x10) > 0)) {
            driver->turnAngleCurr = 0;
        }
    }

    tempLo = (s16)driver->ampTurnState * gT->elapsedTimeMS;
    spinRot = (driver->angle + (tempLo >> 0xD)) & 0xFFF;

    driver->angle = spinRot;
    driver->rotCurr[1] = driver->unk3D4[0] + (spinRot + (u16)driver->turnAngleCurr);

    driver->rotCurr[3] = VehCalc_InterpBySpeed(
        driver->rotCurr[3],
        (s32)(gT->elapsedTimeMS << 5) >> 5,
        0
    );

    VehPhysForce_RotAxisAngle(&driver->matrixMovingDir, &driver->axisAngle1NormalVec.x, driver->angle);
}
