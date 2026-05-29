typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK OtherFX_Stop2();                     /* extern */
M2C_UNK howl_PauseAudio();                          /* extern */
M2C_UNK howl_StopAudio();  /* extern */
M2C_UNK howl_UnPauseAudio();                        /* extern */
s32 D_8008D8B8;

void MainFrame_TogglePauseAudio(s32 arg0) {
    if (arg0 != 0) {
        if (D_8008D8B8 == 0) {
            OtherFX_Stop2(1);
            howl_PauseAudio();
            D_8008D8B8 = 1;
        }
    } else if (D_8008D8B8 != 0) {
        howl_StopAudio(0, 0, 1);
        howl_UnPauseAudio();
        D_8008D8B8 = 0;
    }
}