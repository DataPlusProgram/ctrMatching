typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern u32 *D_8008AE88;
extern s8 D_8009D2A4[];

void SetDrawEnv_Unknown_800747F8(u32 arg0) {
    *D_8008AE88 = arg0;
    D_8009D2A4[arg0 >> 0x18] = arg0;
}