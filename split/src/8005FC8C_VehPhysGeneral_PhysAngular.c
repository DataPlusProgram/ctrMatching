#include "../../common.h"

s32 VehCalc_MapToRange(s32 value, s32 inMin, s32 inMax, s32 outMin, s32 outMax);     /* extern */
s32 VehCalc_SteerAccel();     /* extern */
void VehPhysForce_RotAxisAngle(); /* extern */

void VehPhysGeneral_PhysAngular(Thread *thread, Driver *driver)
{
    s32 isNegative;
    s32 clampHit;
    s16 interpValue;
    s16 tempS16;
    s32 temp0;
    s32 temp1;
    s32 temp2;
    s32 tempU32;
    s32 temp3;
    s32 temp4;
    s32 temp5;
    s32 temp6;
    s32 temp7;
    s32 temp8;
    s16 tempS16_2;
    s32 temp9;
    s32 temp10;
    u32 actionsFlagSet;
    Terrain *terrain;
    s32 elapsedTime;

    (void)thread;

    temp5 = driver->rotCurr[3];
    temp0 = temp5;
    if (temp5 < 0) {
        temp0 = -temp5;
    }

    elapsedTime = gT->elapsedTimeMS;

    tempU32 = temp0 >> 3;
    if (tempU32 == 0) {
        tempU32 = 1;
    }

    temp1 = (u8)driver->unk46A;
    if (temp1 < tempU32) {
        tempU32 = temp1;
    }

    temp0 = VehCalc_InterpBySpeed(driver->rotPrev[3], 8, tempU32);
    driver->rotPrev[3] = temp0;

    interpValue = VehCalc_InterpBySpeed(temp5, (temp0 * elapsedTime) >> 5, 0);
    actionsFlagSet = driver->actionsFlagSet;
    temp1 = driver->forwardDir;
    tempS16 = temp1;
    driver->rotCurr[3] = interpValue;

    temp5 = driver->speedApprox;
    temp0 = driver->simpTurnState * 0x100;

    if (temp5 < 1) {
        if (driver->baseSpeed < 0) {
            temp1 = -1;
            tempS16 = -1;
            driver->forwardDir = -1;
        }

        if (temp5 >= 0) {
            goto checkForwardDir;
        }
    } else {
checkForwardDir:
        if (driver->baseSpeed >= 0) {
            temp1 = 1;
            tempS16 = 1;
            driver->forwardDir = 1;
        }
    }

    if (temp1 < 0) {
        temp0 = -temp0;
        actionsFlagSet ^= 0x10;
    }

    if (temp5 < 0) {
        temp5 = -temp5;
    }

    if (((actionsFlagSet & 1) != 0) && ((driver->stepFlagSet & 3) == 0)) {
        temp0 = VehCalc_MapToRange(temp5, 0x10, 0x300, 0, temp0);
    }

    terrain = driver->terrainMeta1;
    temp2 = driver->rotationSpinRate;

    if (temp0 == 0) {
        tempS16 = VehCalc_InterpBySpeed(
            temp2,
            ((driver->constTurnInputDelay + (driver->turnConst * 0x32)) * M2C_FIELD(terrain, s32 *, 0x28)) >> 8,
            0
        );
    } else {
        isNegative = 0;
        if (temp0 < 0) {
            temp0 = -temp0;
            temp2 = -temp2;
            isNegative = 1;
        }

        if (temp2 < temp0) {
            temp2 += ((driver->constTurnInputDelay + (driver->turnConst * 100)) * M2C_FIELD(terrain, s32 *, 0x28)) >> 8;
            clampHit = temp0 < temp2;
checkClamp:
            if (clampHit) {
                temp2 = temp0;
            }
        } else if (temp0 < temp2) {
            temp2 -= ((driver->constTurnInputDelay + (driver->turnConst * 0x32)) * M2C_FIELD(terrain, s32 *, 0x28)) >> 8;
            clampHit = temp2 < temp0;
            goto checkClamp;
        }

        tempS16 = (s16)temp2;
        if (isNegative) {
            tempS16 = -tempS16;
        }
    }

    temp0 = driver->timeUntilDriftSpinout;
    temp2 = tempS16;
    driver->rotationSpinRate = tempS16;

    if (temp0 != 0) {
        temp6 = temp0 - elapsedTime;
        temp0 = VehCalc_MapToRange(temp0, 0, 0x140, 0, M2C_FIELD(driver, s16 *, 0x3EA));
        temp2 += temp0;

        if (temp6 < 0) {
            temp6 = 0;
        }

        driver->timeUntilDriftSpinout = temp6;
    }

    temp3 = ((u32)(u16)driver->constSpeedClassStat) << 0x10;
    temp6 = temp3 >> 0x10;
    temp0 = ((u8)driver->constTurnResistMax) * temp6;
    temp6 = ((u8)driver->constTurnResistMin) * temp6;
    tempS16 = driver->unkLerpToForwards;
    temp10 = driver->unk450;
    temp9 = temp0 >> 8;
    temp7 = temp6 >> 8;

    if ((actionsFlagSet & 0x20) != 0) {
        temp9 = temp0 >> 9;
        if (temp5 > 0x300) {
            driver->actionsFlagSet |= 0x800;
        }

        temp7 = temp6 >> 9;
        if (driver->baseSpeed == 0) {
            temp10 = driver->constModelRotVelMin;
        } else {
            temp0 = driver->speed;
            if (temp0 < 0) {
                temp0 = -temp0;
            }

            temp10 = VehCalc_MapToRange(temp0, 0x300, temp3 >> 0x11, driver->constModelRotVelMin, driver->constModelRotVelMax);
        }
    }

    temp0 = driver->speed;
    if (temp0 < 0) {
        temp0 = -temp0;
    }

    temp3 = (((u32)driver->constTurnRate + ((driver->turnConst << 1) / 5)) * 0x100);
    temp6 = VehCalc_MapToRange(temp0, temp7, temp9, temp3, 0);
    temp0 = 0;

    if (temp7 <= temp5) {
        temp8 = temp2;
        if (temp2 < 0) {
            temp8 = -temp2;
        }

        if (temp6 < temp8) {
            temp0 = driver->fireSpeed;
            if (temp0 < 0) {
                temp0 = -temp0;
            }

            VehCalc_MapToRange(temp0, temp7, temp9, 0, 0);
            temp0 = VehCalc_MapToRange(temp8, temp6, temp3, 0, 0);

            if (temp2 < 0) {
                temp0 = -temp0;
            }
        }
    }

    tempS16_2 = driver->turnAngleCurr;
    tempS16 = VehPhysGeneral_LerpToForwards(driver, tempS16_2, tempS16, temp0);
    driver->unkLerpToForwards = tempS16;
    temp0 = tempS16;

    if (M2C_FIELD(terrain, s32 *, 0x24) != 0x100) {
        temp0 = (M2C_FIELD(terrain, s32 *, 0x24) * temp0) >> 8;
    }

    temp3 = tempS16_2 + ((temp0 * elapsedTime) >> 5);
    driver->turnAngleCurr = (s16)temp3;

    temp6 = temp2;
    if ((temp5 > 0x2FF) && ((actionsFlagSet & 1) != 0)) {
        tempS16_2 = driver->numFramesSpentSteering;
        temp8 = VehCalc_SteerAccel(
            tempS16_2,
            driver->constSteerAccelStage2FirstFrame,
            driver->constSteerAccelStage2FrameLength,
            driver->constSteerAccelStage4FirstFrame
        );

        if (temp2 < 0) {
            temp6 = -temp2;
        }

        temp6 = (driver->unk44E * temp6) >> 8;
        driver->numFramesSpentSteering = tempS16_2 + 1;

        if (temp6 < temp8) {
            temp8 = temp6;
        }

        if ((actionsFlagSet & 0x10) != 0) {
            temp8 = -temp8;
        }

        temp9 = driver->unk450;
        if ((temp2 < 1) || (-temp9 <= temp2 + temp8)) {
            if (temp2 < 0) {
                temp9 = temp2 + temp8;
                if (driver->unk450 < temp2 + temp8) {
                    temp9 = driver->unk450;
                }
            } else {
                temp9 = temp2 + temp8;
            }
        } else {
            temp9 = -temp9;
        }

        temp6 = temp9;
    }

    temp8 = M2C_FIELD(driver, s16 *, 0x3D4);
    tempS16 = M2C_FIELD(driver, s16 *, 0x3D8);
    temp2 = M2C_FIELD(driver, s16 *, 0x3D6);

    if (((terrain->flags & 0x10) == 0) && ((actionsFlagSet & 1) != 0)) {
        temp9 = temp3;
        if (temp3 < 0) {
            temp9 = -temp3;
        }

        if ((temp10 * 3 >> 2) < temp9) {
            temp10 = temp0;
            if (temp0 < 0) {
                temp10 = -temp0;
            }

            if (temp10 < 3) {
                temp10 = temp8;
                if (temp8 < 0) {
                    temp10 = -temp8;
                }

                if (temp10 < 10) {
                    tempS16 = 8;
                    temp2 = 0x14;
                    if (temp3 < 0) {
                        temp2 = -0x14;
                    }
                }
            }

            goto keepShake;
        }
    }

    tempS16 = 0;
keepShake:
    temp10 = temp8;
    if (temp8 < 0) {
        temp10 = -temp8;
    }

    if (temp10 > 0x32) {
        tempS16 = 0;
    }

    if (tempS16 == 0) {
        temp2 = 10;
        if (temp8 > 0) {
            temp2 = -10;
        }

        temp10 = temp2;
        if (temp2 < 0) {
            temp10 = -temp2;
        }

        tempS16_2 = VehCalc_InterpBySpeed(temp8, temp10, 0);
        tempS16 = 0;
    } else {
        tempS16--;
        tempS16_2 = temp8 + temp2;
    }

    tempU32 = (u16)driver->angle;
    M2C_FIELD(driver, s16 *, 0x3D8) = tempS16;
    M2C_FIELD(driver, s16 *, 0x3D4) = tempS16_2;
    M2C_FIELD(driver, s16 *, 0x3D6) = (s16)temp2;

    temp0 = VehCalc_MapToRange(temp5, 0, 0x600, temp0, 0);
    temp5 = (temp0 * elapsedTime) >> 5;
    temp0 = temp5;
    if (temp5 < 0) {
        temp0 = -temp5;
    }

    if (temp0 > 1) {
        tempU32 = (tempU32 - temp5) & 0xFFF;
    }

    driver->ampTurnState = (s16)temp6;
    tempU32 = (tempU32 + ((temp6 * elapsedTime) >> 0xD)) & 0xFFF;
    tempS16 = (s16)tempU32;
    driver->angle = tempS16;
    driver->rotCurr[1] = tempS16 + (s16)temp3 + tempS16_2;

    if ((actionsFlagSet & 8) != 0) {
        goto scaleTurnSmall;
    }

    if (driver->mashXUnknown < 7) {
        goto scaleTurnTerrain;
    }

scaleTurnSmall:
    temp6 = (temp6 * 10) >> 8;
    goto afterTurnScale;

scaleTurnTerrain:
    temp0 = M2C_FIELD(terrain, s32 *, 0x14);
    if (temp0 != 0x100) {
        temp6 = (temp6 * temp0) >> 8;
    }

afterTurnScale:
    driver->axisRotationX = (driver->axisRotationX + ((temp6 * elapsedTime) >> 0xD)) & 0xFFF;
    VehPhysForce_RotAxisAngle(&driver->matrixMovingDir, &driver->axisAngle1NormalVec.x, tempU32);
    gte_SetRotMatrix(&driver->matrixMovingDir);
    VehPhysForce_CounterSteer(driver);
}
