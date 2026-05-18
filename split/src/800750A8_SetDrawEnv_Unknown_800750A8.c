typedef int s32;

s32 VSync();                                 /* extern */
extern s32 D_8008AEBC;
extern s32 D_8008AEC0;

void SetDrawEnv_Unknown_800750A8(void) {
    D_8008AEBC = VSync(-1) + 0xF0;
    D_8008AEC0 = 0;
}