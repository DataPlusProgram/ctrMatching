typedef int s32;

s32 strncmp(s32, s32, s32);

s32 CdSearchFile_Unknown_80072590(s32 arg0, s32 arg1) {
    return strncmp(arg0, arg1, 0xC) == 0;
}