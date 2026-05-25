#include "../../common.h"

extern M2C_UNK VehPhysProc_SpinFirst_Update;

void VehPhysProc_SpinFirst_InitSetUpdate(Thread *unused, Driver *driver) {
    driver->funcPtrs[0] = 0;
    driver->funcPtrs[1] = &VehPhysProc_SpinFirst_Update;
}
