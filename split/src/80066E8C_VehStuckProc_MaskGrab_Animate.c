#include "../../common.h"

extern GameTracker *gGamepads;
extern void OtherFX_Play(s32 soundId, s32 volume);
extern s32 VehFrameInst_GetNumAnimFrames(Instance *inst, u8 animIndex);
extern s16 VehFrameInst_GetStartFrame(u8 animIndex, s32 frameCount);

void VehStuckProc_MaskGrab_Animate(Thread *thread, Driver *driver)
{
    Instance *inst;
    s16 animFrame;
    s16 maskScale;
    s32 elapsedPosY;
    s32 targetPosY;
    s8 desiredAnimFrame;
    void *maskObj;

    inst = thread->inst;

    if (driver->kartStates.maskGrab.boolStillFalling != 0) {
        if ((driver->kartStates.maskGrab.boolWhistle == 0) && (driver->noInputTimer < 0x3C0)) {
            OtherFX_Play(0x55, 1);
            driver->kartStates.maskGrab.boolWhistle = 1;
        }

        driver->matrixAnimState = 4;
        if (driver->kartStates.maskGrab.animFrame >= 3) {
            desiredAnimFrame = (u8)driver->kartStates.maskGrab.animFrame + 5;
        } else {
            desiredAnimFrame = 7;
        }

        driver->matrixAnimFrame = desiredAnimFrame;
        inst->animIndex = 2;

        maskScale = 7;
        if (driver->kartStates.maskGrab.animFrame >= 3) {
            maskScale = (u16)driver->kartStates.maskGrab.animFrame + 5;
        }

        inst->animFrame = maskScale;

        animFrame = (u16)driver->kartStates.maskGrab.animFrame + 1;
        driver->kartStates.maskGrab.animFrame = animFrame;
        if (animFrame >= 8) {
            driver->kartStates.maskGrab.animFrame = 7;
        }

        if (driver->noInputTimer >= 0x510) {
            driver->speed = 0;
            driver->speedApprox = 0;
            driver->posCurr.x = driver->posPrev.x;
            driver->posCurr.y = driver->posPrev.y;
            driver->posCurr.z = driver->posPrev.z;
        } else {
            driver->matrixAnimState = 4;
            driver->matrixAnimFrame = 0xC;
            inst->animIndex = 2;
            inst->animFrame = 0xC;

            if (driver->noInputTimer >= 0x3C1) {
                if (driver->kartStates.maskGrab.boolParticlesSpawned == 0) {
                    VehStuckProc_MaskGrab_Particles(driver);
                    driver->kartStates.maskGrab.boolParticlesSpawned = 1;
                }

                maskScale = driver->jumpSquishStretch + 0x2D0;
                driver->jumpSquishStretch = maskScale;
                if (maskScale >= 0x1F41) {
                    driver->jumpSquishStretch = 0x1F40;
                }
            } else {
                maskScale = driver->jumpSquishStretch - 0x320;
                driver->jumpSquishStretch = maskScale;
                if ((s32)(maskScale << 0x10) < 0) {
                    driver->jumpSquishStretch = 0;
                }
            }
        }
    } else {
        driver->matrixAnimState = 0;
        driver->matrixAnimFrame = 0;
        inst->animIndex = 0;
        inst->animFrame = VehFrameInst_GetStartFrame(0, VehFrameInst_GetNumAnimFrames(inst, 0));
        driver->axisAngle2NormalVec[0] = driver->kartStates.maskGrab.angleAxisNormalVec[0];
        driver->axisAngle2NormalVec[1] = driver->kartStates.maskGrab.angleAxisNormalVec[1];
        driver->axisAngle2NormalVec[2] = driver->kartStates.maskGrab.angleAxisNormalVec[2];
    }

    maskObj = driver->kartStates.maskGrab.maskObj;
    if (maskObj != NULL) {
        M2C_FIELD(maskObj, s16 *, 6) = 0x1E00;

        if (driver->noInputTimer >= 0x3C1) {
            M2C_FIELD(maskObj, s16 *, 0x12) = 0;
            return;
        }

        if (driver->kartStates.maskGrab.boolLiftingPlayer != 0) {
            elapsedPosY = gGamepads->elapsedTimeMS << 7;
            targetPosY = driver->posCurr.y;
            driver->speed = 0;
            elapsedPosY = targetPosY + elapsedPosY;
            driver->posCurr.y = elapsedPosY;
            driver->posPrev.y = elapsedPosY;
        } else {
            M2C_FIELD(maskObj, u16 *, 0xE) -= (u16)gGamepads->elapsedTimeMS;
        }

        M2C_FIELD(maskObj, s16 *, 0x10) = driver->posCurr.z >> 8;

        targetPosY = driver->posCurr.y >> 8;
        if (M2C_FIELD(maskObj, s16 *, 0xE) < targetPosY) {
            M2C_FIELD(maskObj, u16 *, 0xE) = targetPosY;
            driver->kartStates.maskGrab.boolLiftingPlayer = 1;
        }

        M2C_FIELD(maskObj, s16 *, 0xC) = driver->posCurr.x >> 8;

        if (driver->noInputTimer >= 0x2D1) {
            M2C_FIELD(maskObj, s16 *, 0x12) = ((0x3C0 - driver->noInputTimer) << 0xC) / 240;
            return;
        }

        M2C_FIELD(maskObj, s16 *, 0x12) = 0x1000;
    }
}
