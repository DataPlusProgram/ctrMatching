#include "../../common.h"

M2C_UNK s_ghost;
M2C_UNK s_ghost1;

void ElimBG_Deactivate(void *arg0)
{
    s32 flags;
    s32 ghostFlags;
    u8 hudFlags;

    if (M2C_FIELD(&s_ghost1, s16 *, 2) != 0) {
        flags = ((GameTracker *)arg0)->renderFlags;

        M2C_FIELD(&s_ghost1, s16 *, 2) = 3;

        ghostFlags = M2C_FIELD(&s_ghost, s32 *, 4);
        hudFlags = M2C_FIELD(&s_ghost1, u8 *, 0);

        flags = (flags & 0x1000) | (ghostFlags & ~0x1000);

        ((GameTracker *)arg0)->renderFlags = flags;
        M2C_FIELD(arg0, u8 *, 0x1D31) = hudFlags;
    }
}
