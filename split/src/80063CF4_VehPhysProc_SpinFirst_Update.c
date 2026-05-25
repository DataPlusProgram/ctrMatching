typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0x38E];
    s16 unk38E;
    char pad390[0x70];
    s16 unk400;
} M2cVehPhysProcSpinFirstUpdateArg1;

M2C_UNK VehPhysProc_SpinLast_Init(); /* extern */

void VehPhysProc_SpinFirst_Update(M2C_UNK unused, M2cVehPhysProcSpinFirstUpdateArg1 *arg1) {
    s32 varV0;

    if (arg1->unk400 != 0) {
        varV0 = arg1->unk38E;

        if (varV0 < 0) {
            varV0 = -varV0;
        }

        if (varV0 >= 0x300) {
            return;
        }
    }

    VehPhysProc_SpinLast_Init();
}