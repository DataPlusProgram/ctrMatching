typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK GPU_Unknown_8007C9C0();              /* extern */
M2C_UNK StartCARD2();                               /* extern */

void StartCARD(void) {
    EnterCriticalSection();
    StartCARD2();
    GPU_Unknown_8007C9C0(0);
    ExitCriticalSection();
}