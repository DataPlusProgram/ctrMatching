typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 LOAD_IsOpen_AdvHub();                           /* extern */
extern M2C_UNK COLL_FIXED_PlayerSearch;
extern M2C_UNK COLL_MOVED_PlayerSearch;
extern void *D_8008D2AC;
extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehFrameProc_Driving;
extern M2C_UNK VehPhysForce_CollideDrivers;
extern M2C_UNK VehPhysForce_OnApplyForces;
extern M2C_UNK VehPhysForce_TranslateMatrix;
extern M2C_UNK VehPhysGeneral_JumpAndFriction;
extern M2C_UNK VehPhysGeneral_PhysAngular;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehPhysProc_Driving_PhysLinear;
extern M2C_UNK VehPhysProc_Driving_Update;

void VehPhysProc_Driving_Init(M2C_UNK arg0, void *arg1) {
    if (((u32) (M2C_FIELD(D_8008D2AC, s32 *, 0x1A10) - 0x19) >= 5U) || (LOAD_IsOpen_AdvHub() != 0)) {
        if (M2C_FIELD(D_8008D2AC, s32 *, 0) & 0x20) {
            if (M2C_FIELD(arg1, u8 *, 0x376) == 6) {
                M2C_FIELD(arg1, s32 *, 0x24) = 0xB40;
            }
        }

        M2C_FIELD(arg1, s16 *, 0x406) = 0x60;
        M2C_FIELD(arg1, s16 *, 0x408) = 0x280;
        M2C_FIELD(arg1, M2C_UNK **, 0x58) = &VehPhysProc_Driving_Update;
        M2C_FIELD(arg1, M2C_UNK **, 0x5C) = &VehPhysProc_Driving_PhysLinear;
        M2C_FIELD(arg1, M2C_UNK **, 0x60) = &VehPhysProc_Driving_Audio;
        M2C_FIELD(arg1, M2C_UNK **, 0x64) = &VehPhysGeneral_PhysAngular;
        M2C_FIELD(arg1, M2C_UNK **, 0x68) = &VehPhysForce_OnApplyForces;
        M2C_FIELD(arg1, M2C_UNK **, 0x6C) = &COLL_MOVED_PlayerSearch;
        M2C_FIELD(arg1, M2C_UNK **, 0x70) = &VehPhysForce_CollideDrivers;
        M2C_FIELD(arg1, M2C_UNK **, 0x74) = &COLL_FIXED_PlayerSearch;
        M2C_FIELD(arg1, M2C_UNK **, 0x78) = &VehPhysGeneral_JumpAndFriction;
        M2C_FIELD(arg1, M2C_UNK **, 0x7C) = &VehPhysForce_TranslateMatrix;
        M2C_FIELD(arg1, M2C_UNK **, 0x80) = &VehFrameProc_Driving;
        M2C_FIELD(arg1, u8 *, 0x376) = 0;
        M2C_FIELD(arg1, s16 *, 0x3DC) = 0;
        M2C_FIELD(arg1, s16 *, 0x40A) = 0;
        M2C_FIELD(arg1, s32 *, 0x54) = 0;
        M2C_FIELD(arg1, M2C_UNK **, 0x84) = &VehEmitter_DriverMain;
    }
}