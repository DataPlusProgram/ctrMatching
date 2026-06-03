#include "../../common.h"

extern s32 D_800845A0[];

s32 MATH_Sin(s32 angle)
{
    s32 sinValue;

    sinValue = D_800845A0[angle & 0x3FF];

    if ((angle & 0x400) == 0) {
        sinValue <<= 0x10;
    }

    sinValue >>= 0x10;

    if ((angle & 0x800) != 0) {
        sinValue = -sinValue;
    }

    return sinValue;
}
