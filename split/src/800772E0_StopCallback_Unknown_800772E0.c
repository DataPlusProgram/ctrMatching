typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ExitCriticalSection();
s32 GPU_Unknown_8007C880();
M2C_UNK HookEntryInt();
M2C_UNK StopCallback_Unknown_800773B8();
M2C_UNK StopCallback_Unknown_800777E8();
M2C_UNK _96_remove();
s32 setjmp();
s32 startIntrDMA();

extern u16 D_8008AF98;
extern M2C_UNK D_8008AFD4;
extern void *D_8008C020;
extern u16 *D_8008C024;
extern volatile u16 *D_8008C028;
extern s32 *D_8008C02C;

void *StopCallback_Unknown_800772E0(void) {
    void *varS0;
    u16 *tempV1;
    volatile u16 *tempV0;
    s32 tempA1;

    varS0 = (void *)&D_8008AF98;
    if (M2C_FIELD(varS0, volatile u16 *, 0) != 0) {
        return NULL;
    }

    tempV1 = D_8008C024;
    tempV0 = D_8008C028;
    tempA1 = 0x33333333;

    *tempV0 = 0;
    *tempV1 = *tempV0;
    *D_8008C02C = tempA1;

    StopCallback_Unknown_800777E8(varS0, 0x41A);

    if (setjmp((s8 *)varS0 + 0x38) != 0) {
        StopCallback_Unknown_800773B8();
    }

    varS0 = &D_8008AFD4;
    M2C_FIELD(varS0, void **, 0) = (s8 *)varS0 + 0xFDC;
    HookEntryInt((s8 *)varS0 - 4);

    M2C_FIELD(varS0, s16 *, -0x3C) = 1;
    M2C_FIELD(D_8008C020, s32 *, 0x14) = GPU_Unknown_8007C880();
    M2C_FIELD(D_8008C020, s32 *, 4) = startIntrDMA();

    _96_remove(D_8008C020);
    ExitCriticalSection();

    varS0 = (s8 *)varS0 - 0x3C;
    return varS0;
}