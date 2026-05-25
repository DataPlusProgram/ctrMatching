typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *battleSetupWeaponHighlighted;

void MEMPACK_PopToState(s32 arg0) {
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x1C) = arg0;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x14) = M2C_FIELD((s8 *)battleSetupWeaponHighlighted + (arg0 * 4), s32 *, 0x20);
}