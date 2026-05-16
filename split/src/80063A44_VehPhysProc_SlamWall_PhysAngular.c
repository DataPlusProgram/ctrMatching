typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 VehCalc_InterpBySpeed();          /* extern */
M2C_UNK VehPhysForce_RotAxisAngle();  /* extern */
extern void *D_8008D2AC;

void VehPhysProc_SlamWall_PhysAngular(M2C_UNK arg0, void *arg1) {
    s32 temp_lo;
    u16 temp_v0;
    s16 interpResult;
    void *temp_a1;
    register void *temp_v1 asm("v1");
    register s32 temp_c0 asm("v1");

    temp_a1 = D_8008D2AC;

    temp_c0 = M2C_FIELD(arg1, s16 *, 0xC0);
    temp_lo = temp_c0 * M2C_FIELD(temp_a1, s32 *, 0x1D04);

    temp_v0 = (M2C_FIELD(arg1, u16 *, 0x39A) + (temp_lo >> 0xD)) & 0xFFF;

    M2C_FIELD(arg1, u16 *, 0x39A) = temp_v0;
    M2C_FIELD(arg1, s16 *, 0x2EE) = M2C_FIELD(arg1, u16 *, 0x3D4) + (temp_v0 + M2C_FIELD(arg1, u16 *, 0x3C6));

    interpResult = VehCalc_InterpBySpeed(
        M2C_FIELD(arg1, s16 *, 0x2F2),
        (M2C_FIELD(temp_a1, s32 *, 0x1D04) << 5) >> 5,
        0,
        temp_lo
    );

    temp_v1 = D_8008D2AC;
    M2C_FIELD(arg1, s16 *, 0x2F2) = interpResult;

    M2C_FIELD(arg1, u16 *, 0x3C6) = VehCalc_InterpBySpeed(
        M2C_FIELD(arg1, s16 *, 0x3C6),
        (M2C_FIELD(temp_v1, s32 *, 0x1D04) << 7) >> 5,
        0
    );

    VehPhysForce_RotAxisAngle(
        (s8 *) arg1 + 0x310,
        (s8 *) arg1 + 0x360,
        M2C_FIELD(arg1, s16 *, 0x39A)
    );
}