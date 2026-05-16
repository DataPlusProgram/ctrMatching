typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

M2C_UNK DecDCToutCallback_Unknown_80079B90();       /* extern */
extern s32 *D_8008C254;
extern s32 *D_8008C258;
extern s32 *D_8008C25C;
extern s32 *D_8008C284;
extern s32 *D_8008C28C;

void DecDCToutCallback_Unknown_80079A74(s32 *arg0, u32 arg1) {
    DecDCToutCallback_Unknown_80079B90();
    *D_8008C28C |= 0x88;
    *D_8008C254 = (s32) ((s8 *) arg0 + 4);
    *D_8008C258 = ((arg1 >> 5) << 0x10) | 0x20;
    *D_8008C284 = *arg0;
    *D_8008C25C = 0x01000201;
}