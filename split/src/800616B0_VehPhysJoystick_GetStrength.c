typedef short s16;
typedef int s32;

#define NULL 0

typedef struct {
    char pad0[0x2];
    s16 unk2;
    s16 unk4;
} M2cVehPhysJoystickGetStrengthArg2;

s32 VehPhysJoystick_GetStrength(s32 arg0, s32 arg1, M2cVehPhysJoystickGetStrengthArg2 *arg2) {
    s32 var_a2;
    s32 var_v1;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_a3;

    var_v1 = 0x30;
    if (arg2 != NULL) {
        var_v1 = arg2->unk2;
        var_a2 = arg2->unk4;
        var_a3 = var_a2 - var_v1;
    } else {
        var_a2 = 0x7F;
        var_a3 = 0x5E;
    }

    if (arg0 < var_v1) {
        return 0;
    }
    if (arg0 >= var_a2) {
        return arg1;
    }

    arg0 -= var_v1;
    temp_v1 = var_a3 / 2;

    if (arg0 < temp_v1) {
        return (s32)(arg0 * (arg1 / 5) * 2) / var_a3;
    }

    temp_v1_2 = arg1 / 5;
    return ((s32)((arg0 - temp_v1) * (arg1 - temp_v1_2) * 2) / var_a3) + temp_v1_2;
}
