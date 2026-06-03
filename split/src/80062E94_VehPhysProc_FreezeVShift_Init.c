#include "../../common.h"

extern M2C_UNK COLL_MOVED_PlayerSearch;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_FreezeVShift_ReverseOneFrame;
extern M2C_UNK VehPhysProc_FreezeVShift_Update;

void VehPhysProc_FreezeVShift_Init(Thread *thread, Driver *driver) {
   

    driver->kartState = 9;
	driver->actionsFlagSet &= 0xEFFFFFFF;
	
	driver->funcPtrs[0] = 0;
    driver->funcPtrs[1] = &VehPhysProc_FreezeVShift_Update;
    driver->funcPtrs[2] = &VehPhysProc_Driving_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[4] = &VehPhysGeneral_PhysAngular;
    driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
    driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
    driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
    driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
    driver->funcPtrs[9] = &VehPhysProc_FreezeVShift_ReverseOneFrame;
    driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
    driver->funcPtrs[11] = &VehFrameProc_Driving;
    driver->funcPtrs[12] = &VehEmitter_DriverMain;
	
    driver->turboMeterRoomLeft = 0;
    
    
}
