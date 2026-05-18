typedef int s32;

#define NULL 0

s32 Timer_GetTime_Total();                          /* extern */

s32 Timer_GetTime_Elapsed(s32 arg0, s32 *arg1) {
    s32 var_v1;

    var_v1 = Timer_GetTime_Total();
    if (arg1 != NULL) {
        *arg1 = var_v1;
    }
    if (var_v1 < arg0) {
        var_v1 += 0xC7E18;
    }
    return var_v1 - arg0;
}