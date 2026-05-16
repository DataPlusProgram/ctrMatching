typedef signed char s8;
typedef unsigned char u8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
	char pad0[0x2];
	u16 unk2;
} M2cSongPoolAdvHub1Arg0;

void SongPool_AdvHub1(M2cSongPoolAdvHub1Arg0 *arg0, s32 arg1, s8 arg2, s32 arg3) {
    void *temp_v0;

    if (arg1 < (s32) M2C_FIELD((M2C_FIELD(saved_reg_gp, s32 *, 0x85C) + *((arg0->unk2 * 2) + M2C_FIELD(saved_reg_gp, s32 *, 0x848))), u8 *, 1)) {
        temp_v0 = M2C_FIELD((arg0 + (arg1 * 4)), void **, 0x1C);
        if (arg3 != 0) {
            M2C_FIELD(temp_v0, s8 *, 5) = arg2;
        }
        M2C_FIELD(temp_v0, s8 *, 6) = arg2;
    }
}