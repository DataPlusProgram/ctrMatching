typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK DrawSyncCallback();                      /* extern */
M2C_UNK EnterCriticalSection();                     /* extern */
M2C_UNK ExitCriticalSection();                      /* extern */
M2C_UNK MEMCARD_CloseCard();                        /* extern */
M2C_UNK PadStopCom();                               /* extern */
M2C_UNK ResetGraph();                        /* extern */
M2C_UNK StopCallback();                             /* extern */
M2C_UNK Timer_Destroy();                            /* extern */
M2C_UNK VSyncCallback();                     /* extern */
s32 memcard_fd;

void MainKillGame_StopCTR(void) {
    EnterCriticalSection();
    DrawSyncCallback(memcard_fd);
    ExitCriticalSection();
    StopCallback();
    MEMCARD_CloseCard();
    PadStopCom();
    ResetGraph(3);
    VSyncCallback(0);
    Timer_Destroy();
}