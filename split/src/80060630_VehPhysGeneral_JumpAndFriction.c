#include "../../common.h"

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK GAMEPAD_ShockForce1();       /* extern */
M2C_UNK GAMEPAD_ShockFreq();         /* extern */
M2C_UNK OtherFX_Play();              /* extern */
M2C_UNK OtherFX_Play_Echo();         /* extern */
s32 VehCalc_MapToRange();            /* extern */
M2C_UNK VehPhysCrash_ConvertVecToSpeed(); /* extern */

extern void *gGamepads;

void VehPhysGeneral_JumpAndFriction(Thread *thread, Driver *driver) {
    Vec3 movement;
    s32 accelMagnitude;
    s32 absAmpTurnState;
    s32 absBaseSpeed;
    s32 absSpeedApprox;
    s32 jumpMaxNormalVelY;
    s32 jumpPeakVelY;
    s32 jumpSpeedCap;
    s32 quadMulNormVecY;
    s32 speedScale;
    s32 terrainSlowUntilSpeed;
    s16 baseSpeedDelta;
    s16 baseSpeedMagnitude;
    s16 interpSpeed;
    s16 jumpSpeed;
    s16 speedApprox;
    u32 speedLoss;
    s16 *jumpNormalVec;
    u32 *matrixMovingDirWords;

    thread = thread;

    matrixMovingDirWords = (u32 *)&driver->matrixMovingDir;
    {
        u32 mat0;
        u32 mat1;
        u32 mat2;
        u32 mat3;
        u32 mat4;

        mat0 = matrixMovingDirWords[0];
		
        mat1 = matrixMovingDirWords[1];
		gte_ldR11R12(mat0);
		gte_ldR13R21(mat1);
        mat2 = matrixMovingDirWords[2];
        mat3 = matrixMovingDirWords[3];
        mat4 = matrixMovingDirWords[4];


        gte_ldR22R23(mat2);
        gte_ldR31R32(mat3);
        gte_ldR33(mat4);
    }

    if ((driver->kartState != 2) && !(driver->actionsFlagSet & 0x800000) && (driver->reserves == 0)) {
        absAmpTurnState = driver->ampTurnState >> 8;
        if (absAmpTurnState < 0) {
            absAmpTurnState = -absAmpTurnState;
        }

        baseSpeedDelta = VehCalc_MapToRange(absAmpTurnState, 0, (u8) driver->constBackwardTurnRate, 0, (s32) driver->constTurnDecreaseRate);
        baseSpeedMagnitude = driver->baseSpeed;
        absBaseSpeed = baseSpeedMagnitude;

        if (absBaseSpeed < 0) {
            absBaseSpeed = -absBaseSpeed;
        }

        if (absBaseSpeed < baseSpeedDelta) {
            baseSpeedDelta = (s16) absBaseSpeed;
        }

        if (baseSpeedMagnitude < 0) {
            driver->baseSpeed = driver->baseSpeed + baseSpeedDelta;
        } else {
            driver->baseSpeed = driver->baseSpeed - baseSpeedDelta;
        }
    }

    if (driver->set0xF0OnWallRub != 0) {
        if (driver->baseSpeed > driver->scrubMeta8) {
            driver->baseSpeed = driver->scrubMeta8;
        }

        if (driver->baseSpeed < -driver->scrubMeta8) {
            driver->baseSpeed = -driver->scrubMeta8;
        }
    }

    movement.x = driver->velocity.x;
    movement.y = driver->velocity.y;
    movement.z = driver->velocity.z;
    speedLoss = 0;

    if (driver->actionsFlagSet & 1) {
        if (((driver->stepFlagSet & 3) == 0) || (driver->baseSpeed < 1)) {
            if (driver->baseSpeed != 0) {
                if ((((driver->terrainMeta1->flags & 4) == 0) || (driver->baseSpeed < 1)) || (-1 < driver->speedApprox)) {
                    speedApprox = driver->speedApprox;
                    absSpeedApprox = speedApprox;

                    if (absSpeedApprox < 0) {
                        absSpeedApprox = -absSpeedApprox;
                    }

                    if ((0x2FF < absSpeedApprox) && ((driver->baseSpeed < 1) || (speedApprox < 1)) && ((-1 < driver->baseSpeed) || (-1 < speedApprox))) {
                        goto processAccel;
                    }
                }

                accelMagnitude = driver->constAccelClassStat + ((driver->accelConst << 5) / 5);

                if ((driver->stepFlagSet & 3) == 0) {
                    if ((driver->reserves != 0) && (0 < driver->baseSpeed)) {
                        accelMagnitude = driver->constAccelReserves;
                    }

                    terrainSlowUntilSpeed = driver->terrainMeta1->slowUntilSpeed;
                    if ((terrainSlowUntilSpeed != 0x100) && ((driver->actionsFlagSet & 0x800000) == 0)) {
                        accelMagnitude = (terrainSlowUntilSpeed * accelMagnitude) >> 8;
                    }
                } else if (0 < driver->baseSpeed) {
                    accelMagnitude = 0x1F40;
                }
            }
        } else {
            accelMagnitude = 0x1F40;
        }

    processAccel:
        speedScale = (accelMagnitude * M2C_FIELD(gGamepads, s32 *, 0x1D04)) >> 5;
        gte_ldVXY0(0);
        gte_ldVZ0(speedScale & 0xFFFF);
        gte_rtv0();

        {
            s32 tempX;
            s32 tempY;
            s32 tempZ;

            read_mt(tempX, tempY, tempZ);

            if (driver->baseSpeed < 0) {
                driver->unk3B2 = (s16) -speedScale;
                movement.x -= tempX;
                movement.y -= tempY;
                movement.z -= tempZ;
                driver->unkVectorX = (s16) -tempX;
                driver->unkVectorY = (s16) -tempY;
                driver->unkVectorZ = (s16) -tempZ;
            } else {
                driver->unk3B2 = (s16) speedScale;
                movement.x += tempX;
                movement.y += tempY;
                movement.z += tempZ;
                driver->unkVectorX = (s16) tempX;
                driver->unkVectorY = (s16) tempY;
                driver->unkVectorZ = (s16) tempZ;
            }
        }

        speedLoss = VehCalc_FastSqrt((movement.x * movement.x) + (movement.y * movement.y) + (movement.z * movement.z), 0x10) >> 8;
        absBaseSpeed = driver->baseSpeed;

        if (absBaseSpeed < 0) {
            absBaseSpeed = -absBaseSpeed;
        }

        speedLoss -= absBaseSpeed;

        if ((s32) speedLoss < 0) {
            speedLoss = 0;
        }

        if ((s32) speedScale < (s32) speedLoss) {
            speedLoss = speedScale;
        }

        if (((driver->actionsFlagSet & 1) != 0) && (driver->jumpForcedMs != 0)) {
            if (driver->jumpUnknown != 0) {
                driver->jumpUnknown = 0x180;
            }

            if (driver->kartState == 6) {
                GAMEPAD_ShockFreq(driver, 8, 0);
                GAMEPAD_ShockForce1(driver, 8, 0x7F);
            }

            goto applyJump;
        }

    }

    if ((driver->actionsFlagSet & 0x8000) && (driver->heldItemId == 5)) {
        driver->actionsFlagSet &= 0xFFFF7FFF;

        if ((driver->jumpCoyoteTimerMs != 0) && (driver->jumpCooldownMs == 0)) {
            driver->jumpForcedMs = 0xA0;
            jumpPeakVelY = driver->constJumpForce * 9;

            if (jumpPeakVelY < 0) {
                jumpPeakVelY += 3;
            }

            driver->jumpInitialVelY = (s16) (jumpPeakVelY >> 2);
            OtherFX_Play_Echo(9, 1, M2C_FIELD(driver, u16 *, 0x2CA) & 1);
            driver->jumpUnknown = 0x180;
            goto applyJump;
        }

        driver->noItemTimer = 0;
    }

    if (driver->forcedJumpTrampoline != 0) {
        if ((driver->jumpForcedMs == 0) || (driver->jumpInitialVelY == driver->constJumpForce)) {
            OtherFX_Play(0x7E, 1);
        }

        driver->jumpForcedMs = 0xA0;

        if (driver->forcedJumpTrampoline == 2) {
            driver->jumpUnknown = 0x180;
            driver->jumpInitialVelY =  (driver->constJumpForce * 3);
        } else {
            driver->jumpInitialVelY =  ((driver->constJumpForce * 3) / 2);
        }

        driver->forcedJumpTrampoline = 0;
    } else {
        if ((driver->jumpCoyoteTimerMs == 0) || (driver->jumpTenBuffer == 0) || (driver->jumpCooldownMs != 0)) {
            goto finishMovement;
        }

        driver->jumpForcedMs = 0xA0;
        driver->numberOfJumps = (u16) (driver->numberOfJumps + 1);
        driver->jumpInitialVelY = driver->constJumpForce;
        OtherFX_Play_Echo(8, 1, M2C_FIELD(driver, u16 *, 0x2CA) & 1);
    }

applyJump:
    jumpPeakVelY = 0;
    jumpMaxNormalVelY = 0;
    terrainSlowUntilSpeed = 0x378;
    driver->jumpCooldownMs = 0x180;
    driver->jumpTenBuffer = 0;
    driver->actionsFlagSet |= 0x480;

    do {
        absSpeedApprox = VehPhysGeneral_JumpGetVelY((s8 *)driver + terrainSlowUntilSpeed, &movement);
        accelMagnitude = absSpeedApprox;

        if (accelMagnitude < 0) {
            accelMagnitude = -accelMagnitude;
        }

        speedScale = jumpPeakVelY;

        if (speedScale < 0) {
            speedScale = -speedScale;
        }

        if (speedScale < accelMagnitude) {
            jumpPeakVelY = absSpeedApprox;
        }

        jumpMaxNormalVelY++;
        terrainSlowUntilSpeed += 8;
    } while (jumpMaxNormalVelY <= 0);

    jumpNormalVec = &driver->axisAngle1NormalVec;

    if ((driver->actionsFlagSet & 1) == 0) {
        jumpNormalVec = &driver->axisAngle2NormalVec;
    }

    accelMagnitude = VehPhysGeneral_JumpGetVelY(jumpNormalVec, &movement);
    absSpeedApprox = accelMagnitude;

    if (absSpeedApprox < 0) {
        absSpeedApprox = -absSpeedApprox;
    }

    speedScale = jumpPeakVelY;

    if (speedScale < 0) {
        speedScale = -speedScale;
    }

    if (speedScale < absSpeedApprox) {
        jumpPeakVelY = accelMagnitude;
        speedScale = absSpeedApprox;
    }

    jumpSpeed = driver->jumpInitialVelY;
    jumpSpeedCap = VehCalc_FastSqrt(((jumpPeakVelY * jumpPeakVelY) + (jumpSpeed * jumpSpeed)) >> 8, 8) - jumpPeakVelY;
    quadMulNormVecY = M2C_FIELD(M2C_FIELD(gGamepads, void **, 0x160), u8 *, 0x18C) << 8;

    if (quadMulNormVecY == 0) {
        quadMulNormVecY = 0x3700;
    } else if (0x5000 < quadMulNormVecY) {
        quadMulNormVecY = 0x5000;
    }

    if (quadMulNormVecY < jumpSpeedCap) {
        jumpSpeedCap = quadMulNormVecY;
    }

    if (movement.y < jumpSpeedCap) {
        movement.y = jumpSpeedCap;
    }

finishMovement:
    if (driver->actionsFlagSet & 1) {
        if (driver->underDriver != NULL) {
            quadMulNormVecY = driver->underDriver->mulNormVecY;

            if (quadMulNormVecY != 0) {
                absSpeedApprox = driver->speedApprox;

                if (absSpeedApprox < 0) {
                    absSpeedApprox = -absSpeedApprox;
                }

                gte_ldVXY0((quadMulNormVecY * absSpeedApprox >> 8) << 0x10);
                gte_ldVZ0(0);
                gte_rtv0();

                {
                    s32 tempX;
                    s32 tempY;
                    s32 tempZ;

                    read_mt(tempX, tempY, tempZ);

                    movement.x += tempX;
                    movement.y += tempY;
                    movement.z += tempZ;
                }
            }
        }
    }

    VehPhysCrash_ConvertVecToSpeed(driver, &movement.x, 0);
    interpSpeed = driver->speed - speedLoss;
    driver->speed = interpSpeed;

    if (interpSpeed < 0) {
        driver->speed = 0;
    }

    speedApprox = driver->speedApprox;

    if (speedApprox < 0) {
        absSpeedApprox = speedApprox;

        if (absSpeedApprox < 0) {
            absSpeedApprox = -absSpeedApprox;
        }

        if (absSpeedApprox < 0x100) {
            driver->unk36E = driver->unk36E - (driver->unk36E >> 3);
        } else {
            driver->unk36E = (s16) (((driver->unk36E * 0xD) + ((M2C_FIELD(gGamepads, s32 *, 0x1CEC) & 7) * 0x300)) >> 4);
        }
    } else {
        driver->unk36E = (s16) (((driver->unk36E * 0xD) + (speedApprox * 3)) >> 4);
    }
}
