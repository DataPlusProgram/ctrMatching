typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK COLL_FIXED_PlayerSearch;
extern M2C_UNK COLL_MOVED_PlayerSearch;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehFrameProc_Driving;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysForce_OnApplyForces;
extern M2C_UNK VehPhysForce_TranslateMatrix;
extern M2C_UNK VehPhysGeneral_JumpAndFriction;
extern M2C_UNK VehPhysGeneral_PhysAngular;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_FreezeEndEvent_PhysLinear;

void VehPhysProc_FreezeEndEvent_Init(void *unused, void *arg1) {
    M2C_UNK *temp_v0;

    temp_v0 = &VehPhysProc_FreezeEndEvent_PhysLinear;

    if (M2C_FIELD(arg1, u8 *, 0x376) != 0xB) {
        M2C_FIELD(arg1, M2C_UNK **, 0x5C) = temp_v0;
        M2C_FIELD(arg1, M2C_UNK **, 0x60) = &VehPhysProc_Driving_Audio;
        M2C_FIELD(arg1, M2C_UNK **, 0x64) = &VehPhysGeneral_PhysAngular;
        M2C_FIELD(arg1, M2C_UNK **, 0x68) = &VehPhysForce_OnApplyForces;
        M2C_FIELD(arg1, M2C_UNK **, 0x6C) = &COLL_MOVED_PlayerSearch;
        M2C_FIELD(arg1, M2C_UNK **, 0x70) = &VehPhysForce_CollideDrivers;
        M2C_FIELD(arg1, M2C_UNK **, 0x74) = &COLL_FIXED_PlayerSearch;
        M2C_FIELD(arg1, M2C_UNK **, 0x78) = &VehPhysGeneral_JumpAndFriction;
        M2C_FIELD(arg1, M2C_UNK **, 0x7C) = &VehPhysForce_TranslateMatrix;
        M2C_FIELD(arg1, M2C_UNK **, 0x80) = &VehFrameProc_Driving;
        M2C_FIELD(arg1, u8 *, 0x376) = 0xB;
        M2C_FIELD(arg1, s16 *, 0x38C) = 0;
        M2C_FIELD(arg1, s16 *, 0x38E) = 0;
        M2C_FIELD(arg1, s32 *, 0x54) = 0;
        M2C_FIELD(arg1, s32 *, 0x58) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0x84) = &VehEmitter_DriverMain;
    }
}