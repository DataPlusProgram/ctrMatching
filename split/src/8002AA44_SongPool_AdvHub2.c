typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x2];
    u16 unk2;
    s32 unk4;
} M2cSongPoolAdvHub2Arg0;

typedef struct {
    s32 unk0;
    u8 *unk4;
} M2cSongPoolAdvHub2Arg1;

M2C_UNK SongPool_AdvHub1(); /* extern */

s32 boolStereoEnabled;
s32 howl_spuAddrs;

void SongPool_AdvHub2(M2cSongPoolAdvHub2Arg0 *arg0, M2cSongPoolAdvHub2Arg1 *arg1, s32 arg2) {
    M2cSongPoolAdvHub2Arg0 *arg0Copy;
    void *tempS2;
    s32 varS0;
    s32 mask;

    arg0Copy = arg0;
    tempS2 = (void *)(howl_spuAddrs + M2C_FIELD(boolStereoEnabled + (arg0Copy->unk2 * 2), u16 *, 0));

    if (arg1 != NULL) {
        if (arg1->unk0 != M2C_FIELD(tempS2, u8 *, 1)) {
            return;
        }

        arg0Copy->unk4 = arg2;
    }

    if (M2C_FIELD(tempS2, u8 *, 1) != 0) {
        varS0 = 0;

        do {
            mask = arg1->unk4[varS0] & arg0Copy->unk4;

            if (mask != 0) {
                SongPool_AdvHub1(arg0Copy, varS0, 0xFF, 0);
            } else {
                SongPool_AdvHub1(arg0Copy, varS0, 0, 0);
            }

            varS0 += 1;
        } while (varS0 < M2C_FIELD(tempS2, u8 *, 1));
    }
}