typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CseqMusic_Restart();            /* extern */
s32 D_8008D820;
u16 D_8008D824;

void Music_Restart(void) {
    if (D_8008D820 != 0) {
        CseqMusic_Restart(D_8008D824, 8);
    }
}