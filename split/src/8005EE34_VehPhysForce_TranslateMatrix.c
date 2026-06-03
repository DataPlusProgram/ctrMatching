#include "../../common.h"

typedef struct MatrixAnimFrame {
    s16 pos[3];
    s16 pad6;
    s16 rotData[12];
} MatrixAnimFrame;

typedef struct MatrixAnimSet {
    MatrixAnimFrame *frames;
    s32 frameCount;
} MatrixAnimSet;

typedef struct FallingParticle {
    u8 pad0[0x18];
    u8 animByte;
    u8 driverId;
    u8 pad1A[6];
    Instance *driverInst;
} FallingParticle;

enum {
    INSTANCE_FLAG_HIDE_MODEL = 0x80,
    INSTANCE_FLAG_SPLIT_LINE = 0x2000
};

extern s32 D_800845A0[];
extern s32 D_80087F00;
extern s32 D_80087F10;
extern s32 D_80087F20;
extern MatrixAnimSet D_80087EF4[];
extern M2C_UNK emSet_Falling;

extern void MatrixRotate(void *output, void *baseMatrix, void *rotationData);
extern void OtherFX_Play_Echo(s32 soundId, s32 count, s32 flags);
extern void *Particle_Init(s32 flags, s32 pool, void *emitterSet);
extern s32 VehCalc_MapToRange(s32 value, s32 inMin, s32 inMax, s32 outMin, s32 outMax);
extern void VehPhysForce_RotAxisAngle(MatrixNd *matrix, s16 *axisAngleNormalVec, s16 angle);

