typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK OtherFX_Stop1();                         /* extern */

void OtherFX_RecycleMute(s32 *arg0) {
    s32 temp_a0;

    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        OtherFX_Stop1(temp_a0);
        *arg0 = 0;
    }
}