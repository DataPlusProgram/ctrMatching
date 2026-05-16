typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Channel_SearchFX_Destroy(); /* extern */
M2C_UNK Smart_EnterCriticalSection();               /* extern */
M2C_UNK Smart_ExitCriticalSection();                /* extern */

void OtherFX_Stop2(s32 arg0) {
    Smart_EnterCriticalSection();
    Channel_SearchFX_Destroy(1, arg0 & 0xFFFF, 0xFFFF);
    Smart_ExitCriticalSection();
}