typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void StopCallback_Unknown_800777E8(s32 *arg0, s32 arg1) {
    s8 *var_a0;
    s32 var_v0;

    var_a0 = (s8 *) arg0;
    var_v0 = arg1 - 1;

    if (arg1 != 0) {
        do {
            M2C_FIELD(var_a0, s32 *, 0) = 0;
            var_v0 -= 1;
            var_a0 += 4;
        } while (var_v0 != -1);
    }
}