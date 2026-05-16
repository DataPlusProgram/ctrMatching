typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK SetRCnt();         /* extern */
M2C_UNK StartRCnt();                         /* extern */
M2C_UNK StopRCnt();                          /* extern */

void Timer_Init(void) {
    EnterCriticalSection();
    StopRCnt(0xF2000001);
    SetRCnt(0xF2000001, 0xFFFF, 0x2000);
    StartRCnt(0xF2000001);
    ExitCriticalSection();
}