#include "../../common.h"

extern GamepadSystem *D_8008D2B0;
extern GameTracker *gGamepads;

void OtherFX_Play_Echo(s32 soundId, s32 count, s32 flags);
s32 VehCalc_MapToRange(s32 value, s32 inMin, s32 inMax, s32 outMin, s32 outMax);
void VehFire_Increment(Driver *driver, s32 fireLevel, s32 arg2, s32 rotation);
void VehPhysProc_Driving_Init(Thread *thread, Driver *driver);
void VehPhysProc_PowerSlide_Finalize(void *driver);
void VehPhysProc_SpinFirst_Init(Thread *thread, Driver *driver);

void VehPhysProc_PowerSlide_Update(Thread *thread, Driver *driver)
{
    s32 fireLevel;

    if (D_8008D2B0->gamepad[driver->driverId].buttonsTapped & 0xC00) {
        fireLevel = driver->turboMeterRoomLeft;
        driver->kartStates.drifting.numFramesDrifting = 0;

        if (fireLevel != 0) {
            if (fireLevel < ((u8)driver->constTurboLowRoomWarning << 5)) {
                fireLevel = VehCalc_MapToRange(
                    fireLevel,
                    0,
                    ((u8)driver->constTurboLowRoomWarning << 5),
                    ((u8)driver->constTurboFullBarReserveGain << 5),
                    0
                );

                VehFire_Increment(
                    driver,
                    fireLevel,
                    2,
                    ((s8)driver->kartStates.drifting.numBoostsSuccess << 6)
                );

                driver->kartStates.drifting.numBoostsSuccess++;

                if ((s8)driver->kartStates.drifting.numBoostsSuccess < 3) {
                    driver->actionsFlagSet |= 0x80;
                }

                driver->kartStates.drifting.driftBoostTimeMs = ((u8)driver->unk479 << 5);
            } else {
                driver->unk381 = 8;
            }

            driver->kartStates.drifting.numBoostsAttempted++;
            driver->turboMeterRoomLeft = 0;
        }
    } else if (driver->turboMeterRoomLeft != 0) {
        driver->turboMeterRoomLeft -= gGamepads->elapsedTimeMS;

        if (driver->turboMeterRoomLeft < 0) {
            driver->turboMeterRoomLeft = 0;
        }

        if (driver->turboMeterRoomLeft == 0) {
            OtherFX_Play_Echo(0xF, 1, ((u16 *)&driver->actionsFlagSet)[1] & 1);
            driver->kartStates.drifting.numBoostsAttempted += 3;
        }
    } else if ((s8)driver->kartStates.drifting.numBoostsAttempted < 3) {
        driver->turboMeterRoomLeft = ((u8)driver->constTurboMaxRoom << 5);
    }

    if (driver->kartStates.drifting.numFramesDrifting > (u8)driver->constDriftingFramesTillSpinout) {
        M2C_FIELD(driver, s16 *, 0x400) = 0x3C0;

        if ((driver->speedApprox < 0) && ((M2C_FIELD(driver, s32 *, 0xBC) & 3) == 0)) {
            M2C_FIELD(driver, s16 *, 0x400) = 0x780;
        }

        VehPhysProc_SpinFirst_Init(thread, driver);
        return;
    }

    if (
        (driver->kartStates.drifting.numFramesDrifting < -((u8)driver->constDriftingFramesTillSpinout)) ||
        (driver->speed < (((u16)driver->constSpeedClassStat << 16) >> 17)) ||
        (driver->actionsFlagSet & 0x2028) ||
        ((D_8008D2B0->gamepad[driver->driverId].buttonsHeldCurrFrame & driver->buttonUsedToStartDrift) == 0)
    ) {
        VehPhysProc_PowerSlide_Finalize(driver);
        VehPhysProc_Driving_Init(thread, driver);
    }
}