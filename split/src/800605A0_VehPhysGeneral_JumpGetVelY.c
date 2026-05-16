typedef short s16;
typedef int s32;

typedef struct {
    s16 unk0;
    s16 unk2;
    s16 unk4;
} M2cVehPhysGeneralJumpGetVelYArg0;

typedef struct {
    s32 unk0;
    char pad4[0x4];
    s32 unk8;
} M2cVehPhysGeneralJumpGetVelYArg1;

s32 VehPhysGeneral_JumpGetVelY(M2cVehPhysGeneralJumpGetVelYArg0 *arg0, M2cVehPhysGeneralJumpGetVelYArg1 *arg1)
{
    s16 temp_a2;
    s32 var_v0;
    s32 var_v1;

    temp_a2 = arg0->unk2;
    var_v0 = temp_a2;

    if (temp_a2 < 0) {
        var_v0 = -var_v0;
    }

    var_v1 = 0;

    if (var_v0 >= 0x15) {
        var_v1 = ((arg1->unk0 * arg0->unk0) + (arg1->unk8 * arg0->unk4)) / temp_a2;
    }

    return var_v1;
}