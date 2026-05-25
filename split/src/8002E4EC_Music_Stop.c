typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK CseqMusic_Stop(); /* extern */

s32 D_8008D820;
s32 D_8008D824;

void Music_Stop(void) {
    if (D_8008D820 != 0) {
        CseqMusic_Stop((u16)D_8008D824);
        D_8008D820 = 0;
        D_8008D824 = -1;
    }
}