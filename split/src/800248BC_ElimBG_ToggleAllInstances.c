typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ElimBG_ToggleInstance();        /* extern */
s32 LIST_GetFirstItem();                      /* extern */
s32 LIST_GetNextItem();                          /* extern */

void ElimBG_ToggleAllInstances(void *arg0, M2C_UNK arg1) {
    s32 temp_a0;
    s32 var_s0_2;
    u32 temp_s1;
    u32 var_s0;
    void *temp_v0;

    temp_v0 = M2C_FIELD(arg0, void **, 0x160);
    var_s0 = M2C_FIELD(temp_v0, u32 *, 0x10);
    temp_s1 = var_s0 + (M2C_FIELD(temp_v0, s32 *, 0xC) << 6);
    if (var_s0 < temp_s1) {
        do {
            temp_a0 = M2C_FIELD(var_s0, s32 *, 0x2C);
            if (temp_a0 != 0) {
                ElimBG_ToggleInstance(temp_a0, arg1);
            }
            var_s0 += 0x40;
        } while (var_s0 < temp_s1);
    }
    var_s0_2 = LIST_GetFirstItem(arg0 + 0x1904);
    if (var_s0_2 != 0) {
        do {
            ElimBG_ToggleInstance(var_s0_2, arg1);
            var_s0_2 = LIST_GetNextItem(var_s0_2);
        } while (var_s0_2 != 0);
    }
}