typedef unsigned char u8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

s32 LOAD_HowlSectorChainEnd();                      /* extern */
s32 LOAD_HowlSectorChainStart(); /* extern */
M2C_UNK howl_ParseCseqHeader();                /* extern */
extern M2C_UNK KartHWL_CdFile;
extern s32 sampleBlock1;
u8 vol_Music;
extern s32 vol_Voice;

s32 howl_LoadSong(void) {
    switch (vol_Music) {                            /* irregular */
    case 3:
        return 1;
    case 0:
        if (LOAD_HowlSectorChainStart(&KartHWL_CdFile, &sampleBlock1, vol_Voice, 1) != 0) {
            vol_Music = 1;
        }
block_15:
    default:
        return vol_Music == 3;
    case 1:
        if ((LOAD_HowlSectorChainEnd() != 0) && (LOAD_HowlSectorChainStart(&KartHWL_CdFile, &sampleBlock1 + 0x800, vol_Voice + 1, ((u32) (sampleBlock1 + 0x7FF) >> 0xB) - 1) != 0)) {
            vol_Music = 2;
        }
        goto block_15;
    case 2:
        if (LOAD_HowlSectorChainEnd() != 0) {
            howl_ParseCseqHeader(&sampleBlock1);
            vol_Music = 3;
        }
        goto block_15;
    }
}