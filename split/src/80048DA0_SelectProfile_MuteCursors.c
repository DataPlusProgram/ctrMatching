typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK menuFourAdvProfiles;
extern M2C_UNK menuGhostSelection;
extern M2C_UNK menuWarning2;

void SelectProfile_MuteCursors(void) {
    void *temp_v1;
    void *temp_a1;
    void *temp_a0;

    temp_v1 = &menuFourAdvProfiles;
    temp_a1 = &menuWarning2;
    temp_a0 = &menuGhostSelection;

    M2C_FIELD(temp_v1, s32 *, 8) = M2C_FIELD(temp_v1, s32 *, 8) | 0x800000;
    M2C_FIELD(temp_a0, s32 *, 8) = M2C_FIELD(temp_a0, s32 *, 8) | 0x800000;
    M2C_FIELD(temp_a1, s32 *, 8) = M2C_FIELD(temp_a1, s32 *, 8) | 0x800000;
}