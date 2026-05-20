typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x36E];
    u16 unk36E;
    char pad370[0xBE];
    u16 unk42E;
    char pad430[0x2];
    s16 unk432;
} M2cUIDrawSpeedNeedleArg2;

s32 MATH_Cos();
s32 MATH_Sin();
s16 VehCalc_MapToRange(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern void *D_8008D2AC;

void UI_DrawSpeedNeedle(s32 arg0, s32 arg1, M2cUIDrawSpeedNeedleArg2 *arg2) {
    s32 baseY;
    s32 baseX;
    M2C_UNK varA3;
    s16 tempA3;
    s16 tempS1;
    s16 tempS2;
    s32 *tempV13;
    s32 *tempV15;
    s32 tempT0;
    s32 tempV1;
    s32 varA0;
    s32 varA1;
    s32 varA2;
    s32 varV0;
    s32 varV02;
    s32 varV03;
    s32 varV04;
    s32 varV05;
    s32 varV06;
    s32 stackArg;
    u16 tempV0;
    u16 tempV02;
    u32 tempA0;
    u32 tempA02;
    u32 varS0;
    u32 varS02;
    void *tempV12;
    void *tempV14;

    baseY = arg1;

    tempV0 = arg2->unk42E;
    tempT0 = tempV0 << 0x10;

    varA2 = (((s32)((s16)tempV0 + arg2->unk432) >> 8) * 0x1A5E0) / 64000;

    baseX = arg0;

    tempV02 = arg2->unk36E;
    tempV1 = tempV02 << 0x10;
    varA1 = 0;

    if ((s16)tempV0 >= (s16)tempV02) {
        varA0 = ((tempV1 >> 0x18) * 0x1A5E0) / 64000;
        varA2 = ((tempT0 >> 0x18) * 0x1A5E0) / 64000;
        varA3 = 0xD90;
        stackArg = 0x980;
    } else {
        varA0 = ((tempV1 >> 0x18) * 0x1A5E0) / 64000;
        varA1 = ((tempT0 >> 0x18) * 0x1A5E0) / 64000;
        varA3 = 0x980;
        stackArg = 0x700;
    }

    varS0 = 0;
    tempA3 = VehCalc_MapToRange(varA0, varA1, varA2, varA3, stackArg);

    tempV12 = M2C_FIELD(D_8008D2AC, void **, 0x10);
    tempA0 = M2C_FIELD(tempV12, u32 *, 0x80);

    if ((u32)M2C_FIELD(tempV12, u32 *, 0x84) >= tempA0) {
        varS0 = tempA0;
        M2C_FIELD(tempV12, u32 *, 0x80) = tempA0 + 0x1C;
    }

    if (varS0 != 0) {
        tempS1 = tempA3;
        tempS2 = tempS1 + 0x400;

        M2C_FIELD(varS0, s32 *, 4) = 0x30005B5B;
        M2C_FIELD(varS0, s32 *, 0xC) = 0x30012B32;
        M2C_FIELD(varS0, s32 *, 0x14) = 0x3000BBFF;

        M2C_FIELD(varS0, s16 *, 0x18) = baseX + (((MATH_Sin(tempS2) * 3) >> 0xB) + 0x41);

        varV0 = ((MATH_Cos(tempS2) * 4) >> 0xB) * 0x140;
        if (varV0 < 0) {
            varV0 += 0x1FF;
        }
        M2C_FIELD(varS0, s16 *, 0x1A) = baseY + ((varV0 >> 9) + 0x29);

        M2C_FIELD(varS0, s16 *, 0x10) = baseX - (((MATH_Sin(tempS1) * 3) >> 0xB) - 0x41);

        varV02 = ((MATH_Cos(tempS1) * 3) >> 0xB) * 0x140;
        if (varV02 < 0) {
            varV02 += 0x1FF;
        }
        M2C_FIELD(varS0, s16 *, 0x12) = baseY - ((varV02 >> 9) - 0x29);

        M2C_FIELD(varS0, s16 *, 8) = baseX + (((MATH_Sin(tempS1) * 0x1E) >> 0xB) + 0x41);

        varV03 = ((MATH_Cos(tempS1) * 0x1E) >> 0xB) * 0x140;
        if (varV03 < 0) {
            varV03 += 0x1FF;
        }
        M2C_FIELD(varS0, s16 *, 0xA) = baseY + ((varV03 >> 9) + 0x29);

        tempV13 = M2C_FIELD(D_8008D2AC, s32 **, 0x147C);
        M2C_FIELD(varS0, s32 *, 0) = *tempV13 | 0x06000000;
        *tempV13 = varS0 & 0xFFFFFF;

        tempV14 = M2C_FIELD(D_8008D2AC, void **, 0x10);
        tempA02 = M2C_FIELD(tempV14, u32 *, 0x80);
        varS02 = 0;

        if ((u32)M2C_FIELD(tempV14, u32 *, 0x84) >= tempA02) {
            varS02 = tempA02;
            M2C_FIELD(tempV14, u32 *, 0x80) = varS02 + 0x1C;
        }

        if (varS02 != 0) {
            M2C_FIELD(varS02, s32 *, 4) = 0x30FFFFFF;
            M2C_FIELD(varS02, s32 *, 0xC) = 0x3000699C;
            M2C_FIELD(varS02, s32 *, 0x14) = 0x3000FFFF;

            M2C_FIELD(varS02, s16 *, 0x18) = baseX - (((MATH_Sin(tempS2) * 3) >> 0xB) - 0x41);

            varV04 = ((MATH_Cos(tempS2) * 4) >> 0xB) * 0x140;
            if (varV04 < 0) {
                varV04 += 0x1FF;
            }
            M2C_FIELD(varS02, s16 *, 0x1A) = baseY - ((varV04 >> 9) - 0x29);

            M2C_FIELD(varS02, s16 *, 0x10) = baseX - (((MATH_Sin(tempS1) * 3) >> 0xB) - 0x41);

            varV05 = ((MATH_Cos(tempS1) * 3) >> 0xB) * 0x140;
            if (varV05 < 0) {
                varV05 += 0x1FF;
            }
            M2C_FIELD(varS02, s16 *, 0x12) = baseY - ((varV05 >> 9) - 0x29);

            M2C_FIELD(varS02, s16 *, 8) = baseX + (((MATH_Sin(tempS1) * 0x1E) >> 0xB) + 0x41);

            varV06 = ((MATH_Cos(tempS1) * 0x1E) >> 0xB) * 0x140;
            if (varV06 < 0) {
                varV06 += 0x1FF;
            }
            M2C_FIELD(varS02, s16 *, 0xA) = baseY + ((varV06 >> 9) + 0x29);

            tempV15 = M2C_FIELD(D_8008D2AC, s32 **, 0x147C);
            M2C_FIELD(varS02, s32 *, 0) = *tempV15 | 0x06000000;
            *tempV15 = varS02 & 0xFFFFFF;
        }
    }
}