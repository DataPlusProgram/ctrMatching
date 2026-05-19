typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ExitCriticalSection();  /* extern */
M2C_UNK HookEntryInt(s8 *arg0); /* extern */

extern M2C_UNK D_8008AF98;
extern u16 *D_8008C028;
extern s32 *D_8008C02C;

M2C_UNK *StopCallback_Unknown_80077770(void) {
    s8 *baseS0;
    s8 *volatile holdBase;
    u16 *tempA0;
    s32 *tempV1;

    baseS0 = (s8 *)&D_8008AF98;
    holdBase = baseS0;
    baseS0 = holdBase;

    if (M2C_FIELD(baseS0, u16 *, 0) != 0) {
        return NULL;
    }

    HookEntryInt(baseS0 + 0x38);

    tempA0 = D_8008C028;
    M2C_FIELD(baseS0, u16 *, 0) = 1;
    *tempA0 = M2C_FIELD(baseS0, u16 *, 0x32);

    tempV1 = D_8008C02C;
    *tempV1 = M2C_FIELD(baseS0, s32 *, 0x34);

    ExitCriticalSection();

    return (M2C_UNK *)baseS0;
}