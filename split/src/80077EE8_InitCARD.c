typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK GPU_Unknown_8007C9C0();              /* extern */
M2C_UNK InitCARD2();                             /* extern */
s32 ReadInitPadFlag();                              /* extern */
M2C_UNK _Unknown_800806E8();                        /* extern */
M2C_UNK _copy_memcard_patch();                      /* extern */
M2C_UNK _patch_card2();                             /* extern */

void InitCARD(s32 arg0) {
    s32 var_s0;

    var_s0 = arg0;
    GPU_Unknown_8007C9C0(0);
    EnterCriticalSection();
    if (ReadInitPadFlag() == 0) {
        var_s0 = 0;
    }
    InitCARD2(var_s0);
    _copy_memcard_patch();
    _Unknown_800806E8();
    _patch_card2();
    ExitCriticalSection();
}