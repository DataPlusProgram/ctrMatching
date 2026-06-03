#include "../../common.h"

void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver);

void VehPhysProc_SpinLast_PhysLinear(Thread *thread, Driver *driver)
{
    VehPhysProc_Driving_PhysLinear(thread, driver);
    driver->baseSpeed = 0;
    driver->fireSpeed = 0;
    driver->actionsFlagSet = driver->actionsFlagSet | 0x4008;
}
