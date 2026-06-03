#include "../../common.h"

extern void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver);

void VehPhysProc_PowerSlide_PhysLinear(Thread *thread, Driver *driver)
{
    VehPhysProc_Driving_PhysLinear(thread, driver);

    driver->actionsFlagSet |= 0x1800;
    driver->timeSpentDrifting += gT->elapsedTimeMS;
}
