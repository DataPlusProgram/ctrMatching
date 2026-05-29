#include "../../common.h"

s32 LOAD_IsOpen_AdvHub();                           /* extern */
extern M2C_UNK COLL_FIXED_PlayerSearch;
extern M2C_UNK COLL_MOVED_PlayerSearch;
extern GameTracker *gT;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehFrameProc_Driving;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysForce_OnApplyForces;
extern M2C_UNK VehPhysForce_TranslateMatrix;
extern M2C_UNK VehPhysGeneral_JumpAndFriction;
extern M2C_UNK VehPhysGeneral_PhysAngular;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_Driving_PhysLinear;
extern M2C_UNK VehPhysProc_Driving_Update;

void VehPhysProc_Driving_Init(Thread *thread, Driver *driver)
{

    if (((u32)(gT->levelID - 0x19) >= 5) || (LOAD_IsOpen_AdvHub() != 0))
	{
        if (gT->gameMode1 & 0x20)
		{
            if (driver->kartState == 6)
			{
                driver->invincibleTimer = 0xB40;
            }
        }

        driver->startDriving0x60 = 0x60;
        driver->startRollback0x280 = 0x280;
        driver->funcPtrs[1] = &VehPhysProc_Driving_Update;
        driver->funcPtrs[2] = &VehPhysProc_Driving_PhysLinear;
        driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
        driver->funcPtrs[4] = &VehPhysGeneral_PhysAngular;
        driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
        driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
        driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
        driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
        driver->funcPtrs[9] = &VehPhysGeneral_JumpAndFriction;
        driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
        driver->funcPtrs[11] = &VehFrameProc_Driving;
        driver->kartState = 0;
        driver->turboMeterRoomLeft = 0;
        driver->unknownTraction = 0;
        driver->funcPtrs[0] = 0;
        driver->funcPtrs[12] = &VehEmitter_DriverMain;
    }
}
