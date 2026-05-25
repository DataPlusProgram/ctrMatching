typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 VehCalc_InterpBySpeed();          /* extern */
M2C_UNK VehPhysForce_RotAxisAngle();  /* extern */
extern void *gGamepads;

void VehPhysProc_SpinStop_PhysAngular(M2C_UNK unused, void *arg1) {
    s32 tempLo;
    u16 tempV0;

    tempLo = M2C_FIELD(arg1, s16 *, 0xC0) * M2C_FIELD(gGamepads, s32 *, 0x1D04);

    tempV0 = (M2C_FIELD(arg1, u16 *, 0x39A) + (tempLo >> 0xD)) & 0xFFF;
    M2C_FIELD(arg1, u16 *, 0x39A) = tempV0;

    M2C_FIELD(arg1, s16 *, 0x2EE) =
        M2C_FIELD(arg1, u16 *, 0x3D4) + (tempV0 + M2C_FIELD(arg1, u16 *, 0x3C6));

    M2C_FIELD(arg1, s16 *, 0x2F2) =
        VehCalc_InterpBySpeed(
            M2C_FIELD(arg1, s16 *, 0x2F2),
            (M2C_FIELD(gGamepads, s32 *, 0x1D04) << 5) >> 5,
            0,
            tempLo
        );

    M2C_FIELD(arg1, u16 *, 0x3C6) =
        VehCalc_InterpBySpeed(
            M2C_FIELD(arg1, s16 *, 0x3C6),
            (M2C_FIELD(gGamepads, s32 *, 0x1D04) << 7) >> 5,
            0
        );

    VehPhysForce_RotAxisAngle(
        arg1 + 0x310,
        arg1 + 0x360,
        M2C_FIELD(arg1, s16 *, 0x39A)
    );
}