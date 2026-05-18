typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C094;
extern s32 D_8008C09C[];

s32 StopRCnt(s32 arg0)
{
    s32 *ptr = D_8008C094;
    s32 value = D_8008C09C[arg0 & 0xFFFF];

    ptr[1] &= ~value;

    return 1;
}