typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK ChangeClearPAD();                    /* extern */
M2C_UNK InitCARD2();                             /* extern */
s32 ReadInitPadFlag();                              /* extern */
M2C_UNK _patch_card();                             /* extern */
M2C_UNK _copy_memcard_patch();                      /* extern */
M2C_UNK _patch_card2();                             /* extern */

void InitCARD(s32 arg0) {
    s32 var_s0;

    var_s0 = arg0;
    ChangeClearPAD(0);
    EnterCriticalSection();
    if (ReadInitPadFlag() == 0) {
        var_s0 = 0;
    }
    InitCARD2(var_s0);
    _copy_memcard_patch();
    _patch_card();
    _patch_card2();
    ExitCriticalSection();
}
