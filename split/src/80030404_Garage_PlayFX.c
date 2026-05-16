typedef signed char s8;
typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK OtherFX_Play_LowLevel(); /* extern */
extern u32 D_8008D058;
extern u8 D_800962E4[];

void Garage_PlayFX(s32 arg0, s32 arg1, s32 arg2, u32 arg3) {
    u32 temp_v1;
    u32 temp_q;
    void *temp_v0;

    if (arg1 < 8) {
        if (arg0 == 0xF6) {
            temp_v1 = (((u32)D_8008D058 >> 3) + (D_8008D058 << 0x1D)) * 5;
            temp_v1 += 1;
            D_8008D058 = temp_v1;

            temp_q = temp_v1 / 3U;
            arg0 = (temp_v1 - ((temp_q * 2) + temp_q)) + 0xF3;
        }

        temp_v0 = &D_800962E4[arg1 * 0xC];
        OtherFX_Play_LowLevel(arg0 & 0xFFFF, 1, (M2C_FIELD(temp_v0, u8 *, 2) << 0x10) | (M2C_FIELD(temp_v0, u8 *, 4) | 0x8000), arg3);
    }
}