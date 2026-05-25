typedef unsigned char u8;
typedef int s32;

u8 *howl_GetNextNote(u8 *arg0, s32 *arg1) {
    u8 *var_a2;
    s32 var_a0;
    s32 temp_v0;

    var_a2 = arg0;
    var_a0 = *var_a2;
    var_a2++;

    if (var_a0 & 0x80) {
        var_a0 &= 0x7F;

        do {
            temp_v0 = *var_a2;
            var_a2++;
            var_a0 = (var_a0 << 7) + (temp_v0 & 0x7F);
        } while (temp_v0 & 0x80);
    }

    *arg1 = var_a0;
    return var_a2;
}