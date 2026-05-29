typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 s_OTMem;

void MainStats_ClearBattleVS(void) {
    s32 var_a0;
    s32 var_a1;
    s32 var_a2;
    s32 var_v1;

    var_a2 = 0;
    var_a1 = 0;
    do {
        var_a0 = 0;
        var_v1 = var_a1;
loop_2:
        M2C_FIELD((s_OTMem + var_v1), s32 *, 0x1E80) = 0;
        var_a0 += 1;
        var_v1 += 4;
        if (var_a0 < 3) {
            goto loop_2;
        }
        var_a2 += 1;
        var_a1 += 0xC;
    } while (var_a2 < 4);
}