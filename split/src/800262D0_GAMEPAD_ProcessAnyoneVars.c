typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 GAMEPAD_ProcessHold();
M2C_UNK GAMEPAD_ProcessMotors();
M2C_UNK GAMEPAD_ProcessSticks();
s32 GAMEPAD_ProcessTapRelease();

s32 GAMEPAD_ProcessAnyoneVars(void *arg0) {
    s32 varS1;
    void *varS0;
    s32 tempV0;
    s32 varA1;
    s32 varA2;
    volatile s8 *varA0;

    varS0 = arg0;

    varS1 = GAMEPAD_ProcessHold();
    GAMEPAD_ProcessSticks(varS0);
    varS1 = varS1 | GAMEPAD_ProcessTapRelease(varS0);
    GAMEPAD_ProcessMotors(varS0);

    tempV0 = M2C_FIELD(varS0, s32 *, 0x314);
    varA1 = 0;

    M2C_FIELD(varS0, s32 *, 0x290) = 0;
    M2C_FIELD(varS0, s32 *, 0x294) = 0;
    M2C_FIELD(varS0, s32 *, 0x298) = 0;
    M2C_FIELD(varS0, s32 *, 0x29C) = 0;

    if (tempV0 > 0) {
        varA2 = tempV0;
        varA0 = varS0;

        do {
            M2C_FIELD(varS0, s32 *, 0x290) = M2C_FIELD(varS0, s32 *, 0x290) | *(volatile s32 *)(varA0 + 0x10);
            M2C_FIELD(varS0, s32 *, 0x294) = M2C_FIELD(varS0, s32 *, 0x294) | *(volatile s32 *)(varA0 + 0x14);
            varA1 += 1;
            M2C_FIELD(varS0, s32 *, 0x298) = M2C_FIELD(varS0, s32 *, 0x298) | *(volatile s32 *)(varA0 + 0x18);
            M2C_FIELD(varS0, s32 *, 0x29C) = M2C_FIELD(varS0, s32 *, 0x29C) | *(volatile s32 *)(varA0 + 0x1C);
            varA0 += 0x50;
        } while (varA1 < varA2);
    }

    return varS1;
}