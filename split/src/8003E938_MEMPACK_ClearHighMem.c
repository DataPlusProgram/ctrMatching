typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

 void *battleSetupWeaponHighlighted;

void MEMPACK_ClearHighMem(void) {
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 8) = (s32) M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0xC);
}