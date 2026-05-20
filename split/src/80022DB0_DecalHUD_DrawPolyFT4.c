typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void DecalHUD_DrawPolyFT4(void *arg0, s32 arg1, s32 arg2, void *arg3, s32 *arg4, u8 arg5, s32 arg6) {
    void *tempT3;
    s32 tempT4;
    s32 tempT1;
    s32 *tempT7;
    s32 tempA0;
    s32 tempA1;
    s32 tempA2;
    s32 tempT2;
    s32 tempT5;
    s32 tempT6;
    s32 tempV0;
    s32 tempV1;
    void *tempT0;

    tempT3 = arg0;
    tempT4 = arg1;
    tempT7 = arg4;
    tempA0 = arg6;
    tempT2 = arg5;

    arg0 = (void *)tempA0;

    if (tempT3 != NULL) {
        tempT1 = arg2;
        tempA0 = (s16)(s32)arg0;

        tempA1 = M2C_FIELD(tempT3, s32 *, 0x18);
        tempA2 = M2C_FIELD(tempT3, s32 *, 0x14);

        tempV1 = tempA1 & 0xFF;
        tempV0 = tempA2 & 0xFF;
        tempV1 -= tempV0;
        tempT5 = (tempV1 * tempA0) >> 0xC;

        tempV0 = tempA2 >> 8;
        tempV1 = M2C_FIELD(tempT3, u8 *, 0x1D);
        tempV0 &= 0xFF;
        tempV1 -= tempV0;
        tempT6 = (tempV1 * tempA0) >> 0xC;

        tempT1 = tempT1 << 0x10;
        tempA0 = tempT2 & 0xFF;
        tempT2 = M2C_FIELD(tempT3, s32 *, 0x1C);
        tempT0 = M2C_FIELD(arg3, void **, 0xC);

        if (tempA0 != 0) {
            tempV1 = tempA1 & 0xFF9FFFFF;
            tempV0 = 0x2F;
            M2C_FIELD(tempT0, s8 *, 7) = tempV0;
            tempV0 = tempA0 - 1;
            tempV0 <<= 0x15;
            tempV1 |= tempV0;
            M2C_FIELD(tempT0, s32 *, 0x14) = tempV1;
        } else {
            tempV0 = 0x2D;
            M2C_FIELD(tempT0, s8 *, 7) = tempV0;
            M2C_FIELD(tempT0, s32 *, 0x14) = tempA1;
        }

        tempA1 = 0x00FFFFFF;
        tempV0 = tempT4 | tempT1;

        M2C_FIELD(tempT0, s32 *, 0xC) = tempA2;
        M2C_FIELD(tempT0, s16 *, 0x1C) = tempT2;

        tempA2 = M2C_FIELD(tempT3, u16 *, 0x1E);
        tempA0 = tempT4 + tempT5;

        M2C_FIELD(tempT0, s32 *, 8) = tempV0;

        tempV0 = tempA0 | tempT1;
        M2C_FIELD(tempT0, s32 *, 0x10) = tempV0;

        tempV0 = tempT6 << 0x10;
        tempV0 = tempT1 + tempV0;

        tempV1 = tempT4 | tempV0;
        tempA0 = tempA0 | tempV0;

        M2C_FIELD(tempT0, s32 *, 0x18) = tempV1;

        tempV1 = 0x09000000;
        M2C_FIELD(tempT0, s32 *, 0x20) = tempA0;
        M2C_FIELD(tempT0, u16 *, 0x24) = tempA2;

        tempV0 = *tempT7;
        tempA1 = (s32)tempT0 & tempA1;
        tempV0 |= tempV1;
        M2C_FIELD(tempT0, s32 *, 0) = tempV0;

        tempV0 = (s32)tempT0 + 0x28;
        *tempT7 = tempA1;
        M2C_FIELD(arg3, void **, 0xC) = (void *)tempV0;
    }
}