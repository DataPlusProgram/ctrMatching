typedef int s32;

extern s32 timeSet1;
extern s32 timeSet2;

void Voiceline_ClearTimeStamp(void) {
    s32 *tempA0;
    s32 *tempV1;
    s32 *varA0;
    s32 *varV1;
    s32 varA1;

    varA1 = 0;
    tempA0 = &timeSet2;
    varA0 = tempA0;
    tempV1 = &timeSet1;
    varV1 = tempV1;

    do {
        *varV1 = 0;
        *varA0 = 0;
        varA0 += 1;
        varA1 += 1;
        varV1 += 1;
    } while (varA1 < 0x10);
}