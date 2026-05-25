typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s16 VehCalc_InterpBySpeed();  /* extern */
M2C_UNK VehPhysForce_RotAxisAngle(); /* extern */
extern void *gGamepads;

void VehPhysProc_SlamWall_PhysAngular(void *arg1) {
    s32 temp_lo;
    u16 temp_v0;

    temp_lo = M2C_FIELD(arg1, s16 *, 0xC0) * M2C_FIELD(gGamepads, s32 *, 0x1D04);
    temp_v0 = (M2C_FIELD(arg1, u16 *, 0x39A) + (temp_lo >> 0xD)) & 0xFFF;
    M2C_FIELD(arg1, u16 *, 0x39A) = temp_v0;
    M2C_FIELD(arg1, s16 *, 0x2EE) = (s16) (M2C_FIELD(arg1, u16 *, 0x3D4) + (temp_v0 + M2C_FIELD(arg1, u16 *, 0x3C6)));
    M2C_FIELD(arg1, s16 *, 0x2F2) = VehCalc_InterpBySpeed(M2C_FIELD(arg1, s16 *, 0x2F2), (s32) (M2C_FIELD(gGamepads, s32 *, 0x1D04) << 5) >> 5, 0, temp_lo);
    M2C_FIELD(arg1, u16 *, 0x3C6) = VehCalc_InterpBySpeed((s16) M2C_FIELD(arg1, u16 *, 0x3C6), (s32) (M2C_FIELD(gGamepads, s32 *, 0x1D04) << 7) >> 5, 0);
    VehPhysForce_RotAxisAngle(arg1 + 0x310, arg1 + 0x360, (s16) M2C_FIELD(arg1, u16 *, 0x39A));
}