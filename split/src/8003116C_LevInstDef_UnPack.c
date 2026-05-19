typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

#define NULL 0

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008D2AC;

void LevInstDef_UnPack(void *arg0) {
    u32 tempA1;
    u32 varA0;
    u32 varV1;
    u32 varV1_2;
    void *tempV0;

    varA0 = M2C_FIELD(arg0, u32 *, 0xC);
    tempA1 = varA0 + (M2C_FIELD(arg0, s32 *, 0) * 0x5C);

    if (varA0 < tempA1) {
        do {
            tempV0 = M2C_FIELD(varA0, void **, 0x44);
            if (tempV0 != NULL) {
                tempV0 = M2C_FIELD(tempV0, void **, 8);
                if (tempV0 != NULL) {
                    varV1 = (u32) tempV0;
                    if (M2C_FIELD(varV1, void **, 0) != NULL) {
                        do {
                            M2C_FIELD(varV1, void **, 0) = M2C_FIELD(M2C_FIELD(varV1, void **, 0), void **, 0x2C);
                            varV1 += 4;
                        } while (M2C_FIELD(varV1, void **, 0) != NULL);
                    }
                }
            }

            varA0 += 0x5C;
        } while (varA0 < tempA1);
    }

    varV1_2 = (u32) M2C_FIELD(M2C_FIELD(D_8008D2AC, void **, 0x160), void **, 0x24);
    if ((varV1_2 != 0) && (M2C_FIELD(varV1_2, void **, 0) != NULL)) {
        do {
            M2C_FIELD(varV1_2, void **, 0) = M2C_FIELD(M2C_FIELD(varV1_2, void **, 0), void **, 0x2C);
            varV1_2 += 4;
        } while (M2C_FIELD(varV1_2, void **, 0) != NULL);
    }
}