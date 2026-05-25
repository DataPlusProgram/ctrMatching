typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *battleSetupWeaponHighlighted;

void MEMPACK_ClearLowMem(void) {
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x1C) = 0;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x14) = (s32) M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 4);
}