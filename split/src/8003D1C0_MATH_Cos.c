#include "../../common.h"

extern s32 D_800845A0[];

s32 MATH_Cos(s32 angle)
{
    s32 cosineValue;
    s32 tableValue;

    tableValue = D_800845A0[angle & 0x3FF];

    if (angle & 0x400) {
        cosineValue = (s16)tableValue;
        if (!(angle & 0x800)) {
            cosineValue = -cosineValue;
        }
    } else {
        cosineValue = tableValue >> 0x10;
        if (angle & 0x800) {
            cosineValue = -cosineValue;
        }
    }

    return cosineValue;
}
