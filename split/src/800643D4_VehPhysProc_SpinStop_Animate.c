#include "../../common.h"

s32 VehFrameInst_GetNumAnimFrames(Instance *inst, u8 animIndex);
s32 VehFrameInst_GetStartFrame(s32 arg0, s32 numFrames);

void VehPhysProc_SpinStop_Animate(Thread *thread, Driver *driver)
{
    Instance *inst;
    s32 numFrames;
    s16 frame;

    inst = thread->inst;
    numFrames = VehFrameInst_GetNumAnimFrames(inst, inst->animIndex);

    if (numFrames <= 0)
    {
        driver->funcPtrs[0] = VehPhysProc_Driving_Init;
        return;
    }

    switch (driver->kartStates.spinning.spinDir)
    {
    case 1:
        frame = inst->animFrame - 5;
        inst->animFrame = frame;

        if (frame < 0)
        {
            inst->animFrame = 0;
            driver->kartStates.spinning.spinDir = 0;
        }
        break;

    case -1:
        frame = inst->animFrame + 5;
        inst->animFrame = frame;

        if (frame >= numFrames)
        {
            inst->animFrame = numFrames - 1;
            driver->kartStates.spinning.spinDir = 0;
        }
        break;

    default:
        numFrames = VehFrameInst_GetStartFrame(0, numFrames);
        frame = VehCalc_InterpBySpeed(inst->animFrame, 2, numFrames);
        inst->animFrame = frame;

        if (frame == numFrames)
            driver->funcPtrs[0] = VehPhysProc_Driving_Init;
    }
}
