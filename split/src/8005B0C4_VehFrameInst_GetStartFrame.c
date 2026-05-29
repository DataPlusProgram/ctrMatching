#include "../../common.h"

s32 VehFrameInst_Unknown_8005B0EC(void);

s32 VehFrameInst_GetStartFrame(s32 animIndex, s32 numFrames)
{
    if (animIndex == 0)
    {
        return numFrames >> 1;
    }

    if (animIndex != 4)
    {
        return VehFrameInst_Unknown_8005B0EC();
    }

    return numFrames - 1;
}
