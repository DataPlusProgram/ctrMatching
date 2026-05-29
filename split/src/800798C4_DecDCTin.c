typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define STORE_WORD(ptr, val) (*(ptr) = (val))

M2C_UNK DecDCToutCallback_Unknown_80079A74(); /* extern */

void DecDCTin(s32 *arg0, s32 arg1) {
    if (arg1 & 1) {
        *arg0 = *arg0 & 0xF7FFFFFF;
    } else {
        *arg0 = *arg0 | 0x08000000;
    }

    if (arg1 & 2) {
        *arg0 = *arg0 | 0x02000000;
    } else {
        *arg0 = *arg0 & 0xFDFFFFFF;
    }

    DecDCToutCallback_Unknown_80079A74(arg0, *(u16 *)arg0);
}