#include "../../common.h"

extern M2C_UNK VehPhysProc_SpinFirst_Update;

void VehPhysProc_SpinFirst_InitSetUpdate(void *unused, void *arg1) {
    M2C_FIELD(arg1, s32 *, 0x54) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x58) = &VehPhysProc_SpinFirst_Update;
}