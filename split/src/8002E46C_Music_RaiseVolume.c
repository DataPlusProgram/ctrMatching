typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

M2C_UNK CseqMusic_ChangeVolume(); /* extern */
s32 D_8008D820;
s32 D_8008D824;

void Music_RaiseVolume(void) {
    M2C_UNK var_a1;

    if (D_8008D820 != 0) {
        var_a1 = 0xFF;
        if ((u32) (D_8008D824 - 1) < 2U) {

        } else {
            var_a1 = 0xBE;
        }
        CseqMusic_ChangeVolume((u16) D_8008D824, var_a1, 8);
    }
}