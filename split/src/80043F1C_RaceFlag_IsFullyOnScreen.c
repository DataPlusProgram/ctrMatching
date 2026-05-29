typedef short s16;
typedef int s32;

s16 RaceFlag_ElapsedTime;

s32 RaceFlag_IsFullyOnScreen(void) {
    return RaceFlag_ElapsedTime == 0;
}