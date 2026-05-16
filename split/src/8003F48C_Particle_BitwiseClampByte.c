typedef int s32;

s32 Particle_BitwiseClampByte(s32 *arg0) {
    s32 var_v1;

    var_v1 = *arg0;
    if (var_v1 < 0) {
        var_v1 = 0;
        *arg0 = 0;
    } else if (var_v1 > 0xFF00) {
        var_v1 = 0xFF00;
        *arg0 = 0xFF00;
    }
    return var_v1 >> 8;
}