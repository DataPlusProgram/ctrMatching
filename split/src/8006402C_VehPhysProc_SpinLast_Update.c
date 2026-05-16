typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x3C6];
    s16 unk3C6;
} M2cVehPhysProcSpinLastUpdateArg1;

M2C_UNK VehPhysProc_SpinStop_Init(); /* extern */

void VehPhysProc_SpinLast_Update(M2C_UNK arg0, M2cVehPhysProcSpinLastUpdateArg1 *arg1) {
    s32 var_v0;

    var_v0 = arg1->unk3C6;
    if (var_v0 < 0) {
        var_v0 = -var_v0;
    }

    if (var_v0 < 0x10) {
        VehPhysProc_SpinStop_Init();
    }
}