typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 VehCalc_InterpBySpeed();         /* extern */
M2C_UNK VehPhysForce_RotAxisAngle(); /* extern */
extern void *gGamepads;

void VehPhysProc_SpinFirst_PhysAngular(M2C_UNK unused, void *arg1) {
    s32 tempLo;
    u16 tempA0;
    u16 tempA0_2;
    u16 tempV0;
    u16 tempV1;
    volatile u16 *spinVel;

    spinVel = (volatile u16 *)((s8 *)arg1 + 0x3B4);

    tempA0 = *spinVel;
    M2C_FIELD(arg1, s16 *, 0x3E6) = 0x2710;

    tempV0 = M2C_FIELD(arg1, u16 *, 0x3C6);
    tempV1 = M2C_FIELD(arg1, u16 *, 0x580);

    tempA0 = tempA0 - ((s32)(tempA0 << 0x10) >> 0x13);
    tempV0 = (tempV0 + tempV1 + 0x800) & 0xFFF;

    *spinVel = tempA0;

    tempA0_2 = M2C_FIELD(arg1, u16 *, 0x3D4);
    tempV1 = M2C_FIELD(arg1, u16 *, 0x3B4);

    M2C_FIELD(arg1, u16 *, 0x3C6) = tempV0 - 0x800;

    tempA0_2 = tempA0_2 - ((s32)(tempA0_2 << 0x10) >> 0x13);
    M2C_FIELD(arg1, u16 *, 0xC0) = tempV1;
    M2C_FIELD(arg1, u16 *, 0x3D4) = tempA0_2;

    tempLo = (s16)tempV1 * M2C_FIELD(gGamepads, s32 *, 0x1D04);

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

    VehPhysForce_RotAxisAngle(
        arg1 + 0x310,
        arg1 + 0x360,
        M2C_FIELD(arg1, s16 *, 0x39A)
    );
}