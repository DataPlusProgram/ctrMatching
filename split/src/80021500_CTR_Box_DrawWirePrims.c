typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK AddPrim();

void CTR_Box_DrawWirePrims(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, volatile long arg6, s32 arg7, void *arg8) {
    u32 tempT0;
    u32 varA1;
    s32 tempV0;

    tempT0 = M2C_FIELD(arg8, u32 *, 0xC);
    varA1 = 0;
    if (M2C_FIELD(arg8, u32 *, 0x10) >= tempT0) {
        varA1 = tempT0;
        M2C_FIELD(arg8, u32 *, 0xC) = varA1 + 0x10;
    }

    if (varA1 != 0) {
        M2C_FIELD(varA1, s8 *, 3) = 3;
        M2C_FIELD(varA1, s8 *, 7) = 0x40;
        M2C_FIELD(varA1, s8 *, 4) = arg4;

        tempV0 = arg5;
        M2C_FIELD(varA1, s8 *, 5) = tempV0;

        tempV0 = arg6;
        M2C_FIELD(varA1, s16 *, 8) = arg0;
        M2C_FIELD(varA1, s16 *, 0xA) = arg1;
        M2C_FIELD(varA1, s16 *, 0xC) = arg2;
        M2C_FIELD(varA1, s16 *, 0xE) = arg3;
        M2C_FIELD(varA1, s8 *, 6) = tempV0;

        AddPrim(arg7, (void *)varA1);
    }
}