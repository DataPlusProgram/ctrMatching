#include "../../common.h"

void VehPhysProc_PowerSlide_InitSetUpdate(Thread* arg0, Driver *driver) {
    driver->funcPtrs[0] = 0;
    driver->funcPtrs[1] = &VehPhysProc_PowerSlide_Update;
}
