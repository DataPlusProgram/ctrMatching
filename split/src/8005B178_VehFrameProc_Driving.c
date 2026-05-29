#include "../../common.h"

typedef struct DriverLinkedParticle {
    u8 pad0[0x18];
    u8 animByte;
    u8 driverId;
    u8 pad1A[6];
    Instance *driverInst;
} DriverLinkedParticle;

extern GameTracker *gGamepads;
extern M2C_UNK emSet_BurnSmoke;
extern s16 D_80086E84[];

extern void *Particle_Init(s32 flags, s32 pool, void *emitterSet);
extern s16 VehCalc_InterpBySpeed(s16 currentValue, s32 step, s32 targetValue);
extern s32 VehCalc_MapToRange(s32 value, s32 inMin, s32 inMax, s32 outMin, s32 outMax);
extern s32 VehFrameInst_GetNumAnimFrames(Instance *inst, u8 animIndex);
extern s32 VehFrameInst_GetStartFrame(u8 animIndex, s32 frameCount);

void VehFrameProc_Driving(Thread *thread, Driver *driver)
{
    Instance *inst;
    u8 desiredAnimIndex;
    s32 animFrameCount;
    s32 targetFrame;

    inst = thread->inst;
    desiredAnimIndex = 0;

    if ((driver->instTntRecv == NULL) && (driver->kartState != 10))
    {
        if ((driver->fireSpeed < 0) && (driver->speedApprox < 1))
        {
            desiredAnimIndex = 1;
        }

        if ((driver->jumpHeightCurr >= 0x601) || (inst->animIndex == 3))
        {
            if ((driver->posCurr.y - driver->quadBlockHeight) > 0x8000)
            {
                desiredAnimIndex = 3;
            }
        }
    }

    animFrameCount = VehFrameInst_GetNumAnimFrames(inst, inst->animIndex);
    if (animFrameCount <= 0)
    {
        return;
    }

    if (desiredAnimIndex == inst->animIndex)
    {
anim_is_current:
        if (desiredAnimIndex == 0)
        {
            if (driver->instTntRecv != NULL)
            {
                targetFrame = animFrameCount >> 1;
                goto interp_1;
            }

            if ((0 < driver->burnTimer) && (driver->burnTimer < 0x1E0))
            {
                DriverLinkedParticle *particle;

                targetFrame = ((((driver->burnTimer >> 5) % 5) << 2) - 8) + (animFrameCount >> 1);
                inst->animFrame = targetFrame;

                particle = Particle_Init(0, M2C_FIELD(gGamepads, s32 *, 0x2118), &emSet_BurnSmoke);
                if (particle != NULL)
                {
                    particle->animByte = driver->instSelf->unk50;
                    particle->driverInst = driver->instSelf;
                    particle->driverId = driver->driverId;
                }

                goto interp_1;
            }

            if ((driver->actionsFlagSet & 8) != 0)
            {
                targetFrame = VehCalc_MapToRange(-driver->ampTurnState, -0x40, 0x40, 0, animFrameCount - 1);
            }
            else
            {
                targetFrame = VehCalc_MapToRange(-driver->simpTurnState, -driver->constTurnRate, driver->constTurnRate, 0, animFrameCount - 1);
            }

            goto interp_1;
        }

        if (desiredAnimIndex == 3)
        {
            inst->animFrame = VehCalc_InterpBySpeed(inst->animFrame, 1, animFrameCount - 1);

            if (driver->kartState != 5)
            {
                s16 charId;

                charId = D_80086E84[driver->driverId];

                if (charId == 0xD)
                {
                    charId = 3;
                }

                if (charId == 0xE)
                {
                    charId = 0;
                }

                if (charId == 0xF)
                {
                    charId = 0;
                }

                driver->matrixAnimState = charId + 7;
                driver->matrixAnimFrame = (u8)inst->animFrame;
            }

            return;
        }

        goto interp_1_last_frame;
    }

    if (inst->animIndex == 2)
    {
        targetFrame = VehFrameInst_GetNumAnimFrames(inst, 1) - 1;
    }
    else
    {
        targetFrame = VehFrameInst_GetStartFrame(inst->animIndex, animFrameCount);
    }

    if (inst->animFrame == targetFrame)
    {
        animFrameCount = VehFrameInst_GetNumAnimFrames(inst, desiredAnimIndex);
        if (animFrameCount <= 0)
        {
            return;
        }

        inst->animIndex = desiredAnimIndex;
        inst->animFrame = VehFrameInst_GetStartFrame(desiredAnimIndex, animFrameCount);
        driver->matrixAnimState = 0;
        driver->matrixAnimFrame = 0;
        goto anim_is_current;
    }

    if (inst->animIndex != 0)
    {
        if (inst->animIndex == 2)
        {
            driver->matrixAnimFrame = (u8)inst->animFrame;
            goto interp_1;
        }
        goto interp_2;
    }

interp_6:
    inst->animFrame = VehCalc_InterpBySpeed(inst->animFrame, 6, targetFrame);
    return;

interp_2:
    inst->animFrame = VehCalc_InterpBySpeed(inst->animFrame, 2, targetFrame);
    if ((u32)(inst->animIndex - 2) < 2U)
    {
        driver->matrixAnimFrame = (u8)inst->animFrame;
        if ((u8)inst->animFrame == 0)
        {
            driver->matrixAnimState = 0;
            driver->matrixAnimFrame = 0;
        }
    }
    return;

interp_1_last_frame:
    targetFrame = animFrameCount - 1;

interp_1:
    inst->animFrame = VehCalc_InterpBySpeed(inst->animFrame, 1, targetFrame);
    return;
}
