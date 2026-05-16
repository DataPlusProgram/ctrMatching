typedef int s32;

extern s32 *D_8008AE84;
extern s32 *D_8008AE88;

s32 SetDrawEnv_Unknown_80074830(s32 *arg0, s32 arg1) {
    s32 *var_a0;
    s32 temp_v1;
    s32 var_a2;

    var_a0 = arg0;
    var_a2 = arg1 - 1;
    *D_8008AE88 = 0x04000000;
    if (arg1 != 0) {
        do {
            temp_v1 = *var_a0;
            var_a0 += 1;
            var_a2 -= 1;
            *D_8008AE84 = temp_v1;
        } while (var_a2 != -1);
    }
    return 0;
}