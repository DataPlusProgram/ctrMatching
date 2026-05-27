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
extern GameTracker *gT;
extern M2C_UNK emSet_Falling;

extern void MatrixRotate(void *output, void *baseMatrix, void *rotationData);
extern void OtherFX_Play_Echo(s32 soundId, s32 count, s32 flags);
extern void *Particle_Init(s32 flags, s32 pool, void *emitterSet);
extern s16 VehCalc_InterpBySpeed(s16 currentValue, s32 step, s32 targetValue);
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
    s16 jumpHeightCurr;
    u8 matrixAnimFrame;
    u8 matrixAnimState;
    u32 actionFlags;
    u32 angle;

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

                if (((driver->actionsFlagSet | driver->actionsFlagSetPrevFrame) & 2) == 0) {
                    if (animSpeed < -0x320) {
                        animSpeed = -0x320;
                    }
                } else if (animSpeed < -0x640) {
                    animSpeed = -0x640;
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
                        OtherFX_Play_Echo(0x5B, 1, driver->actionsFlagSet & 1);
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

    matrixAnimState = driver->matrixAnimState;
    matrixAnimFrame = driver->matrixAnimFrame;

    if ((driver->reserves == 0) || (driver->fireSpeed < driver->constSpeedClassStat) || (driver->actionsFlagSet & 0x80)) {
        if (matrixAnimState != 0) {
            if (matrixAnimState == 2) {
                matrixAnimState = 3;
                matrixAnimFrame = 0;
            } else if (matrixAnimState == 1) {
                frameDuration = D_80087F00 - 1;
                if (frameDuration != 0) {
                    animBlendValue = 0x100 - (((u32)matrixAnimFrame << 8) / frameDuration);
                    if (animBlendValue < 0) {
                        animBlendValue = 0;
                    }
                    if (0x100 < animBlendValue) {
                        animBlendValue = 0x100;
                    }

                    matrixAnimFrame = (u8)((animBlendValue * (D_80087F10 - 1)) >> 8);
                    matrixAnimState = 3;
                }
            } else if ((matrixAnimState == 3) && (D_80087F10 <= (u32)(matrixAnimFrame + 1))) {
                matrixAnimState = 0;
                matrixAnimFrame = 0;
            }
        }
    } else {
        if (matrixAnimState == 1) {
            matrixAnimFrame++;
            if (D_80087F00 <= matrixAnimFrame) {
                matrixAnimState = 2;
                matrixAnimFrame = 0;
            }
        } else if (2 < matrixAnimState) {
            if (matrixAnimState == 3) {
                frameDuration = D_80087F10 - 1;
                if (frameDuration != 0) {
                    animBlendValue = 0x100 - (((u32)matrixAnimFrame << 8) / frameDuration);
                    if (animBlendValue < 0) {
                        animBlendValue = 0;
                    }
                    if (0x100 < animBlendValue) {
                        animBlendValue = 0x100;
                    }

                    matrixAnimFrame = (u8)((animBlendValue * (D_80087F00 - 1)) >> 8);
                    matrixAnimState = 1;
                }
            }
        } else if (matrixAnimState == 0) {
            matrixAnimState = 1;
            matrixAnimFrame = 0;
        }
    }

    if ((matrixAnimState == 5) && (D_80087F20 <= (u32)(matrixAnimFrame + 1))) {
        matrixAnimState = 0;
        matrixAnimFrame = 0;
    } else if (matrixAnimState == 5) {
        matrixAnimFrame++;
    }

    driver->matrixAnimState = matrixAnimState;
    driver->matrixAnimFrame = matrixAnimFrame;

    if (matrixAnimState == 0) {
        inst->matrix.m[0][0] = driver->matrixFacingDir.m[0][0];
        inst->matrix.m[0][1] = driver->matrixFacingDir.m[0][1];
        inst->matrix.m[0][2] = driver->matrixFacingDir.m[0][2];
        inst->matrix.m[1][0] = driver->matrixFacingDir.m[1][0];
        inst->matrix.m[1][1] = driver->matrixFacingDir.m[1][1];
        inst->matrix.m[1][2] = driver->matrixFacingDir.m[1][2];
        inst->matrix.m[2][0] = driver->matrixFacingDir.m[2][0];
        inst->matrix.m[2][1] = driver->matrixFacingDir.m[2][1];
        inst->matrix.m[2][2] = driver->matrixFacingDir.m[2][2];
        inst->matrix.extraShort = driver->matrixFacingDir.extraShort;
        inst->matrix.t[0] = driver->posCurr.x >> 8;
        inst->matrix.t[1] = (driver->posCurr.y >> 8) + ((driver->screenOffsetY * 3) >> 3);
        offsetZ = driver->posCurr.z;
    } else {
        MatrixAnimFrame *animFrameData;
        MatrixAnimSet *animSet;
        u32 *matrixWords;

        animSet = &D_80087EF4[matrixAnimState];
        animFrameData = (MatrixAnimFrame *)((s8 *)animSet->frames + ((u32)matrixAnimFrame << 5));

        MatrixRotate(&inst->matrix, &driver->matrixFacingDir, animFrameData->rotData);
        matrixWords = (u32 *)&driver->matrixFacingDir;
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
    }

    inst->matrix.t[2] = offsetZ >> 8;

    if (driver->squishTimer != 0) {
        inst->matrix.t[0] += (driver->axisAngle2NormalVec[0] * 0x13) >> 0xC;
        inst->matrix.t[1] += (driver->axisAngle2NormalVec[1] * 0x13) >> 0xC;
        inst->matrix.t[2] += (driver->axisAngle2NormalVec[2] * 0x13) >> 0xC;
    }

    verticalPos = inst->matrix.t[1];
    if ((verticalPos < 0) && (-0x4F <= verticalPos) && ((inst->flags & INSTANCE_FLAG_SPLIT_LINE) != 0)) {
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

        angle = (u16)driver->angle;
        tableWord = D_800845A0[angle & 0x3FF];
        splashRotY = (s16)tableWord;
        splashRotX = tableWord >> 16;

        if ((angle & 0x400) == 0) {
            if ((angle & 0x800) == 0) {
                splashRotY = -splashRotY;
            } else {
                splashRotX = -splashRotX;
            }
        } else {
            animBlendValue = splashRotY;
            splashRotY = splashRotX;
            if ((angle & 0x800) == 0) {
                splashRotX = -animBlendValue;
            } else {
                splashRotX = animBlendValue;
                splashRotY = -splashRotY;
            }
        }

        wakeInst->matrix.m[0][0] = (s16)splashRotX;
        wakeInst->matrix.m[0][1] = 0;
        wakeInst->matrix.m[0][2] = (s16)splashRotY;
        wakeInst->matrix.m[1][0] = 0;
        wakeInst->matrix.m[1][1] = 0x1000;
        wakeInst->matrix.m[1][2] = 0;
        wakeInst->matrix.m[2][0] = (s16)-splashRotY;
        wakeInst->matrix.m[2][1] = 0;
        wakeInst->matrix.m[2][2] = (s16)splashRotX;

        if (driver->wakeScale == 0) {
            driver->wakeScale = 0x1000;
            if (gT->numPlyrCurrGame < 2) {
                speedAbs = driver->speed;
                if (speedAbs < 0) {
                    speedAbs = -speedAbs;
                }

                if ((0xC00 < speedAbs) && (-0x1FF < driver->posPrev.y)) {
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
            if (gT->numPlyrCurrGame < 2) {
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

finishWake:
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
