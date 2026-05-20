typedef int s32;
typedef signed char s8;

extern s8 D_8008AF28[];

s32 CdSyncCallback(s32 arg0);

void strncmp_Unknown_800769B0(void) {
    s8 *baseS0;

    baseS0 = D_8008AF28 - 0x28;

    CdSyncCallback(*(s32 *)(baseS0 + 0x28));

    *(s32 *)(baseS0 + 0x24) = 0;
}