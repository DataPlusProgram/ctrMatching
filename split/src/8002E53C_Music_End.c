typedef int s32;

extern s32 D_8008D820 = 0;
extern s32 D_8008D824 = 0;

void Music_End(void) {
    D_8008D820 = 0;
    D_8008D824 = -1;
}