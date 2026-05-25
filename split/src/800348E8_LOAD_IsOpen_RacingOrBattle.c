typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *gGamepads;

s32 LOAD_IsOpen_RacingOrBattle(void) {
    return M2C_FIELD(gGamepads, u8 *, 0x2541) == 1;
}