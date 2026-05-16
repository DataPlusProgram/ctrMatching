typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK COLL_FIXED_PlayerSearch;
extern M2C_UNK COLL_MOVED_PlayerSearch;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysForce_OnApplyForces;
extern M2C_UNK VehPhysForce_TranslateMatrix;
extern M2C_UNK VehPhysGeneral_JumpAndFriction;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_SpinStop_Animate;
extern M2C_UNK VehPhysProc_SpinStop_PhysAngular;
extern M2C_UNK VehPhysProc_SpinStop_PhysLinear;
extern M2C_UNK VehPhysProc_SpinStop_Update;

void VehPhysProc_SpinStop_Init(s32 arg0, void *arg1) {
    M2C_FIELD(arg1, M2C_UNK **, 0x58) = &VehPhysProc_SpinStop_Update;
    M2C_FIELD(arg1, M2C_UNK **, 0x5C) = &VehPhysProc_SpinStop_PhysLinear;
    M2C_FIELD(arg1, M2C_UNK **, 0x60) = &VehPhysProc_Driving_Audio;
    M2C_FIELD(arg1, M2C_UNK **, 0x64) = &VehPhysProc_SpinStop_PhysAngular;
    M2C_FIELD(arg1, M2C_UNK **, 0x68) = &VehPhysForce_OnApplyForces;
    M2C_FIELD(arg1, M2C_UNK **, 0x6C) = &COLL_MOVED_PlayerSearch;
    M2C_FIELD(arg1, M2C_UNK **, 0x70) = &VehPhysForce_CollideDrivers;
    M2C_FIELD(arg1, M2C_UNK **, 0x74) = &COLL_FIXED_PlayerSearch;
    M2C_FIELD(arg1, M2C_UNK **, 0x78) = &VehPhysGeneral_JumpAndFriction;
    M2C_FIELD(arg1, M2C_UNK **, 0x7C) = &VehPhysForce_TranslateMatrix;
    M2C_FIELD(arg1, M2C_UNK **, 0x80) = &VehPhysProc_SpinStop_Animate;
    M2C_FIELD(arg1, s32 *, 0x54) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x84) = &VehEmitter_DriverMain;
}