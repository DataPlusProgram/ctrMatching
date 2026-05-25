typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *battleSetupWeaponHighlighted;

void MEMPACK_NewPack(s32 arg0, s32 arg1) {
    s32 temp_a0;

    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 4) = arg0;
    temp_a0 = arg0 + arg1;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 8) = temp_a0;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0) = arg1;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x1C) = 0;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x10) = temp_a0;
    M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 0x14) = (s32) M2C_FIELD(battleSetupWeaponHighlighted, s32 *, 4);
}