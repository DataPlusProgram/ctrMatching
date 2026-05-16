typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

M2C_UNK DecDCToutCallback_Unknown_80079C24();       /* extern */
extern s32 *D_8008C260;
extern s32 *D_8008C264;
extern s32 *D_8008C268;
extern s32 *D_8008C28C;

void DecDCToutCallback_Unknown_80079B04(s32 arg0, u32 arg1) {
    DecDCToutCallback_Unknown_80079C24();
    *D_8008C28C |= 0x88;
    *D_8008C268 = 0;
    *D_8008C260 = arg0;
    *D_8008C264 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_8008C268 = 0x01000200;
}