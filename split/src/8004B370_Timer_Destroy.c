typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK StopRCnt();                          /* extern */

void Timer_Destroy(void) {
    EnterCriticalSection();
    StopRCnt(0xF2000001);
    ExitCriticalSection();
}