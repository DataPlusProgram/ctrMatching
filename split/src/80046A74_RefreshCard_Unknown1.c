typedef int s32;

extern s32 D_8009AA30;

void RefreshCard_Unknown1(void) {
    D_8009AA30 = (D_8009AA30 | 6) & ~8;
}