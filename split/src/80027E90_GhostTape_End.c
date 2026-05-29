typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK GhostTape_WriteMoves();              /* extern */
extern void *gGamepads;
s16 numAudioBanks;
M2C_UNK ptrGhost;

void GhostTape_End(void) {
    void *temp_s0;

    if (numAudioBanks != 0) {
        temp_s0 = M2C_FIELD(M2C_FIELD(gGamepads, void **, 0x1B2C), void **, 0x30);
        GhostTape_WriteMoves(1);
        M2C_FIELD(M2C_FIELD(&ptrGhost, void **, 0), s16 *, 2) = (s16) (M2C_FIELD(&ptrGhost, u16 *, 0xC) - M2C_FIELD(&ptrGhost, u16 *, 4));
        M2C_FIELD(M2C_FIELD(&ptrGhost, void **, 0), s32 *, 0xC) = (s32) M2C_FIELD(temp_s0, s32 *, 0x3A4);
        M2C_FIELD(M2C_FIELD(&ptrGhost, void **, 0), s32 *, 8) = (s32) M2C_FIELD(temp_s0, s16 *, 0x38E);
        numAudioBanks = 0;
        M2C_FIELD(M2C_FIELD(&ptrGhost, void **, 0), s32 *, 0x10) = (s32) M2C_FIELD(M2C_FIELD(gGamepads, void **, 0x24EC), s32 *, 0x514);
    }
}