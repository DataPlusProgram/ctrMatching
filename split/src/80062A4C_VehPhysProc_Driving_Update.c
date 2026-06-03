#include "../../common.h"

extern void VehPhysProc_FreezeVShift_Init(Thread *thread, Driver *driver);
extern void VehPhysProc_PowerSlide_Init(Thread *thread, Driver *driver);
extern GamepadSystem *D_8008D2B0;

void VehPhysProc_Driving_Update(Thread *thread, Driver *driver)
{
    u32 actionsFlagSet;
    s32 turnThreshold;
    s32 absTurnInput;
    short turnRate;

    actionsFlagSet = driver->actionsFlagSet;

    if (actionsFlagSet & 2)
    {
        absTurnInput = driver->turnConst;
        turnThreshold = (absTurnInput * 2) / 5;

        absTurnInput = driver->simpTurnState;
        turnRate = (u8)driver->constTurnRate;

        if (absTurnInput < 0)
        {
            absTurnInput = -absTurnInput;
        }

        if (((turnThreshold + turnRate) >> 1) < absTurnInput)
        {
            if (D_8008D2B0->gamepad[driver->driverId].buttonsHeldCurrFrame & driver->buttonUsedToStartDrift)
            {
                if ((actionsFlagSet & 8) == 0)
                {
                    if (driver->speedApprox >= (((u16)driver->constSpeedClassStat << 16) >> 17))
                    {
                        VehPhysProc_PowerSlide_Init(thread, driver);
                        return;
                    }
                }
            }
        }
    }

    if ((driver->startDriving0x60 == 0) && (driver->unknownTraction >= 5))
    {
        VehPhysProc_FreezeVShift_Init(thread, driver);
        return;
    }

    if (driver->startRollback0x280 == 0)
    {
        driver->unknownTraction = 0;
    }
}
