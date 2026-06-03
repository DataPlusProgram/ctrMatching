#include "../../common.h"

M2C_UNK GAMEPAD_JogCon1();
s32 LOAD_IsOpen_RacingOrBattle();
M2C_UNK Voiceline_RequestPlay();
M2C_UNK func_800ABEFC();

extern M2C_UNK COLL_MOVED_PlayerSearch;
extern s16 D_80086E84[];
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehFrameProc_Spinning;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_SpinFirst_PhysLinear;
void VehPhysProc_SpinFirst_Init(Thread *thread, Driver *driver)
{
    driver->kartState = 3;
    driver->unkLerpToForwards = 0;
    driver->turboMeterRoomLeft = 0;

    if (LOAD_IsOpen_RacingOrBattle() != 0)
    {
        if (!(gT->gameMode1 & 0x100000))
        {
            func_800ABEFC(driver, -1);
        }
    }

    Voiceline_RequestPlay(3, D_80086E84[driver->driverId], 0x10);

    driver->kartStates.spinning.spinDir = 1;
    driver->kartStates.spinning.driftSpinRate = 0x12C;

    if (driver->ampTurnState < 0)
    {
        driver->kartStates.spinning.driftSpinRate = -0x12C;
        driver->kartStates.spinning.spinDir = -1;
    }
 	driver->funcPtrs[1] = 0;
    driver->funcPtrs[0] = &VehPhysProc_SpinFirst_InitSetUpdate;
    driver->funcPtrs[2] = &VehPhysProc_SpinFirst_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[4] = &VehPhysProc_SpinFirst_PhysAngular;
    driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
    driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
    driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
    driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
    driver->funcPtrs[9] = &VehPhysGeneral_JumpAndFriction;
    driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
    driver->funcPtrs[11] = &VehFrameProc_Spinning;
    driver->funcPtrs[12] = &VehEmitter_DriverMain;

    if (driver->simpTurnState > 0)
    {
        GAMEPAD_JogCon1(driver, 0x29, 0x60);
    }
    else
    {
        GAMEPAD_JogCon1(driver, 0x19, 0x60);
    }
}
