#include "../../common.h"

extern GameTracker *gGamepads;
extern void VehBirth_TeleportSelf(Driver *driver, s32 isAI, s32 spawnFlags);
extern void VehStuckProc_MaskGrab_FindDestPos(Driver *driver, QuadBlock *quadBlock);
extern void VehStuckProc_RevEngine_Init(Thread *thread, Driver *driver);

void VehStuckProc_PlantEaten_Update(Thread *thread, Driver *driver)
{
    u16 timer;

    timer = driver->noInputTimer - gGamepads->elapsedTimeMS;
    driver->noInputTimer = timer;

    if ((s16)timer < 0) {
        driver->noInputTimer = 0;
    }

    if (driver->noInputTimer == 0) {
        VehStuckProc_MaskGrab_FindDestPos(driver, driver->lastValid);
        VehBirth_TeleportSelf(driver, 0, 0x80);

        thread->flags &= ~0x1000;
        M2C_FIELD(thread->inst, u32 *, 0x28) &= ~0x80;

        VehStuckProc_RevEngine_Init(thread, driver);
    }
}
