typedef int s32;

s32 D_8008D820;
s32 D_8008D824;

void Music_Start(s32 arg0) {
    D_8008D820 = 1;
    D_8008D824 = arg0 & 0xFFFF;
}