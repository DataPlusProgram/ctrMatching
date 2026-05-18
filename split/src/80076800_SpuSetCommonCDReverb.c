typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C3B4;

void SpuSetCommonCDReverb(s32 arg0)
{
    void *ptr;
    s32 value;

    if (arg0 == 0) {
        ptr = D_8008C3B4;
        value = M2C_FIELD(ptr, u16 *, 0x1AA);
        value &= 0xFFFB;
        goto store;
    }

    ptr = D_8008C3B4;
    value = M2C_FIELD(ptr, u16 *, 0x1AA);
    value |= 4;

store:
    M2C_FIELD(ptr, s16 *, 0x1AA) = value;
}