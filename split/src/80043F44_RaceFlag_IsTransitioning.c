typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 RaceFlag_ElapsedTime;
extern void *gGamepads;

s32 RaceFlag_IsTransitioning(void) {
    s32 var_a0;

    var_a0 = 0;
    if ((RaceFlag_ElapsedTime != 0) && (RaceFlag_ElapsedTime != -0x1388) && (RaceFlag_ElapsedTime != 0x1388)) {
        var_a0 = (u32) (M2C_FIELD(gGamepads, s32 *, 0x256C) & 0x1000) > 0U;
    }
    return var_a0;
}