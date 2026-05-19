typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

extern s32 D_8008C098;

u16 GetRCnt(s32 arg0) {
    s32 tempV1;

    tempV1 = arg0 & 0xFFFF;

    if (tempV1 >= 3) {
        return 0U;
    }

    tempV1 <<= 4;
    return *(u16 *)((s8 *)D_8008C098 + tempV1);
}