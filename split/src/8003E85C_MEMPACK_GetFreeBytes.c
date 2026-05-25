typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *battleSetupWeaponHighlighted;

s32 MEMPACK_GetFreeBytes(void) {
    return M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 8) - M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x14);
}