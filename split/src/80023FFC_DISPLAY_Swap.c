typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK PutDispEnv();                    /* extern */
M2C_UNK PutDrawEnv();                            /* extern */
extern void *D_8008D2AC;

void DISPLAY_Swap(void) {
    s32 temp_v0;
    s32 temp_v1;

    temp_v1 = 1 - M2C_FIELD(D_8008D2AC, s32 *, 0xC);
    temp_v0 = D_8008D2AC - ((temp_v1 * 0xA4) - 0xBC);
    M2C_FIELD(D_8008D2AC, s32 *, 0xC) = temp_v1;
    M2C_FIELD(D_8008D2AC, s32 *, 0x14) = temp_v0;
    PutDispEnv(temp_v0 + 0x5C, D_8008D2AC);
    PutDrawEnv(M2C_FIELD(D_8008D2AC, s32 *, 0x14));
}