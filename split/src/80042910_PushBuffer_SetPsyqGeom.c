#include "../../common.h"

M2C_UNK SetGeomOffset();                    /* extern */
M2C_UNK SetGeomScreen();                         /* extern */

void PushBuffer_SetPsyqGeom(PushBuffer *pb) {
    u32 packed;
    s32 x;
    s32 y;

    packed = (u16)pb->rectX;
    packed <<= 16;
    x = (s32)packed >> 16;
    x += packed >> 31;

    packed = (u16)pb->rectY;
    packed <<= 16;
    y = (s32)packed >> 16;
    y += packed >> 31;

    SetGeomOffset(x >> 1, y >> 1);
    SetGeomScreen(pb->distanceToScreenPrev);
}
