typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK _Unknown_8007E740();

extern void *D_8008C7A0;
extern s32 D_8008C7A4;
extern s32 D_8008C7B8;
extern s32 D_8008C814;

void PadInitMtap(s32 arg0, s32 arg1) {
    s32 *varT5;
    s32 *varA2;
    s32 varA3;
    s32 varT0;
    s32 varT1;
    s32 varT2;
    s32 varT6;
    s32 varV1;
    s32 varV12;
    u8 *varA1;
    u8 *varA12;
    void *varA0;
    void *varT3;

    D_8008C7A4 = 0;
    D_8008C7B8 = 1;
    _Unknown_8007E740();

    varT6 = 0;
    varT5 = &D_8008C814;
    varT3 = D_8008C7A0;
    varA2 = (s32 *)((s8 *)varT3 + 0x40);

    M2C_FIELD(varT3, s32 *, 0x30) = arg0;
    M2C_FIELD(varT3, s32 *, 0x120) = arg1;

    do {
        varA1 = (u8 *)varT3 + 0x5D;

        varA2[-12] = (s32)varT3;
        M2C_FIELD((void *)varA2[-4], u8 *, 0) = 0xFF;

        varV1 = 5;
        M2C_FIELD((void *)varA2[-4], u8 *, 1) = 0;
        *varT5 = 0;

loop2:
        *varA1 = 0xFF;
        varV1 -= 1;
        varA1 += 1;
        if (varV1 >= 0) {
            goto loop2;
        }

        varT0 = varA2[-13];
        varT2 = 0;
        varT1 = 3;
        varA3 = 2;
        varA0 = (void *)(varT0 + 0x40);

loop4:
        M2C_FIELD(varA0, void **, -0x30) = varT3;
        M2C_FIELD(varA0, s32 *, -0x10) = varA2[-4] + varA3;

        M2C_FIELD(varA0, u8 *, -8) = 0xFF;
        M2C_FIELD(varA0, u8 *, -0xA) = 0;
        M2C_FIELD(varA0, u8 *, -0xC) = 0;

        M2C_FIELD(M2C_FIELD(varA0, void **, -0x10), u8 *, 0) = 0xFF;
        M2C_FIELD(M2C_FIELD(varA0, void **, -0x10), u8 *, 1) = 0;

        varA12 = (u8 *)varT0 + 0x5D;
        M2C_FIELD(varA0, s32 *, -4) = varA2[-1] + varA3;

        varV12 = 5;
        M2C_FIELD(varA0, s32 *, 0) = varA2[0] + varT1;

loop5:
        *varA12 = 0xFF;
        varV12 -= 1;
        varA12 += 1;
        if (varV12 >= 0) {
            goto loop5;
        }

        varT1 += 8;
        varA3 += 8;
        varT2 += 1;
        varA0 += 0xF0;
        varT0 += 0xF0;

        if (varT2 < 4) {
            goto loop4;
        }

        varT5 += 1;
        varT6 += 1;
        varA2 += 0x3C;
        varT3 += 0xF0;
    } while (varT6 < 2);

    D_8008C7A4 = 1;
}