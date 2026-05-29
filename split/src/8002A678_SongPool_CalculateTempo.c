typedef short s16;
typedef unsigned int u32;

u32 SongPool_CalculateTempo(s16 arg0, s16 arg1, s16 arg2) {
    return ((((u32) (arg2 * arg1) / 60) << 0x10) / (u32) arg0);
}