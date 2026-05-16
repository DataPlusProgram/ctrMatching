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
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_PowerSlide_InitSetUpdate;
extern M2C_UNK VehPhysProc_PowerSlide_PhysAngular;
extern M2C_UNK VehPhysProc_PowerSlide_PhysLinear;

void VehPhysProc_PowerSlide_Init(M2C_UNK arg0, void *arg1) {
    s16 temp_v1;
    register M2C_UNK *temp_emitter asm("v0");

    M2C_FIELD(arg1, s8 *, 0x376) = 2;

    temp_v1 = (M2C_FIELD(arg1, s8 *, 0x460) + ((M2C_FIELD(arg1, s8 *, 0x34) * 4) / 5)) << 8;
    M2C_FIELD(arg1, s16 *, 0x3DA) = temp_v1;

    if (M2C_FIELD(arg1, s8 *, 0x4B) < 0) {
        M2C_FIELD(arg1, s16 *, 0x3DA) = -temp_v1;
    }

    M2C_FIELD(arg1, M2C_UNK **, 0x54) = &VehPhysProc_PowerSlide_InitSetUpdate;
    M2C_FIELD(arg1, M2C_UNK **, 0x5C) = &VehPhysProc_PowerSlide_PhysLinear;
    M2C_FIELD(arg1, M2C_UNK **, 0x60) = &VehPhysProc_Driving_Audio;
    M2C_FIELD(arg1, M2C_UNK **, 0x64) = &VehPhysProc_PowerSlide_PhysAngular;
    M2C_FIELD(arg1, M2C_UNK **, 0x68) = &VehPhysForce_OnApplyForces;
    M2C_FIELD(arg1, M2C_UNK **, 0x6C) = &COLL_MOVED_PlayerSearch;
    M2C_FIELD(arg1, M2C_UNK **, 0x70) = &VehPhysForce_CollideDrivers;
    M2C_FIELD(arg1, M2C_UNK **, 0x74) = &COLL_FIXED_PlayerSearch;
    M2C_FIELD(arg1, M2C_UNK **, 0x78) = &VehPhysGeneral_JumpAndFriction;
    M2C_FIELD(arg1, M2C_UNK **, 0x7C) = &VehPhysForce_TranslateMatrix;
    M2C_FIELD(arg1, M2C_UNK **, 0x80) = &VehFrameProc_Driving;

    temp_emitter = &VehEmitter_DriverMain;

    M2C_FIELD(arg1, s16 *, 0x580) = 0;
    M2C_FIELD(arg1, s16 *, 0x584) = 0;
    M2C_FIELD(arg1, s16 *, 0x582) = 0;
    M2C_FIELD(arg1, s8 *, 0x586) = 0;
    M2C_FIELD(arg1, s8 *, 0x587) = 0;
    M2C_FIELD(arg1, s16 *, 0x3B4) = 0;
    M2C_FIELD(arg1, s16 *, 0x3D2) = 0;
    M2C_FIELD(arg1, s16 *, 0x3EC) = 0;
    M2C_FIELD(arg1, s32 *, 0x58) = 0;
    M2C_FIELD(arg1, M2C_UNK **, 0x84) = temp_emitter;
    M2C_FIELD(arg1, s16 *, 0x3DC) = M2C_FIELD(arg1, u8 *, 0x476) << 5;
}