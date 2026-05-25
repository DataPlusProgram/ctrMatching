typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Channel_DestroyAll_LowLevel(); /* extern */
M2C_UNK CseqMusic_StopAll();                        /* extern */
M2C_UNK Smart_EnterCriticalSection();               /* extern */
M2C_UNK Smart_ExitCriticalSection();                /* extern */
s32 songLoadStage;

void howl_StopAudio(s32 arg0, s32 arg1, M2C_UNK arg2) {
    if (arg1 != 0) {
        CseqMusic_StopAll();
    }
    Smart_EnterCriticalSection();
    Channel_DestroyAll_LowLevel(arg2, arg1 == 0, 2);
    Smart_ExitCriticalSection();
    if (arg0 != 0) {
        songLoadStage = 0;
    }
}