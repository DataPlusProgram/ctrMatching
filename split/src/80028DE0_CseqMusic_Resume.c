typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Smart_EnterCriticalSection();               /* extern */
M2C_UNK Smart_ExitCriticalSection();       /* extern */
extern u8 D_8008D05C;
extern s32 D_8008D7B0;
extern u8 D_80095D84;

void CseqMusic_Resume(void) {
    s32 var_a1;
    u8 *var_a0;
    u8 temp_v1;

    if ((D_8008D05C != 0) && (D_8008D7B0 != 0)) {
        Smart_EnterCriticalSection();
        var_a1 = 0;
        var_a0 = &D_80095D84;
        do {
            temp_v1 = *var_a0;
            if (temp_v1 & 1) {
                *var_a0 = temp_v1 & 0xFD;
            }
            var_a1 += 1;
            var_a0 += 0x7C;
        } while (var_a1 < 2);
        Smart_ExitCriticalSection(var_a0, var_a1);
    }
}