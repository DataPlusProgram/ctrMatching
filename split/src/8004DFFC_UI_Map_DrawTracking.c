typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK UI_Map_DrawRawIcon();
extern void *D_8008D2AC;

void UI_Map_DrawTracking(s32 arg0, void *arg1) {
    M2C_UNK varA3;
    void *tempS0;
    void *tempV1;
    void *varS1;
    void *tempD2AC;
    void *newVar;
    s32 tempV0;
    void *tempA1;

    varS1 = arg1;
    if (varS1 != 0) {
        do {
            tempS0 = *((void **)(((s8 *)varS1) + 0x34));
            if (*((s16 *)(((s8 *)(*((void **)(((s8 *)tempS0) + 0x18)))) + 0x10)) == 0x36) {
                UI_Map_DrawRawIcon(arg0, tempS0 + 0x44, 0x20, 0, 0, 0x1000);

                tempV1 = (newVar = *(*((void ***)(((s8 *)(*((void **)(((s8 *)tempS0) + 0x6C)))) + 0x30))));

                varA3 = 4;
                if (tempV1 != 0) {
                    tempD2AC = D_8008D2AC;
                    tempV1 = *((void **)(((s8 *)tempV1) + 0x1C));
                    tempV0 = *((s32 *)(((s8 *)tempD2AC) + 0x1CEC));
                    tempA1 = tempV1 + 0x44;

                    if (tempV0 & 1) {
                        varA3 = 3;
                    }

                    UI_Map_DrawRawIcon(arg0, tempA1, 0x21, varA3, 0, 0x1000);
                }
            }

            varS1 = *((void **)(((s8 *)varS1) + 0x10));
        } while (varS1 != 0);
    }
}