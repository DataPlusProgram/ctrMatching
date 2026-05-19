typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LIST_AddFront();              /* extern */
M2C_UNK PROC_CheckAllForDead();       /* extern */
extern void *D_8008D2AC;

void LevInstDef_RePack(void *arg0, s32 arg1) {
    register u32 tempV1;
    u32 varA0;
    void *tempS1;
    void *tempV0;
    void *tempV0_3;
    void *tempV1_2;
    register u32 varS0;
    u32 varS0_2;
    register s32 varS2;

    varA0 = M2C_FIELD(arg0, u32 *, 0xC);
    tempV1 = varA0 + (M2C_FIELD(arg0, s32 *, 0) * 0x5C);

    if (varA0 < tempV1) {
        varS2 = arg1;

        do {
            tempV0 = M2C_FIELD(varA0, void **, 0x44);
            if (tempV0 != NULL) {
                tempV0 = M2C_FIELD(tempV0, void **, 8);
                if (tempV0 != NULL) {
                    varS0 = (u32) tempV0;
                    if (M2C_FIELD(varS0, void **, 0) != NULL) {
                        do {
                            M2C_FIELD(varS0, void **, 0) = M2C_FIELD(M2C_FIELD(varS0, void **, 0), void **, 0x2C);
                            varS0 += 4;
                        } while (M2C_FIELD(varS0, void **, 0) != NULL);
                    }
                }
            }
            varA0 += 0x5C;
        } while (varA0 < tempV1);
    } else {
        varS2 = arg1;
    }

    varS0_2 = (u32) M2C_FIELD(M2C_FIELD(D_8008D2AC, void **, 0x160), void **, 0x24);
    if ((varS0_2 != 0) && (M2C_FIELD(varS0_2, void **, 0) != NULL)) {
        do {
            tempV0_3 = M2C_FIELD(varS0_2, void **, 0);
            tempS1 = M2C_FIELD(tempV0_3, void **, 0x2C);

            if (varS2 != 0) {
                tempV1_2 = M2C_FIELD(tempV0_3, void **, 0x6C);
                if (tempV1_2 != NULL) {
                    M2C_FIELD(tempV1_2, s32 *, 0x1C) = M2C_FIELD(tempV1_2, s32 *, 0x1C) | 0x800;
                }
                LIST_AddFront(D_8008D2AC + 0x18F8, M2C_FIELD(varS0_2, void **, 0));
            }

            M2C_FIELD(varS0_2, void **, 0) = tempS1;
            varS0_2 += 4;
        } while (M2C_FIELD(varS0_2, void **, 0) != NULL);
    }

    PROC_CheckAllForDead();
}