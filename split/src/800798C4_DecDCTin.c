typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define STORE_WORD(ptr, val) (*(ptr) = (val))

M2C_UNK DecDCToutCallback_Unknown_80079A74(); /* extern */

void DecDCTin(s32 *arg0, s32 arg1) {
    s32 tempV0;
    s32 tempV1;

    if (arg1 & 1) {
        tempV1 = 0xF7FFFFFF;
        tempV0 = *arg0 & tempV1;
    } else {
        tempV1 = 0x08000000;
        tempV0 = *arg0 | tempV1;
    }

    STORE_WORD(arg0, tempV0);

    if (arg1 & 2) {
        tempV1 = 0x02000000;
        tempV0 = *arg0 | tempV1;
    } else {
        tempV1 = 0xFDFFFFFF;
        tempV0 = *arg0 & tempV1;
    }

    STORE_WORD(arg0, tempV0);

    DecDCToutCallback_Unknown_80079A74(arg0, *(u16 *)arg0);
}