typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK PROC_DestroyBloodline();              /* extern */
M2C_UNK PROC_DestroySelf();                   /* extern */

void PROC_CheckBloodlineForDead(void **arg0, void *arg1) {
    void **var_s2;
    void *temp_a0;
    void *temp_a1;
    void *temp_s1;
    void *var_s0;

    var_s2 = arg0;
    var_s0 = arg1;
    if (var_s0 != NULL) {
        do {
            temp_s1 = M2C_FIELD(var_s0, void **, 0x10);
            if (M2C_FIELD(var_s0, s32 *, 0x1C) & 0x800) {
                temp_a0 = M2C_FIELD(var_s0, void **, 0x14);
                if (temp_a0 != NULL) {
                    PROC_DestroyBloodline(temp_a0);
                }
                PROC_DestroySelf(var_s0);
                *var_s2 = temp_s1;
            } else {
                temp_a1 = M2C_FIELD(var_s0, void **, 0x14);
                if (temp_a1 != NULL) {
                    PROC_CheckBloodlineForDead(var_s0 + 0x14, temp_a1);
                }
                var_s2 = var_s0 + 0x10;
            }
            var_s0 = temp_s1;
        } while (var_s0 != NULL);
    }
}