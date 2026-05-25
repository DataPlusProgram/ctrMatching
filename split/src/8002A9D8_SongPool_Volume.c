typedef signed char s8;
typedef int s32;

typedef struct {
    char pad0[0x18];
    s8 unk18;
    s8 unk19;
    s8 unk1A;
} M2cSongPoolVolumeArg0;

void SongPool_Volume(M2cSongPoolVolumeArg0 *arg0, s8 arg1, s8 arg2, s32 arg3) {
    if (arg3 != 0) {
        arg0->unk18 = arg1;
    }

    arg0->unk19 = arg1;
    arg0->unk1A = arg2;
}