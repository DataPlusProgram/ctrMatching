typedef int s32;
typedef unsigned int u32;

u32 MATH_FastSqrt(u32 arg0, s32 arg1) {
    s32 var_a1;
    u32 temp_a2;
    u32 var_a3;
    u32 var_v1;

    var_a3 = 0;
    var_v1 = 0;
    var_a1 = (arg1 >> 1) + 0xF;

    do {
        var_v1 = (var_v1 << 2) | (arg0 >> 0x1E);
        var_a3 <<= 1;
        temp_a2 = (var_a3 << 1) + 1;
        arg0 <<= 2;

        if (var_v1 >= temp_a2) {
            var_v1 -= temp_a2;
            var_a3 += 1;
        }
    } while (var_a1-- != 0);

    return var_a3;
}