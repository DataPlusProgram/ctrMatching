typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK GPU_Unknown_8007C9D0();     /* extern */
M2C_UNK SysDeqIntRP();            /* extern */
extern M2C_UNK D_8008C7CC;

void PadStopCom(void) {
    EnterCriticalSection();
    GPU_Unknown_8007C9D0(3, 1);
    SysDeqIntRP(2, &D_8008C7CC);
    ExitCriticalSection();
}