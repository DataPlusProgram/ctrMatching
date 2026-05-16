typedef int s32;

s32 VehPhysGeneral_LerpQuarterStrength(s32 arg0, s32 arg1) {
    s32 var_a1;
    s32 var_v0;
    s32 var_v1;

    var_a1 = arg1;
    var_v0 = arg0;
    if (var_a1 != 0) {
        var_a1 = var_a1 >> 2;
        var_v1 = var_v0 < var_a1;
        if (var_a1 == 0) {
            var_a1 = 1;
            goto block_3;
        }
    } else {
block_3:
        var_v1 = var_v0 < var_a1;
    }
    if (var_v1 == 0) {
        var_v0 = var_a1;
    }
    return var_v0;
}