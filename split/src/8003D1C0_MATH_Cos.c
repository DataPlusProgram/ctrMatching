typedef short s16;
typedef int s32;
typedef unsigned int u32;

extern s32 D_800845A0[];

s32 MATH_Cos(s32 arg0) {
    s32 temp_v1;
    s32 var_v1;

    temp_v1 = D_800845A0[arg0 & 0x3FF];

    if (arg0 & 0x400) {
        var_v1 = (s16) temp_v1;
        if (!(arg0 & 0x800)) {
            var_v1 = -var_v1;
        }
    } else {
        var_v1 = temp_v1 >> 0x10;
        if (arg0 & 0x800) {
            var_v1 = -var_v1;
        }
    }

    return var_v1;
}