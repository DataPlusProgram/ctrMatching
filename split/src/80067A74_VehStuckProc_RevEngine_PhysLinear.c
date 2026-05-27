#include "../../common.h"

extern void VehPhysProc_Driving_PhysLinear(Thread *thread, Driver *driver);
extern GameTracker *gGamepads;

void VehStuckProc_RevEngine_PhysLinear(Thread *thread, Driver *driver)
{
    u16 timer;

    timer = driver->kartStates.revEngine.unk58E - M2C_FIELD(gGamepads, u16 *, 0x1D04);
    driver->kartStates.revEngine.unk58E = timer;

    if ((s16)timer < 0) {
        driver->kartStates.revEngine.unk58E = 0;
    }

    timer = driver->kartStates.revEngine.unk590 - M2C_FIELD(gGamepads, u16 *, 0x1D04);
    driver->kartStates.revEngine.unk590 = timer;

    if ((s16)timer < 0) {
        driver->kartStates.revEngine.unk590 = 0;
    }

    VehPhysProc_Driving_PhysLinear(thread, driver);

    if (M2C_FIELD(driver, u8 *, 0x594) != 0) {
        s8 *gtBytes;
        s32 offset;
        s16 rumbleTimer;

        M2C_FIELD(gGamepads, s32 *, (driver->driverId * 0xDC) + 0x1508) |= 0x10;

        gtBytes = (s8 *)gGamepads;
        offset = driver->driverId * 0xDC;
        gtBytes += offset;
        rumbleTimer = 0x40;
        M2C_FIELD(gtBytes, s16 *, 0x1530) = rumbleTimer;

        driver->posCurr.y -= 0x200;

        if (driver->kartStates.revEngine.maskObj != NULL) {
            M2C_FIELD(driver->kartStates.revEngine.maskObj, s16 *, 6) = 0x1E00;
        }
    }
}
