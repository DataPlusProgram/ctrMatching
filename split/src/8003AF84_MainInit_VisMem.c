typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void MainInit_VisMem(void *arg0) {
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;

    temp_v0 = M2C_FIELD(M2C_FIELD(arg0, void **, 0x160), s32 *, 0x190);
    M2C_FIELD(arg0, s32 *, 0x1A38) = temp_v0;
    if (temp_v0 != 0) {
        var_a1 = 0;
        if (M2C_FIELD(arg0, u8 *, 0x1CA8) != 0) {
            do {
                temp_v1 = var_a1 * 4;
                M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x1A38) + temp_v1), s32 *, 0x40) = 0;
                M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x1A38) + temp_v1), s32 *, 0x50) = 0;
                M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x1A38) + temp_v1), s32 *, 0x60) = 0;
                M2C_FIELD((M2C_FIELD(arg0, s32 *, 0x1A38) + temp_v1), s32 *, 0x70) = 0;
                var_a1 += 1;
            } while (var_a1 < (s32) M2C_FIELD(arg0, u8 *, 0x1CA8));
        }
    }
}