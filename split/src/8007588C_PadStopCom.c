typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK ChangeClearRCnt();          /* extern */
M2C_UNK SysDeqIntRP();            /* extern */
extern M2C_UNK D_8008C7CC;

void PadStopCom(void) {
    EnterCriticalSection();
    ChangeClearRCnt(3, 1);
    SysDeqIntRP(2, &D_8008C7CC);
    ExitCriticalSection();
}
