typedef int s32;

extern s32 *D_8008AE88;
extern s32 *D_8008AE8C;
extern s32 *D_8008AE90;
extern s32 *D_8008AE94;

void SetDrawEnv_Unknown_80074870(s32 arg0) {
    *D_8008AE88 = 0x04000002;
    *D_8008AE8C = arg0;
    *D_8008AE90 = 0;
    *D_8008AE94 = 0x01000401;
}