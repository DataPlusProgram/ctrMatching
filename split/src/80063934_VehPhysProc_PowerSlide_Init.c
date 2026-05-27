#include "../../common.h"

extern M2C_UNK COLL_FIXED_PlayerSearch;
extern M2C_UNK COLL_MOVED_PlayerSearch;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehFrameProc_Driving;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysForce_OnApplyForces;
extern M2C_UNK VehPhysForce_TranslateMatrix;
extern M2C_UNK VehPhysGeneral_JumpAndFriction;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_PowerSlide_InitSetUpdate;
extern M2C_UNK VehPhysProc_PowerSlide_PhysAngular;
extern M2C_UNK VehPhysProc_PowerSlide_PhysLinear;

void VehPhysProc_PowerSlide_Init(Thread *thread, Driver *driver)
{
    s32 temp_v1;
    M2C_UNK *tempEmitter;
    s32 tempTurboRoom;

    driver->kartState = 2;
    temp_v1 = (driver->powerSlideVal + ((driver->turnConst * 4) / 5)) << 8;
    driver->multDrift = temp_v1;

    if (driver->simpTurnState < 0)
    {
        driver->multDrift = -temp_v1;
    }

    driver->funcPtrs[0] = &VehPhysProc_PowerSlide_InitSetUpdate;
    driver->funcPtrs[2] = &VehPhysProc_PowerSlide_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[4] = &VehPhysProc_PowerSlide_PhysAngular;
    driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
    driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
    driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
    driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
    driver->funcPtrs[9] = &VehPhysGeneral_JumpAndFriction;
    driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
    driver->funcPtrs[11] = &VehFrameProc_Driving;

    tempEmitter = &VehEmitter_DriverMain;
    tempTurboRoom = (u8)driver->constTurboMaxRoom;

    driver->kartStates.drifting.numFramesDrifting = 0;
    driver->kartStates.drifting.driftTotalTimeMs = 0;
    driver->kartStates.drifting.driftBoostTimeMs = 0;
    driver->kartStates.drifting.numBoostsAttempted = 0;
    driver->kartStates.drifting.numBoostsSuccess = 0;
    driver->rotationSpinRate = 0;
    driver->unkLerpToForwards = 0;
    driver->timeUntilDriftSpinout = 0;
    driver->funcPtrs[12] = tempEmitter;
    driver->funcPtrs[1] = 0;
    driver->turboMeterRoomLeft = tempTurboRoom << 5;
}
