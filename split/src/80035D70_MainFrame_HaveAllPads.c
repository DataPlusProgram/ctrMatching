typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 D_8008D10C;
M2C_UNK s_OTMem;

s32 MainFrame_HaveAllPads(s16 arg0) {
    s16 temp_v0;
    s16 var_a2;
    s32 var_a0;
    s32 var_a1;
    s32 var_v0;
    u8 *temp_v0_2;

    var_a1 = 1;
    if (D_8008D10C != -1) {
        return 1;
    }
    if (arg0 != 0) {
        var_a2 = 0;
        if (arg0 > 0) {
            do {
                var_a0 = 0;
                if ((var_a1 << 0x10) != 0) {
                    temp_v0_2 = M2C_FIELD((M2C_FIELD(&s_OTMem, s32 *, 4) + (var_a2 * 0x50)), u8 **, 0x20);
                    if (temp_v0_2 != NULL) {
                        var_a0 = *temp_v0_2 == 0;
                    }
                }
                temp_v0 = var_a2 + 1;
                var_a2 = temp_v0;
                var_a1 = var_a0;
            } while (temp_v0 < arg0);
            var_v0 = var_a1 << 0x10;
        } else {
            goto block_11;
        }
    } else {
        var_a1 = 0;
block_11:
        var_v0 = var_a1 << 0x10;
    }
    return var_v0 >> 0x10;
}