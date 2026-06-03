#include "../../common.h"

extern void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver);

void VehStuckProc_PlantEaten_PhysLinear(Thread *thread, Driver *driver)
{
    u32 flags;
    GameTracker *gamepads;

    VehPhysProc_Driving_PhysLinear(thread, driver);

    flags = driver->actionsFlagSet & 0xFFFDFFDB;
    driver->fireSpeed = 0;
    driver->jumpTenBuffer = 0;
    driver->fireSpeed = 0;
    driver->baseSpeed = 0;
    driver->simpTurnState = 0;
    gamepads = gT;
    flags |= 8;
    driver->actionsFlagSet = flags;

    driver->timeSpentEaten += gamepads->elapsedTimeMS;
}
