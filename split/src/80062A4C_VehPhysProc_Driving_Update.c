#include "../../common.h"

extern M2C_UNK VehPhysProc_FreezeVShift_Init();
extern M2C_UNK VehPhysProc_PowerSlide_Init();
extern s32 D_8008D2B0;

void VehPhysProc_Driving_Update(Thread *thread, Driver *driver) {
    s32 temp_a2;
    Thread *temp_a3;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 tempSign;

    temp_a2 = driver->actionsFlagSet;
    temp_a3 = thread;

    if (temp_a2 & 2) {
        temp_v0 = driver->turnConst;
        temp_v0 = temp_v0 << 1;
        tempSign = temp_v0 >> 0x1F;
        temp_a0 = temp_v0 / 5;
        temp_a0 = temp_a0 - tempSign;

        temp_v1 = driver->simpTurnState;
        temp_v0 = driver->constTurnRate;

        if (temp_v1 < 0) {
            temp_v1 = -temp_v1;
        }

        temp_v0 = (temp_v0 + temp_a0) >> 1;

        if (temp_v0 < temp_v1) {
            temp_a0 = driver->buttonUsedToStartDrift;

            if (M2C_FIELD((s8 *)D_8008D2B0 + ((u8)driver->driverId * 0x50), s32 *, 0x10) & temp_a0) {
                temp_v0 = temp_a2 & 8;

                if (
                    (temp_v0 == 0) &&
                    (driver->speedApprox >= ((s32)((u16)driver->constSpeedClassStat << 0x10) >> 0x11))
                ) {
                    VehPhysProc_PowerSlide_Init(temp_a3);
                    return;
                }
            }
        }
    }

    if ((driver->startDriving0x60 == 0) && (driver->unknownTraction >= 5)) {
        VehPhysProc_FreezeVShift_Init(temp_a3);
        return;
    }

    if (driver->startRollback0x280 == 0) {
        driver->unknownTraction = 0;
    }
}
