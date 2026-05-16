typedef int s32;

extern s32 *D_8008AE84;
extern s32 *D_8008AE88;

s32 SetDrawEnv_Unknown_800748B8(s32 arg0) {
    *D_8008AE88 = arg0 | 0x10000000;
    return *D_8008AE84 & 0xFFFFFF;
}