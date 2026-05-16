typedef int s32;

s32 SelectProfile_UI_ConvertX(s32 arg0, s32 arg1) {
    s32 var_v0;

    var_v0 = (arg0 - 0x100) * arg1;
    if (var_v0 < 0) {
        var_v0 += 0xFF;
    }
    return var_v0 >> 8;
}