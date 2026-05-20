typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK PushBuffer_FadeOneWindow();
extern void *D_8008D2AC;

void PushBuffer_FadeAllWindows(void) {
    void *tempA0;
    s32 varS0;
    s32 varS1;

    tempA0 = D_8008D2AC;
    varS0 = 0;

    if (*((u8 *)(((s8 *)tempA0) + 0x1CA8)) != 0) {
        varS1 = 0x168;

        do {
            PushBuffer_FadeOneWindow(tempA0 + varS1);

            tempA0 = D_8008D2AC;
            varS1 += 0x110;
            varS0 += 1;
        } while (varS0 < *((u8 *)(((s8 *)tempA0) + 0x1CA8)));
    }

    tempA0 = D_8008D2AC;
    PushBuffer_FadeOneWindow(tempA0 + 0x1388);
}