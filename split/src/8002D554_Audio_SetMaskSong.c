typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK Music_Adjust(); /* extern */
extern void *D_8008D2AC;

void Audio_SetMaskSong(s32 arg0) {
    void *var_a0;
    s32 var_a2;
    s32 var_v1;
    s32 temp_v0;
    s32 temp_v1;
    u8 temp_v0_2;

    var_a2 = 0;
    var_a0 = D_8008D2AC;
    temp_v0_2 = M2C_FIELD(var_a0, u8 *, 0x1CA8);

    if (temp_v0_2 != 0) {
        var_v1 = 0;
        do {
            if (M2C_FIELD(M2C_FIELD(var_a0, void **, 0x24EC), s32 *, 0x2C8) & 0x800000) {
                var_a2 = 1;
            }

            var_v1 += 1;
            var_a0 = (void *)((s8 *)var_a0 + 4);
        } while (var_v1 < temp_v0_2);
    }

    temp_v0 = var_a2;
    if (temp_v0 != 0) {
        temp_v1 = M2C_FIELD(D_8008D2AC, s32 *, 0);

        if (temp_v1 & 0x02000000) {
            Music_Adjust(2, arg0, 0, 0);
        } else if (temp_v1 & 0x01000000) {
            Music_Adjust(1, arg0, 0, 0);
        }
    } else {
        Music_Adjust(0, arg0, 0, 0);

        var_a0 = D_8008D2AC;
        temp_v1 = M2C_FIELD(var_a0, s32 *, 0);

        if (temp_v1 & 0x02000000) {
            M2C_FIELD(var_a0, s32 *, 0) = temp_v1 & 0xFDFFFFFF;

            var_a0 = D_8008D2AC;
            temp_v1 = M2C_FIELD(var_a0, s32 *, 0);
        }

        if (temp_v1 & 0x01000000) {
            M2C_FIELD(var_a0, s32 *, 0) = temp_v1 & 0xFEFFFFFF;
        }
    }
}