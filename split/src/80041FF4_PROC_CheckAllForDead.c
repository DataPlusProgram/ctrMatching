typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK PROC_CheckBloodlineForDead();       /* extern */
extern s32 D_8008D2AC;

void PROC_CheckAllForDead(void) {
    s32 temp_a0;
    s32 temp_a1;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;

    var_s2 = 0;
    var_s1 = 0x1B2C;
    var_s0 = 0;
    do {
        var_s2 += 1;
        temp_a0 = D_8008D2AC + var_s1;
        var_s1 += 0x14;
        temp_a1 = M2C_FIELD((D_8008D2AC + var_s0), s32 *, 0x1B2C);
        var_s0 += 0x14;
        PROC_CheckBloodlineForDead(temp_a0, temp_a1);
    } while (var_s2 < 0x12);
}