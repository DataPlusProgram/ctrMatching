typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK Smart_EnterCriticalSection();               /* extern */
M2C_UNK Smart_ExitCriticalSection();                /* extern */
M2C_UNK SongPool_StopAllCseq();            /* extern */
extern u8 D_8008D05C;
extern void *D_8008D7B0;
extern M2C_UNK D_80095D84;

void CseqMusic_Stop(s32 arg0) {
    u8 *var_s0;
    M2C_UNK *temp_v0;
    s32 var_s1;
    u32 temp_s0;
    u32 var_s2;

    if (D_8008D05C != 0) {
        temp_s0 = arg0 & 0xFFFF;
        if ((D_8008D7B0 != NULL) && (temp_s0 < (u16) M2C_FIELD(D_8008D7B0, u16 *, 6))) {
            Smart_EnterCriticalSection();
            var_s1 = 0;
            var_s2 = temp_s0;
            temp_v0 = &D_80095D84;
            var_s0 = (u8 *) temp_v0;

            do {
                if ((M2C_FIELD(var_s0, u8 *, 0) & 1) && (M2C_FIELD(var_s0, u16 *, 2) == var_s2)) {
                    SongPool_StopAllCseq(var_s0);
                }
                var_s1 += 1;
                var_s0 += 0x7C;
            } while (var_s1 < 2);

            Smart_ExitCriticalSection();
        }
    }
}