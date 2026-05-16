typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

M2C_UNK OtherFX_Play_LowLevel();   /* extern */
extern u32 D_8008D058;

void Level_RandomFX(s32 *arg0, s32 arg1, s32 arg2, u32 arg3, s32 arg4) {
    u32 temp_a0;
    s32 temp_v0;
    u32 temp_v0_2;

    temp_v0 = *arg0;
    if (temp_v0 > 0) {
        *arg0 = temp_v0 - 1;
    }

    if (*arg0 == 0) {
        temp_a0 = (((u32) D_8008D058 >> 3) + (D_8008D058 << 0x1D)) * 5;
        temp_a0 += 1;
        D_8008D058 = temp_a0;

        OtherFX_Play_LowLevel(
            arg1 & 0xFFFF,
            0,
            (((((temp_a0 % 100) + 0x64) * arg4) >> 8) & 0xFF) << 0x10 | 0x01008080
        );

        temp_v0_2 = ((((u32) D_8008D058 >> 3) + (D_8008D058 << 0x1D)) * 5) + 1;
        D_8008D058 = temp_v0_2;
        *arg0 = (temp_v0_2 % arg3) + arg2;
    }
}