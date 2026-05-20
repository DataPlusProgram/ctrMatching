typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C3B4;

void SpuSetCommonCDMix(s32 arg0) {
    void *tempV1;
    s32 tempV0;

    if (arg0 == 0) {
        tempV1 = D_8008C3B4;
        tempV0 = M2C_FIELD(tempV1, u16 *, 0x1AA);
        tempV0 &= 0xFFFE;
    } else {
        tempV1 = D_8008C3B4;
        tempV0 = M2C_FIELD(tempV1, u16 *, 0x1AA);
        tempV0 |= 1;
    }

    M2C_FIELD(tempV1, s16 *, 0x1AA) = tempV0;
}