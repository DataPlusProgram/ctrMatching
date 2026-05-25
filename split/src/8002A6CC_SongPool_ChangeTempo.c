typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 SongPool_CalculateTempo(); /* extern */

extern u16 *boolStereoEnabled;
extern s32 howl_spuAddrs;

void SongPool_ChangeTempo(void *arg0, s32 arg1) {
    u16 tempV0;
    u16 tempV1;
    s16 tempA2;

    tempV0 = M2C_FIELD(arg0, u16 *, 2);
    tempV0 <<= 1;

    tempV1 = M2C_FIELD((s8 *)boolStereoEnabled + tempV0, u16 *, 0);
    tempA2 = M2C_FIELD(howl_spuAddrs + tempV1, u16 *, 2) + arg1;

    M2C_FIELD(arg0, s16 *, 0xA) = tempA2;
    M2C_FIELD(arg0, s32 *, 0xC) = SongPool_CalculateTempo(0x3C, M2C_FIELD(arg0, s16 *, 8), tempA2);
}