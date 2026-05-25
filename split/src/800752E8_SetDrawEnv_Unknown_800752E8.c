typedef signed char s8;
typedef int s32;

void SetDrawEnv_Unknown_800752E8(s8 *arg0, s8 arg1, s32 arg2) {
    s32 var_v0;

    var_v0 = arg2 - 1;
    if (arg2 != 0) {
        do {
            *arg0 = arg1;
            var_v0 -= 1;
            arg0 += 1;
        } while (var_v0 != -1);
    }
}