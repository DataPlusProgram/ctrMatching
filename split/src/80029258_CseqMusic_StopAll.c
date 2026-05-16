#include "../../common.h"


M2C_UNK Smart_EnterCriticalSection();               /* extern */
M2C_UNK Smart_ExitCriticalSection();                /* extern */
M2C_UNK SongPool_StopAllCseq();                 /* extern */
extern u8 D_8008D05C;
extern s32 D_8008D7B0;
extern u8 D_80095D84;

void CseqMusic_StopAll(void) {
    s32 var_s1;
    u8 *var_s0;

    if ((D_8008D05C != 0) && (D_8008D7B0 != 0)) {
        var_s1 = 0;
        Smart_EnterCriticalSection();
        var_s0 = &D_80095D84;
        do {
            if (*var_s0 & 1) {
                SongPool_StopAllCseq(var_s0);
            }
            var_s1 += 1;
            var_s0 += 0x7C;
        } while (var_s1 < 2);
        Smart_ExitCriticalSection();
    }
}