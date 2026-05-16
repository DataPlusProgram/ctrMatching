typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void StCdInterrupt_Unknown_80079650(s32 *arg0, s32 *arg1, u32 arg2) {
    s8 *var_a0;
    s8 *var_a1;
    s32 temp_v0;
    u32 var_v1;

    var_a0 = (s8 *) arg0;
    var_a1 = (s8 *) arg1;
    var_v1 = 0;

    if (arg2 != 0) {
        do {
            temp_v0 = M2C_FIELD(var_a1, s32 *, 0);
            var_a1 += 4;
            var_v1 += 1;
            M2C_FIELD(var_a0, s32 *, 0) = temp_v0;
            var_a0 += 4;
        } while (var_v1 < arg2);
    }
}