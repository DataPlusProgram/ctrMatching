typedef short s16;
typedef int s32;

#define NULL 0

s32 VehPhysJoystick_GetStrength(); /* extern */

s32 VehPhysJoystick_GetStrengthAbsolute(s32 arg0, s32 unused, s16 *arg2) {
    s32 var_v0;

    var_v0 = 0x80;
    if (arg2 != NULL) {
        var_v0 = *arg2;
    }

    arg0 -= var_v0;
    if (arg0 < 0) {
        return -VehPhysJoystick_GetStrength(-arg0);
    }

    return VehPhysJoystick_GetStrength(arg0);
}