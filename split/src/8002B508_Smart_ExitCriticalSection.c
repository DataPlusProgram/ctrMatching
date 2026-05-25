typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK ExitCriticalSection();                      /* extern */
s32 OptionSlider_soundID;

void Smart_ExitCriticalSection(void) {
    s32 temp_v0;

    if (OptionSlider_soundID != 0) {
        temp_v0 = OptionSlider_soundID - 1;
        OptionSlider_soundID = temp_v0;
        if (temp_v0 == 0) {
            ExitCriticalSection();
        }
    }
}