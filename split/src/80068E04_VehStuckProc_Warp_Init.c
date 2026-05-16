typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

typedef struct {
    char pad0[0xC];
    s32 unkC;
} AudioTableEntry;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK EngineAudio_Stop();                      /* extern */
M2C_UNK OtherFX_Play();                          /* extern */
M2C_UNK OtherFX_Stop1();                         /* extern */

extern AudioTableEntry D_80086D84[];
extern s16 D_80086E84[];
extern void *D_8008D2AC;

extern M2C_UNK VehEmitter_DriverMain;
extern M2C_UNK VehFrameProc_Driving;
extern M2C_UNK VehPhysForce_TranslateMatrix;
extern M2C_UNK VehPhysProc_Driving_Audio;
extern M2C_UNK VehStuckProc_Warp_PhysAngular;

void VehStuckProc_Warp_Init(M2C_UNK arg0, void *arg1) {
    void *temp_v1;
    s32 temp_v0;
    s32 temp_a0;

    if (M2C_FIELD(arg1, u8 *, 0x376) != 0xA) {
        temp_v0 = 0x3C;
        temp_v1 = (s8 *) arg1 + 0x580;

        M2C_FIELD(arg1, s32 *, 0x580) = temp_v0;
        M2C_FIELD(temp_v1, s32 *, 4) = 0;
        M2C_FIELD(temp_v1, s32 *, 8) = M2C_FIELD(arg1, s32 *, 0x2D0);

        OtherFX_Play(0x97, 1);

        OtherFX_Stop1(M2C_FIELD(arg1, s32 *, 0x304));

        temp_a0 = M2C_FIELD(arg1, s32 *, 0x308);
        M2C_FIELD(arg1, s32 *, 0x304) = 0;
        OtherFX_Stop1(temp_a0);

        temp_a0 = M2C_FIELD(arg1, s32 *, 0x300);
        M2C_FIELD(arg1, s32 *, 0x308) = 0;
        OtherFX_Stop1(temp_a0);

        M2C_FIELD(arg1, s32 *, 0x300) = 0;

        temp_v0 = D_80086E84[M2C_FIELD(arg1, u8 *, 0x4A)];
        temp_v0 = D_80086D84[temp_v0].unkC;
        EngineAudio_Stop((M2C_FIELD(arg1, u8 *, 0x4A) + (temp_v0 << 2)) & 0xFFFF);

        temp_v1 = M2C_FIELD(arg1, void **, 0x1C);
        M2C_FIELD(temp_v1, s32 *, 0x28) |= 0x4000;
        M2C_FIELD(temp_v1, s16 *, 0x56) = M2C_FIELD(arg1, s32 *, 0x2D0) >> 8;

        M2C_FIELD((s8 *) D_8008D2AC + (M2C_FIELD(arg1, u8 *, 0x4A) * 0xDC), s16 *, 0x1532) = 3;

        M2C_FIELD(arg1, M2C_UNK **, 0x60) = &VehPhysProc_Driving_Audio;
        M2C_FIELD(arg1, M2C_UNK **, 0x64) = &VehStuckProc_Warp_PhysAngular;
        M2C_FIELD(arg1, M2C_UNK **, 0x7C) = &VehPhysForce_TranslateMatrix;
        M2C_FIELD(arg1, M2C_UNK **, 0x80) = &VehFrameProc_Driving;

        M2C_FIELD(arg1, u8 *, 0x376) = 0xA;
        M2C_FIELD(arg1, s16 *, 0x38C) = 0;
        M2C_FIELD(arg1, s16 *, 0x38E) = 0;
        M2C_FIELD(arg1, s32 *, 0x54) = 0;
        M2C_FIELD(arg1, s32 *, 0x58) = 0;
        M2C_FIELD(arg1, s32 *, 0x5C) = 0;
        M2C_FIELD(arg1, s32 *, 0x68) = 0;
        M2C_FIELD(arg1, s32 *, 0x6C) = 0;
        M2C_FIELD(arg1, s32 *, 0x70) = 0;
        M2C_FIELD(arg1, s32 *, 0x74) = 0;
        M2C_FIELD(arg1, s32 *, 0x78) = 0;

        M2C_FIELD(arg1, M2C_UNK **, 0x84) = &VehEmitter_DriverMain;
        M2C_FIELD(arg1, s32 *, 0x2C8) |= 0x4000;
    }
}