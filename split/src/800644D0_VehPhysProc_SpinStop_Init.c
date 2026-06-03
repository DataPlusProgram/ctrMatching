#include "../../common.h"

extern void COLL_MOVED_PlayerSearch(void);
extern void VehEmitter_DriverMain(void);
extern void VehPhysForce_CollideDrivers(void);
extern void VehPhysProc_Driving_Audio(void);
extern void VehPhysProc_SpinStop_Animate(void);
extern void VehPhysProc_SpinStop_PhysAngular(void);
extern void VehPhysProc_SpinStop_PhysLinear(void);
extern void VehPhysProc_SpinStop_Update(void);

void VehPhysProc_SpinStop_Init(Thread *thread, Driver *driver)
{	
	driver->funcPtrs[0] = 0;
    driver->funcPtrs[1] = &VehPhysProc_SpinStop_Update;
    driver->funcPtrs[2] = &VehPhysProc_SpinStop_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[4] = &VehPhysProc_SpinStop_PhysAngular;
    driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
    driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
    driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
    driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
    driver->funcPtrs[9] = &VehPhysGeneral_JumpAndFriction;
    driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
    driver->funcPtrs[11] = &VehPhysProc_SpinStop_Animate;
    driver->funcPtrs[12] = &VehEmitter_DriverMain;
}
