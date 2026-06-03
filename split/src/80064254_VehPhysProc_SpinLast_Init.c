#include "../../common.h"

extern void COLL_MOVED_PlayerSearch(void);
extern void VehEmitter_DriverMain(void);
extern void VehFrameProc_LastSpin(void);
extern void VehPhysForce_CollideDrivers(void);
extern void VehPhysProc_Driving_Audio(void);
extern void VehPhysProc_SpinLast_PhysLinear(void);
extern void VehPhysProc_SpinLast_Update(void);

void VehPhysProc_SpinLast_Init(Thread *unused, Driver *driver)
{
    driver->funcPtrs[0] = 0;
    driver->funcPtrs[1] = &VehPhysProc_SpinLast_Update;
    driver->funcPtrs[2] = &VehPhysProc_SpinLast_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[4] = &VehPhysProc_SpinLast_PhysAngular;
    driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
    driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
    driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
    driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
    driver->funcPtrs[9] = &VehPhysGeneral_JumpAndFriction;
    driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
    driver->funcPtrs[11] = &VehFrameProc_LastSpin;
    driver->funcPtrs[12] = &VehEmitter_DriverMain;
}
