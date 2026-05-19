typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK OtherFX_Play_LowLevel();
M2C_UNK Voiceline_RequestPlay();

extern s16 D_80086E84[];

void VehFire_Audio(void *arg0, s32 arg1) {
    s32 tempA0;
    s32 varA1;
    s32 varA2;
    s32 varS0;
    s32 varS1;
    s32 varV0;
    void *varS2;

    varS2 = arg0;

    if (M2C_FIELD(varS2, s16 *, 0x3E0) == 0) {
        varS1 = 0x80;

        if (arg1 >= 0x40) {
            varS1 = 0xC0;

            if (arg1 >= 0x80) {
                varS1 = 0xFF;
                varS0 = 0x6C;
                tempA0 = 0x10;
                Voiceline_RequestPlay(tempA0, D_80086E84[M2C_FIELD(varS2, u8 *, 0x4A)], tempA0);
                goto block_7;
            }

            goto block_5;
        }

        goto block_6;

block_5:
        varS0 = 0x80;
        goto block_7;

block_6:
        varS0 = 0x94;

block_7:
        varA1 = varS1 << 0x10;
        tempA0 = varS0 << 8;

        if (M2C_FIELD(varS2, s32 *, 0x2C8) & 0x10000) {
            varV0 = varA1 | (tempA0 | 0x01000000);
        } else {
            varV0 = varA1 | tempA0;
        }

        varA2 = varV0 | 0x80;
        OtherFX_Play_LowLevel(0xD, 1, varA2);
        M2C_FIELD(varS2, s16 *, 0x3E0) = 0xF0;
    }
}