typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *gT;

s32 LOAD_GetAdvPackIndex(void) {
    s32 temp_v1;

    temp_v1 = M2C_FIELD(gT, s32 *, 0x1A10);
    if ((temp_v1 == 0x19) || (temp_v1 == 0x1C)) {
        return 2;
    }
    return 1;
}