typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

M2C_UNK CseqMusic_AdvHubSwap(); /* extern */
extern M2C_UNK advHubSongSet;
s16 bankPodiumStage;

void Audio_AdvHub_SwapSong(s32 arg0) {
    u32 temp_v1;

    if (bankPodiumStage == 5) {
        temp_v1 = arg0 - 0x19;
        if (temp_v1 < 5) {
            CseqMusic_AdvHubSwap(0, &advHubSongSet, 1 << temp_v1);
        }
    }
}