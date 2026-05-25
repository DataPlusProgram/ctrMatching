typedef int s32;

extern s32 D_8008C420;

s32 CdReadyCallback(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8008C420;
    D_8008C420 = arg0;
    return temp_v0;
}