void VehPhysForce_TranslateMatrix(Thread *thread, Driver *driver)
{
    Instance *inst;
    Instance *wakeInst;
    s32 absScaleDelta;
    s32 animBlendValue;
    s32 animSpeed;
    s32 frameDuration;
    s32 i;
    s32 offsetX;
    s32 offsetY;
    s32 offsetZ;
    s32 scaleTarget;
    s32 speedAbs;
    s32 splashRotX;
    s32 splashRotY;
    s32 tableWord;
    s32 turnScale;
    s32 verticalPos;
    s32 jumpHeightCurr;
    u8 matrixAnimFrame;
    u8 matrixAnimState;
    u32 actionFlags;
    s32 angle;

    inst = thread->inst;

    if (driver->kartState != 0xA) {
        if ((driver->kartState == 5) && ((driver->actionsFlagSet & 1) == 0)) {
            inst->scale[1] = driver->jumpSquishStretch + 0xCCC;

            turnScale = driver->jumpSquishStretch * 0x28;
            if (turnScale < 0) {
                turnScale += 0xFF;
            }

            scaleTarget = 0xCCC - (turnScale >> 8);
            if (scaleTarget < 0x400) {
                scaleTarget = 0x400;
            }

            inst->scale[0] = (s16)scaleTarget;
            inst->scale[2] = (s16)scaleTarget;
        } else {
            jumpHeightCurr = driver->jumpHeightCurr;
            animSpeed = -0x320;
            actionFlags = driver->actionsFlagSet;

            if ((actionFlags & 0x400) == 0) {
                turnScale = jumpHeightCurr * 7;
                animBlendValue = driver->jumpSquishStretch2 * 9;
                animSpeed = (driver->jumpSquishStretch2 - ((animBlendValue + turnScale) >> 4)) * 4;
                absScaleDelta = animSpeed;

                if (absScaleDelta < 0) {
                    absScaleDelta = -absScaleDelta;
                }

                if (absScaleDelta < 0x960) {
                    animSpeed = 0;
                }

                if (((driver->actionsFlagSet | driver->actionsFlagSetPrevFrame) & 2) != 0) {
                    if (animSpeed < -0x640) {
                        animSpeed = -0x640;
                    }
                } else if (animSpeed < -0x320) {
                    animSpeed = -0x320;
                }

                if (0x320 < animSpeed) {
                    animSpeed = 0x320;
                }
            }

            if ((0 < driver->hazardTimer) && ((driver->hazardTimer & 0x80) == 0) && (-0x320 < animSpeed)) {
                animSpeed = -0x320;
            }

            if (((driver->actionsFlagSet & 1) == 0) && (jumpHeightCurr < 0)) {
                absScaleDelta = VehCalc_MapToRange(-jumpHeightCurr, 0, 0xA00, 0x280, 0x320);
                if (animSpeed < absScaleDelta) {
                    animSpeed = absScaleDelta;
                }
                driver->jumpSquishStretch2 = jumpHeightCurr;
            }

            if ((driver->instTntRecv != NULL) && (driver->instTntRecv->scale[1] < 0x9C4)) {
                animSpeed += (driver->instTntRecv->scale[1] - 0x800) * 2;
            }

            absScaleDelta = animSpeed;
            if (absScaleDelta < 0) {
                absScaleDelta = -absScaleDelta;
            }

            speedAbs = driver->jumpSquishStretch;
            if (speedAbs < 0) {
                speedAbs = -speedAbs;
            }

            if (speedAbs < absScaleDelta) {
                driver->jumpSquishStretch = (s16)animSpeed;
            }

            driver->jumpSquishStretch = VehCalc_InterpBySpeed(driver->jumpSquishStretch, 0x12C, 0);
            driver->jumpSquishStretch2 = (s16)(((driver->jumpSquishStretch2 * 9) + (jumpHeightCurr * 7)) >> 4);

            if (driver->squishTimer == 0) {
                if (inst->scale[1] == 0) {
                    if (driver->instSelf->thread->modelIndex == 0x18) {
                        OtherFX_Play_Echo(0x5B, 1, M2C_FIELD(driver, u16 *, 0x2CA) & 1);
                    }

                    inst->scale[1] = driver->jumpSquishStretch + 0xCCC;
                    matrixAnimState = 5;
                    matrixAnimFrame = 0;
                    driver->matrixAnimState = matrixAnimState;
                    driver->matrixAnimFrame = matrixAnimFrame;
                } else {
                    inst->scale[1] = VehCalc_InterpBySpeed(inst->scale[1], 0xA0, driver->jumpSquishStretch + 0xCCC);
                }
            } else {
                inst->scale[1] = 0;
            }

            turnScale = driver->jumpSquishStretch * 0xA0;
            if (turnScale < 0) {
                turnScale += 0xFF;
            }
            inst->scale[0] = VehCalc_InterpBySpeed(inst->scale[0], 0xA0, 0xCCC - (turnScale >> 8));

            turnScale = driver->jumpSquishStretch * 0xA0;
            if (turnScale < 0) {
                turnScale += 0xFF;
            }
            inst->scale[2] = VehCalc_InterpBySpeed(inst->scale[2], 0xA0, 0xCCC - (turnScale >> 8));
        }
    }

    VehPhysForce_RotAxisAngle(&driver->matrixFacingDir, driver->axisAngle2NormalVec, driver->rotCurr[1]);

    if ((driver->reserves != 0) && (driver->fireSpeed >= driver->constSpeedClassStat) && ((driver->actionsFlagSet & 0x80) == 0)) {
        MatrixAnimSet *animSetBase;
        s32 state;

        state = driver->matrixAnimState;
        matrixAnimState = state;

        if (state == 1) {
            goto boostState1;
        }
        if (state >= 2) {
            goto boostStateGe2;
        }
        if (state == 0) {
            goto boostState0;
        }
        goto boostStateDone;

boostStateGe2:
        if (state == 2) {
            goto boostStateDone;
        }
        if (state == 3) {
            goto boostState3;
        }
        goto boostStateDone;

boostState0:
        driver->matrixAnimState = 1;
        goto boostStateDone;

boostState1:
        matrixAnimFrame = driver->matrixAnimFrame;
        matrixAnimFrame++;
        driver->matrixAnimFrame = matrixAnimFrame;

        if (D_80087F00 <= matrixAnimFrame) {
            driver->matrixAnimState = 2;
            driver->matrixAnimFrame = 0;
        }
        goto boostStateDone;

boostState3:
        animSetBase = D_80087EF4;
        frameDuration = animSetBase[3].frameCount - 1;
        if (frameDuration != 0) {
            animBlendValue = 0x100 - ((driver->matrixAnimFrame << 8) / frameDuration);
            if (animBlendValue < 0) {
                animBlendValue = 0;
            }
            if (0x100 < animBlendValue) {
                animBlendValue = 0x100;
            }

            matrixAnimFrame = (u8)((animBlendValue * (animSetBase[1].frameCount - 1)) >> 8);
            driver->matrixAnimState = 1;
            driver->matrixAnimFrame = matrixAnimFrame;
        }

boostStateDone:;
    } else {
        matrixAnimState = driver->matrixAnimState;

        if (matrixAnimState != 0) {
            if (matrixAnimState == 2) {
                matrixAnimState = 3;
                matrixAnimFrame = 0;
                driver->matrixAnimState = matrixAnimState;
                driver->matrixAnimFrame = matrixAnimFrame;
            } else if (matrixAnimState == 1) {
                frameDuration = D_80087F00 - 1;
                if (frameDuration != 0) {
                    animBlendValue = 0x100 - ((driver->matrixAnimFrame << 8) / frameDuration);
                    if (animBlendValue < 0) {
                        animBlendValue = 0;
                    }
                    if (0x100 < animBlendValue) {
                        animBlendValue = 0x100;
                    }

                    matrixAnimFrame = (u8)((animBlendValue * (D_80087F10 - 1)) >> 8);
                    matrixAnimState = 3;
                    driver->matrixAnimState = matrixAnimState;
                    driver->matrixAnimFrame = matrixAnimFrame;
                }
            } else if (matrixAnimState == 3) {
                matrixAnimFrame = driver->matrixAnimFrame + 1;
                driver->matrixAnimFrame = matrixAnimFrame;

                if (D_80087F10 <= matrixAnimFrame) {
                    driver->matrixAnimState = 0;
                    driver->matrixAnimFrame = 0;
                }
            }
        }
    }

    if (driver->matrixAnimState == 5) {
        matrixAnimFrame = driver->matrixAnimFrame + 1;
        driver->matrixAnimFrame = matrixAnimFrame;

        if (D_80087F20 <= matrixAnimFrame) {
            driver->matrixAnimState = 0;
            driver->matrixAnimFrame = 0;
        }
    }

    if (driver->matrixAnimState != 0) {
        MatrixAnimFrame *animFrameData;
        MatrixAnimSet *animSet;
        u32 *matrixWords;

        matrixAnimState = driver->matrixAnimState;
        matrixAnimFrame = driver->matrixAnimFrame;
        matrixWords = (u32 *)&driver->matrixFacingDir;
        animSet = &D_80087EF4[matrixAnimState];
        animFrameData = (MatrixAnimFrame *)((s8 *)animSet->frames + ((u32)matrixAnimFrame << 5));

        MatrixRotate(&inst->matrix, matrixWords, animFrameData->rotData);
        gte_ldR11R12(matrixWords[0]);
        gte_ldR13R21(matrixWords[1]);
        gte_ldR22R23(matrixWords[2]);
        gte_ldR31R32(matrixWords[3]);
        gte_ldR33(matrixWords[4]);

        gte_ldVXY0((u32)(u16)animFrameData->pos[0] | ((u32)(u16)animFrameData->pos[1] << 16));
        gte_ldVZ0((u16)animFrameData->pos[2]);
        gte_rtv0();
        read_mt(offsetX, offsetY, offsetZ);

        inst->matrix.t[0] = (driver->posCurr.x + offsetX) >> 8;
        inst->matrix.t[1] = ((driver->posCurr.y + offsetY) >> 8) + ((driver->screenOffsetY * 3) >> 3);
        offsetZ += driver->posCurr.z;
    } else {
        M2C_FIELD(inst, s32 *, 0x30) = M2C_FIELD(driver, s32 *, 0x330);
        M2C_FIELD(inst, s32 *, 0x34) = M2C_FIELD(driver, s32 *, 0x334);
        M2C_FIELD(inst, s32 *, 0x38) = M2C_FIELD(driver, s32 *, 0x338);
        M2C_FIELD(inst, s32 *, 0x3C) = M2C_FIELD(driver, s32 *, 0x33C);
        M2C_FIELD(inst, s16 *, 0x40) = M2C_FIELD(driver, s16 *, 0x340);
        inst->matrix.t[0] = driver->posCurr.x >> 8;
        inst->matrix.t[1] = (driver->posCurr.y >> 8) + ((driver->screenOffsetY * 3) >> 3);
        offsetZ = driver->posCurr.z;
    }

    inst->matrix.t[2] = offsetZ >> 8;

    if (driver->squishTimer != 0) {
        inst->matrix.t[0] += (driver->axisAngle2NormalVec[0] * 0x13) >> 0xC;
        inst->matrix.t[1] += (driver->axisAngle2NormalVec[1] * 0x13) >> 0xC;
        inst->matrix.t[2] += (driver->axisAngle2NormalVec[2] * 0x13) >> 0xC;
    }

    verticalPos = inst->matrix.t[1];
    if (verticalPos < 0) {
        if ((-0x4F <= verticalPos) && ((inst->flags & INSTANCE_FLAG_SPLIT_LINE) != 0)) {
        wakeInst = driver->wakeInst;
        if (wakeInst == NULL) {
            return;
        }

        wakeInst->flags &= ~INSTANCE_FLAG_HIDE_MODEL;
        wakeInst->unk50 = inst->unk50 + 1;
        wakeInst->unk51 = inst->unk51 - 1;
        wakeInst->matrix.t[1] = 0;
        wakeInst->matrix.t[0] = inst->matrix.t[0];
        wakeInst->matrix.t[2] = inst->matrix.t[2];

        angle = driver->angle;
        tableWord = D_800845A0[angle & 0x3FF];

        if ((angle & 0x400) != 0) {
            splashRotY = tableWord >> 16;
            splashRotX = (tableWord << 16) >> 16;

            if ((angle & 0x800) == 0) {
                splashRotX = -splashRotX;
            } else {
                splashRotY = -splashRotY;
            }
        } else {
            splashRotX = tableWord >> 16;
            splashRotY = (tableWord << 16) >> 16;

            if ((angle & 0x800) == 0) {
                splashRotY = -splashRotY;
            } else {
                splashRotX = -splashRotX;
            }
        }

        M2C_FIELD(wakeInst, s32 *, 0x30) = splashRotX;
        M2C_FIELD(wakeInst, s32 *, 0x34) = splashRotY;
        M2C_FIELD(wakeInst, s32 *, 0x38) = 0x1000;
        M2C_FIELD(wakeInst, s32 *, 0x3C) = -splashRotY;
        wakeInst->matrix.m[2][2] = (s16)splashRotX;

        if (driver->wakeScale == 0) {
            driver->wakeScale = 0x1000;
            if (M2C_FIELD(gT, u8 *, 0x1CA8) < 2) {
                speedAbs = driver->speed;
                if (speedAbs < 0) {
                    speedAbs = -speedAbs;
                }

                if ((0xC00 < speedAbs) && (-0x200 < driver->posPrev.y)) {
                    FallingParticle *particle;

                    i = 10;
                    do {
                        particle = Particle_Init(0, M2C_FIELD(gT, s32 *, 0x2138), &emSet_Falling);
                        if (particle != NULL) {
                            particle->animByte = driver->instSelf->unk50;
                            particle->driverInst = driver->instSelf;
                            particle->driverId = driver->driverId;
                        }
                        i--;
                    } while (i != 0);
                }
            }
        } else {
            if (M2C_FIELD(gT, u8 *, 0x1CA8) < 2) {
                speedAbs = driver->speed;
                if (speedAbs < 0) {
                    speedAbs = -speedAbs;
                }

                if (0xC00 < speedAbs) {
                    FallingParticle *particle;

                    particle = Particle_Init(0, M2C_FIELD(gT, s32 *, 0x2138), &emSet_Falling);
                    if (particle != NULL) {
                        particle->animByte = driver->instSelf->unk50;
                        particle->driverInst = driver->instSelf;
                        particle->driverId = driver->driverId;
                    }
                }
            }
        }

            wakeInst->scale[0] = driver->wakeScale;
            wakeInst->scale[2] = driver->wakeScale;
            return;
        }
    }

    if (0 < verticalPos) {
        inst->flags &= ~INSTANCE_FLAG_SPLIT_LINE;
    }

    wakeInst = driver->wakeInst;
    if (wakeInst != NULL) {
        wakeInst->flags |= INSTANCE_FLAG_HIDE_MODEL;
        driver->wakeScale = 0;
        wakeInst->scale[0] = 0;
        wakeInst->scale[2] = driver->wakeScale;
    }
}
