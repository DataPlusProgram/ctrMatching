typedef short s16;
typedef int s32;

#define NULL 0

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cVehPhysJoystickReturnToRestArg2;

s32 VehCalc_MapToRange(); /* extern */

s32 VehPhysJoystick_ReturnToRest(s32 arg0, s32 arg1, M2cVehPhysJoystickReturnToRestArg2 *arg2) {
    s32 var_v0;
    s32 var_a1;
    s32 var_a2;

    if (arg2 != NULL) {
        var_v0 = arg2->unk0;
        var_a1 = arg2->unk2;
        var_a2 = arg2->unk4;
    } else {
        var_v0 = 0x80;
        var_a1 = 0x30;
        var_a2 = 0x7F;
    }

    arg0 -= var_v0;

    if (arg0 < 0) {
        return -VehCalc_MapToRange(-arg0, var_a1, var_a2, 0, arg1);
    }

    return VehCalc_MapToRange(arg0, var_a1, var_a2, 0, arg1);
}