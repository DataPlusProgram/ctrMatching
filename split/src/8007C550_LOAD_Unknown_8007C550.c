typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

extern u8 *D_8008C6E0;
extern s8 *D_8008C6EC;
extern s32 *D_8008C6F0;
extern s32 *D_8008C714;
extern s32 *D_8008C718;
extern s32 *D_8008C71C;
extern s32 *D_8008C720;
extern s32 *D_8008C724;

s32 LOAD_Unknown_8007C550(s32 arg0, s32 arg1) {
    *D_8008C6E0 = 0;
    *D_8008C6EC = 0x80;
    *D_8008C714 = 0x20943;
    *D_8008C6F0 = 0x1323;
    *D_8008C718 |= 0x8000;
    *D_8008C71C = arg0;
    *D_8008C720 = arg1 | 0x10000;
    do {

    } while (!(*D_8008C6E0 & 0x40));
    *D_8008C724 = 0x11000000;
    if (*D_8008C724 & 0x01000000) {
        do {

        } while (*D_8008C724 & 0x01000000);
    }
    *D_8008C6F0 = 0x1325;
    return 0;
}