typedef signed char s8;
typedef int s32;

extern s8 D_800962E4[];

void Garage_Leave(void) {
    s32 var_v1;
    s32 temp_a0;
    s8 *base;
    s8 *var_v0;

    temp_a0 = 3;
    var_v1 = 7;
    base = D_800962E4;
    var_v0 = base + 0x54;

    do {
        *var_v0 = temp_a0;
        var_v1 -= 1;
        var_v0 -= 0xC;
    } while (var_v1 >= 0);
}