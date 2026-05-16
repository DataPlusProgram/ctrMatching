typedef signed char s8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void CTR_CycleTex_Model(s32 **arg0, s32 arg1) {
    s8 *var_a2;
    s32 temp_hi;

    var_a2 = (s8 *) arg0;
    if (M2C_FIELD(arg0, s32 *, 0) != (s32) arg0) {
        do {
            temp_hi = ((arg1 + M2C_FIELD(var_a2, s16 *, 6)) >> M2C_FIELD(var_a2, s16 *, 8)) % M2C_FIELD(var_a2, s16 *, 4);
            M2C_FIELD(var_a2, s16 *, 0xA) = temp_hi;
            *M2C_FIELD(var_a2, s32 **, 0) = M2C_FIELD(var_a2 + ((temp_hi << 0x10) >> 0xE), s32 *, 0xC);
            var_a2 += (M2C_FIELD(var_a2, s16 *, 4) * 4) + 0xC;
        } while (M2C_FIELD(var_a2, s32 *, 0) != (s32) arg0);
    }
}