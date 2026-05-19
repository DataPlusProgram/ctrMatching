typedef signed char s8;
typedef short s16;
typedef int s32;

extern s32 D_8008C098;

s32 ResetRCnt(s32 arg0) {
    s32 tempV1;

    tempV1 = arg0 & 0xFFFF;

    if (tempV1 >= 3) {
        return 0;
    }

    *(s16 *)((s8 *)D_8008C098 + (tempV1 * 0x10)) = 0;
    return 1;
}