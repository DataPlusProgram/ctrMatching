typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

extern void *D_8009056C;

s32 Channel_FindSound(u16 param_1) {
    void *var_v1;
    void *temp_a1;
    s32 var_v0;

    var_v1 = D_8009056C;
    var_v0 = 0;

    if (var_v1 != 0) {
        do {
            temp_a1 = *((void **) var_v1);

            if ((*((u8 *) ((s8 *) var_v1 + 0xB)) == 1) && (*((u16 *) ((s8 *) var_v1 + 0x18)) == param_1)) {
                var_v0 = 1;
                break;
            }

            var_v1 = temp_a1;
        } while (var_v1 != 0);
    }

    return var_v0;
}