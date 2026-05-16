typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK (*D_8008C734)();
extern s32 D_8008C754;

void GPU_Unknown_8007C8D8(void) {
    s8 *var_s0;
    M2C_UNK (*temp_v0)();
    s32 var_s1;

    var_s1 = 0;
    var_s0 = (s8 *) &D_8008C734;
    D_8008C754 += 1;

    do {
        temp_v0 = M2C_FIELD(var_s0, M2C_UNK (**)(), 0);
        if (temp_v0 != NULL) {
            temp_v0();
        }

        var_s1 += 1;
        var_s0 += 4;
    } while (var_s1 < 8);
}