#include "../../common.h"

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 RaceFlag_ElapsedTime;

s32 RaceFlag_IsTransitioning(void)
{
    s32 var_a0;
    s32 temp_v0;

    var_a0 = 0;
    if ((RaceFlag_ElapsedTime != 0) &&
        (RaceFlag_ElapsedTime != -5000) &&
        (RaceFlag_ElapsedTime != 5000))
    {
        temp_v0 = ((GameTracker *)gT)->renderFlags & 0x1000;
        var_a0 = (u32)var_a0 < (u32)temp_v0;
    }

    return var_a0;
}
