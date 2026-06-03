typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK howl_ErasePtrCseqHeader();                  /* extern */
u16 *desiredXA_FinalLapIndex;
u8 reverbModeBossID;
s8 vol_Music;
s32 vol_Voice;

s32 howl_SetSong(s32 arg0)
{
    if (reverbModeBossID == 0)
    {
        vol_Music = 3;
        return 1;
    }

    howl_ErasePtrCseqHeader();
    vol_Music = 0;
    vol_Voice = desiredXA_FinalLapIndex[arg0 & 0xFFFF];

    return 1;
}