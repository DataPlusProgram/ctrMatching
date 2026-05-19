typedef signed char s8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void PROC_CollidePointWithSelf(void *arg0, void *arg1) {
    void *tempT1;
    s32 tempT2;
    s32 tempA3;
    void *tempA0;
    s32 tempV1;
    s32 tempT0;
    s32 tempA1;
    s32 tempA2;
    s32 tempLo2;
    s32 tempLo3;

    if (!(M2C_FIELD(arg0, s32 *, 0x1C) & 0x1800)) {
        tempT1 = arg1;
        tempA0 = M2C_FIELD(arg0, void **, 0x34);

        tempV1 = M2C_FIELD(tempT1, s16 *, 0);
        tempT2 = tempV1 - M2C_FIELD(tempA0, s32 *, 0x44);
        tempA3 = tempT2 * tempT2;
        tempT0 = 0x0FFFFFFF;

        tempA2 = M2C_FIELD(tempT1, s16 *, 2) - M2C_FIELD(tempA0, s32 *, 0x48);
        tempA1 = M2C_FIELD(tempT1, s16 *, 4) - M2C_FIELD(tempA0, s32 *, 0x4C);

        if (tempA3 <= tempT0) {
            tempLo2 = tempA2 * tempA2;
            tempA3 += tempLo2;

            if (tempLo2 <= tempT0) {
                tempLo3 = tempA1 * tempA1;
                tempA3 += tempLo3;

                if ((tempLo3 <= tempT0) && (tempA3 < M2C_FIELD(tempT1, s32 *, 0xC))) {
                    M2C_FIELD(tempT1, s32 *, 0xC) = tempA3;
                    M2C_FIELD(tempT1, void **, 8) = arg0;
                    M2C_FIELD(tempT1, s16 *, 0x10) = tempT2;
                    M2C_FIELD(tempT1, s16 *, 0x12) = tempA2;
                    M2C_FIELD(tempT1, s16 *, 0x14) = tempA1;
                }
            }
        }
    }
}