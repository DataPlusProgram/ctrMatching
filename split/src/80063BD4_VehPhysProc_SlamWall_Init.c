#include "../../common.h"

extern M2C_UNK COLL_MOVED_PlayerSearch;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_SlamWall_Animate;
extern M2C_UNK VehPhysProc_SlamWall_PhysAngular;
extern M2C_UNK VehPhysProc_SlamWall_PhysLinear;
extern M2C_UNK VehPhysProc_SlamWall_Update;

void VehPhysProc_SlamWall_Init(Thread *thread, Driver *driver) {
    Instance *inst;

    inst = thread->inst;
    driver->kartState = 1;
    driver->numFramesSpentSteering = 0x2710;
    driver->turboMeterRoomLeft = 0;
    driver->rotationSpinRate = 0;
    driver->unkLerpToForwards = 0;
    driver->unk3D4[0] = 0;
    driver->unk3D4[1] = 0;
    driver->unk3D4[2] = 0;
    driver->ampTurnState = 0;
    driver->speed = 0;
    driver->speedApprox = 0;
    driver->xSpeed = 0;
    driver->ySpeed = 0;
    driver->zSpeed = 0;
    driver->velocity.x = 0;
    driver->velocity.y = 0;
    driver->velocity.z = 0;
    driver->unk36E = 0;
    driver->reserves = 0;
    driver->turboOutsideTimer = 0;
    driver->vehFireAudioCooldown = 0;
    driver->screenOffsetY = 0;
    driver->distanceFromGround = 0;
    driver->unk40E = 0;
    driver->jumpSquishStretch2 = 0;
    driver->jumpSquishStretch = 0;
    driver->baseSpeed = 0;
    driver->fireSpeed = 0;
    inst->scale[1] = 0xCCC;
    inst->scale[0] = 0xCCC;
    
    driver->funcPtrs[0] = 0;
	driver->funcPtrs[1] = &VehPhysProc_SlamWall_Update;
    driver->funcPtrs[2] = &VehPhysProc_SlamWall_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[4] = &VehPhysProc_SlamWall_PhysAngular;
    driver->funcPtrs[5] = &VehPhysForce_OnApplyForces;
    driver->funcPtrs[6] = &COLL_MOVED_PlayerSearch;
    driver->funcPtrs[7] = &VehPhysForce_CollideDrivers;
    driver->funcPtrs[8] = &COLL_FIXED_PlayerSearch;
    driver->funcPtrs[9] = &VehPhysGeneral_JumpAndFriction;
    driver->funcPtrs[10] = &VehPhysForce_TranslateMatrix;
    driver->funcPtrs[11] = &VehPhysProc_SlamWall_Animate;
    driver->funcPtrs[12] = &VehEmitter_DriverMain;
}
