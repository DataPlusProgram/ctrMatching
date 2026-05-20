typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

extern M2C_UNK D_800855A0;
extern M2C_UNK D_800856A0;
extern M2C_UNK D_800857A0;

void MEMCARD_SetIcon(s32 arg0) {
    s8 *src;
    s8 *dst;
    s8 *end;
    s32 tempA1;
    s32 tempA2;
    s32 tempA3;
    s32 tempT0;

    dst = (s8 *)&D_800857A0;
    arg0 <<= 0x10;

    if (arg0 == 0) {
        src = (s8 *)&D_800856A0;
    } else {
        src = (s8 *)&D_800855A0;
        goto blockCopy;
    }

blockCopy:
    end = src + 0x100;

loop:
    tempA1 = *(s32 *)(src + 0);
    tempA2 = *(s32 *)(src + 4);
    tempA3 = *(s32 *)(src + 8);
    tempT0 = *(s32 *)(src + 0xC);

    *(s32 *)(dst + 0) = tempA1;
    *(s32 *)(dst + 4) = tempA2;
    *(s32 *)(dst + 8) = tempA3;
    *(s32 *)(dst + 0xC) = tempT0;

    src += 0x10;
    dst += 0x10;

    if (src != end) {
        goto loop;
    }
}