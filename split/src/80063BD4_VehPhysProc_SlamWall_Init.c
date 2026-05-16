typedef signed char s8;
typedef short s16;
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
extern M2C_UNK VehPhysProc_SlamWall_Animate;
extern M2C_UNK VehPhysProc_SlamWall_PhysAngular;
extern M2C_UNK VehPhysProc_SlamWall_PhysLinear;
extern M2C_UNK VehPhysProc_SlamWall_Update;

void VehPhysProc_SlamWall_Init(void *arg0, void *arg1) {
    void *temp_v1;

    temp_v1 = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(arg1, s8 *, 0x376) = 1;
    M2C_FIELD(arg1, s16 *, 0x3E6) = 0x2710;
    M2C_FIELD(arg1, s16 *, 0x3DC) = 0;
    M2C_FIELD(arg1, s16 *, 0x3B4) = 0;
    M2C_FIELD(arg1, s16 *, 0x3D2) = 0;
    M2C_FIELD(arg1, s16 *, 0x3D4) = 0;
    M2C_FIELD(arg1, s16 *, 0x3D6) = 0;
    M2C_FIELD(arg1, s16 *, 0x3D8) = 0;
    M2C_FIELD(arg1, s16 *, 0xC0) = 0;
    M2C_FIELD(arg1, s16 *, 0x38C) = 0;
    M2C_FIELD(arg1, s16 *, 0x38E) = 0;
    M2C_FIELD(arg1, s32 *, 0x3A0) = 0;
    M2C_FIELD(arg1, s32 *, 0x3A4) = 0;
    M2C_FIELD(arg1, s32 *, 0x3A8) = 0;
    M2C_FIELD(arg1, s32 *, 0x88) = 0;
    M2C_FIELD(arg1, s32 *, 0x8C) = 0;
    M2C_FIELD(arg1, s32 *, 0x90) = 0;
    M2C_FIELD(arg1, s16 *, 0x36E) = 0;
    M2C_FIELD(arg1, s16 *, 0x3E2) = 0;
    M2C_FIELD(arg1, s16 *, 0x3DE) = 0;
    M2C_FIELD(arg1, s16 *, 0x3E0) = 0;
    M2C_FIELD(arg1, s8 *, 0x377) = 0;
    M2C_FIELD(arg1, s16 *, 0x3EE) = 0;
    M2C_FIELD(arg1, s16 *, 0x40E) = 0;
    M2C_FIELD(arg1, s16 *, 0x410) = 0;
    M2C_FIELD(arg1, s16 *, 0x40C) = 0;
    M2C_FIELD(arg1, s16 *, 0x39C) = 0;
    M2C_FIELD(arg1, s16 *, 0x39E) = 0;
    M2C_FIELD(temp_v1, s16 *, 0x1E) = 0xCCC;
    M2C_FIELD(temp_v1, s16 *, 0x1C) = 0xCCC;
    M2C_FIELD(arg1, M2C_UNK **, 0x58) = &VehPhysProc_SlamWall_Update;
    M2C_FIELD(arg1, s32 *, 0x54) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x5C) = &VehPhysProc_SlamWall_PhysLinear;
    M2C_FIELD(arg1, M2C_UNK **, 0x60) = &VehPhysProc_Driving_Audio;
    M2C_FIELD(arg1, M2C_UNK **, 0x64) = &VehPhysProc_SlamWall_PhysAngular;
    M2C_FIELD(arg1, M2C_UNK **, 0x68) = &VehPhysForce_OnApplyForces;
    M2C_FIELD(arg1, M2C_UNK **, 0x6C) = &COLL_MOVED_PlayerSearch;
    M2C_FIELD(arg1, M2C_UNK **, 0x70) = &VehPhysForce_CollideDrivers;
    M2C_FIELD(arg1, M2C_UNK **, 0x74) = &COLL_FIXED_PlayerSearch;
    M2C_FIELD(arg1, M2C_UNK **, 0x78) = &VehPhysGeneral_JumpAndFriction;
    M2C_FIELD(arg1, M2C_UNK **, 0x7C) = &VehPhysForce_TranslateMatrix;
    M2C_FIELD(arg1, M2C_UNK **, 0x80) = &VehPhysProc_SlamWall_Animate;
    M2C_FIELD(arg1, M2C_UNK **, 0x84) = &VehEmitter_DriverMain;
}