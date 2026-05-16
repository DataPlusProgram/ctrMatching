typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK LIST_AddBack();                     /* extern */

void LIST_Init(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 var_s0;
    s32 var_s1;

    var_s1 = arg1;
    var_s0 = arg3 - 1;
    if (arg3 != 0) {
        do {
            LIST_AddBack(arg0, var_s1);
            var_s0 -= 1;
            var_s1 += arg2;
        } while (var_s0 != -1);
    }
}