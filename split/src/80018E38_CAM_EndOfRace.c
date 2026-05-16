#include "../../common.h"


#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK CAM_EndOfRace_Battle();                     /* extern */
extern void *D_8008D2AC;

void CAM_EndOfRace(void *arg0) {
    if (!(M2C_FIELD(D_8008D2AC, s32 *, 0) & 0x20) && (*M2C_FIELD(M2C_FIELD(D_8008D2AC, void **, 0x160), s32 **, 0x134) >= 2) && ((u8) M2C_FIELD(D_8008D2AC, u8 *, 0x1CA8) < 3U)) {
        M2C_FIELD(arg0, s32 *, 0x70) = (s32) (M2C_FIELD(arg0, s32 *, 0x70) | 0x20);
        return;
    }
    CAM_EndOfRace_Battle();
}