typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK OtherFX_Modify();                   /* extern */
s32 OtherFX_Play_LowLevel();       /* extern */
M2C_UNK OtherFX_Stop1();                         /* extern */

void Level_SoundLoopSet(s32 *arg0, s32 arg1, s32 arg2) {
    s32 temp_a0;
    s32 temp_a0_2;

    if (arg2 == 0) {
        temp_a0 = *arg0;
        if (temp_a0 != 0) {
            OtherFX_Stop1(temp_a0);
            *arg0 = 0;
        }
    } else {
        temp_a0_2 = *arg0;
        if (temp_a0_2 == 0) {
            *arg0 = OtherFX_Play_LowLevel(arg1 & 0xFFFF, 0, ((arg2 & 0xFF) << 0x10) | 0x8080);
            return;
        }
        OtherFX_Modify(temp_a0_2, ((arg2 & 0xFF) << 0x10) | 0x8080);
    }
}