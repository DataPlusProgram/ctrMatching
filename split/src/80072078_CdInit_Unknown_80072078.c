typedef int s32;

s32 LOAD_InitCDvol();
s32 LOAD_Unknown_8007C208();

s32 CdInit_Unknown_80072078(void) {
    s32 ret;

    if (LOAD_Unknown_8007C208() == 0) {
        ret = LOAD_InitCDvol() == 0;
    } else {
        ret = 0;
    }

    return ret;
}