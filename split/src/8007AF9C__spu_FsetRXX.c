typedef short s16;
typedef unsigned short u16;
typedef int s32;

extern s32 D_8008C3B4;
extern s32 D_8008C3DC;

void _spu_FsetRXX(s32 arg0, u16 arg1, s32 arg2) {
    s32 temp_v0;

    temp_v0 = arg0 * 2;
    if (arg2 == 0) {
        *(u16 *)(temp_v0 + D_8008C3B4) = arg1;
        return;
    }
    *(u16 *)(temp_v0 + D_8008C3B4) = arg1 >> D_8008C3DC;
}