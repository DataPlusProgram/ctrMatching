typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x2];
    u16 unk2;
    char pad4[0x18];
    void *unk1C;
} M2cSongPoolAdvHub1Arg0;

s32 boolStereoEnabled;
s32 howl_spuAddrs;

void SongPool_AdvHub1(M2cSongPoolAdvHub1Arg0 *arg0, s32 arg1, s8 arg2, s32 arg3) {
    u16 tempV1;
    u8 limit;
    void *tempV0;

    tempV1 = M2C_FIELD(boolStereoEnabled + (arg0->unk2 * 2), u16 *, 0);
    limit = M2C_FIELD(howl_spuAddrs + tempV1, u8 *, 1);

    if (arg1 < limit) {
        tempV0 = M2C_FIELD((s8 *)arg0 + (arg1 * 4), void **, 0x1C);

        if (arg3 != 0) {
            M2C_FIELD(tempV0, s8 *, 5) = arg2;
        }

        M2C_FIELD(tempV0, s8 *, 6) = arg2;
    }
}