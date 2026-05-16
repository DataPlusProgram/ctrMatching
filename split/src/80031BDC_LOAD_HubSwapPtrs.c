typedef signed char s8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void LOAD_HubSwapPtrs(void *arg0) {
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_v0;

    temp_v0 = M2C_FIELD(arg0, s32 *, 0x164);
    if (temp_v0 != 0) {
        temp_a0 = M2C_FIELD(arg0, s32 *, 0x160);
        temp_a1 = M2C_FIELD(arg0, s32 *, 0x1A38);
        M2C_FIELD(arg0, s32 *, 0x160) = temp_v0;
        M2C_FIELD(arg0, s16 *, 0x2548) = 1;
        M2C_FIELD(arg0, s32 *, 0x164) = temp_a0;
        M2C_FIELD(arg0, s32 *, 0x1A38) = (s32) M2C_FIELD(arg0, s32 *, 0x1A3C);
        M2C_FIELD(arg0, s32 *, 0x1A3C) = temp_a1;
    }
}