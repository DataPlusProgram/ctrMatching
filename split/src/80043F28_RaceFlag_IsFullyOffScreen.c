typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

u16 RaceFlag_ElapsedTime;

s32 RaceFlag_IsFullyOffScreen(void) {
    return (u32) ((RaceFlag_ElapsedTime + 0x1387) & 0xFFFF) >= 0x270F;
}