#include "../../common.h"

M2C_UNK VehBirth_TeleportSelf();
M2C_UNK VehStuckProc_MaskGrab_FindDestPos();
M2C_UNK VehStuckProc_RevEngine_Init();

void VehStuckProc_MaskGrab_Update(Thread *thread, Driver *driver) {
    s32 tempV1;
    void *tempV1_2;
    void *tempV1_3;

    tempV1 = driver->noInputTimer - (u16)gT->elapsedTimeMS;
    driver->noInputTimer = tempV1;

    if ((s16)tempV1 < 0) {
        driver->noInputTimer = 0;
    }

    if ((s16)driver->noInputTimer == 0) {
        tempV1_2 = driver->kartStates.maskGrab.maskObj;
        if (tempV1_2 != NULL) {
            M2C_FIELD(tempV1_2, u16 *, 4) = M2C_FIELD(tempV1_2, u16 *, 4) & 0xFFFE;
            M2C_FIELD(driver->kartStates.maskGrab.maskObj, s16 *, 0x12) = 0x1000;
        }

        tempV1_3 = (s8 *)gT + (driver->driverId * 0xDC);
        M2C_FIELD(tempV1_3, s32 *, 0x1508) = M2C_FIELD(tempV1_3, s32 *, 0x1508) | 8;

        VehStuckProc_MaskGrab_FindDestPos(driver, driver->lastValid);
        VehBirth_TeleportSelf(driver, 0, 0x80);
        VehStuckProc_RevEngine_Init(thread, driver);
    }
}
