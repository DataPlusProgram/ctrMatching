typedef signed char s8;
typedef int s32;

#define field(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C094;
extern s32 D_8008C09C;

s32 StopRCnt(s32 arg0)
{
    s32 offset = (arg0 & 0xFFFF) << 2;
    s32 *ptr = D_8008C094;

    ptr[1] &= ~field(&D_8008C09C, s32 *, offset);

    return 1;
}
