typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK Bank_DestroyAll();                          /* extern */
M2C_UNK CTR_ErrorScreen(); /* extern */
M2C_UNK LoadExec();      /* extern */
M2C_UNK MainKillGame_StopCTR();                     /* extern */
M2C_UNK Music_Stop();                               /* extern */
M2C_UNK VSync();                             /* extern */
M2C_UNK _96_init();                                 /* extern */
M2C_UNK _96_remove();                               /* extern */
M2C_UNK howl_Disable();                             /* extern */
M2C_UNK howl_StopAudio();  /* extern */
extern M2C_UNK D_80011458;

void MainKillGame_LaunchSpyro2(void) {
    CTR_ErrorScreen(0, 0, 0);
    Music_Stop();
    howl_StopAudio(1, 1, 1);
    Bank_DestroyAll();
    howl_Disable();
    VSync(0x1E);
    MainKillGame_StopCTR();
    _96_remove();
    _96_init();
    LoadExec(&D_80011458, 0x801FFF00, 0);
}