typedef int s32;
typedef signed char s8;

#define field(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C094;
extern s32 D_8008C09C;

s32 StartRCnt(s32 arg0)
{
    s32 temp = arg0 & 0xFFFF;
    s32 offset = temp << 2;
    s32 *ptr = D_8008C094;

    ptr[1] |= field(&D_8008C09C, s32 *, offset);

    return temp < 3;
}