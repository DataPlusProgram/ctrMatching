#include "../../common.h"

void VehStuckProc_MaskGrab_PhysLinear(Thread *thread, Driver *driver)
{
    VehPhysProc_Driving_PhysLinear(thread, driver);

    driver->fireSpeed = 0;
    driver->jumpTenBuffer = 0;
    driver->fireSpeed = 0;
    driver->baseSpeed = 0;
    driver->simpTurnState = 0;
    driver->actionsFlagSet = (driver->actionsFlagSet & 0xFFFDFFDB) | 8;
}
