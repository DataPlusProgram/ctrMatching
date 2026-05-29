typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK ElimBG_Deactivate();                     /* extern */
M2C_UNK LOAD_LevelFile();                        /* extern */
M2C_UNK howl_StopAudio();  /* extern */
s32 s_OTMem;

void MainRaceTrack_StartLoad(s16 arg0) {
    howl_StopAudio(1, 0, 0);
    ElimBG_Deactivate(s_OTMem);
    LOAD_LevelFile(arg0);
}