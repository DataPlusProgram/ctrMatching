typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysProc_Driving_PhysLinear(); /* extern */
extern void *gGamepads;

void VehPhysProc_SpinFirst_PhysLinear(M2C_UNK unused, void *arg1) {
    s32 tempV1;
    s32 flags;
    void *gamepads;

    tempV1 = M2C_FIELD(arg1, u16 *, 0x400) - M2C_FIELD(gGamepads, u16 *, 0x1D04);
    M2C_FIELD(arg1, u16 *, 0x400) = tempV1;

    if ((s16)tempV1 < 0) {
        M2C_FIELD(arg1, u16 *, 0x400) = 0;
    }

    VehPhysProc_Driving_PhysLinear(unused, arg1);

    flags = M2C_FIELD(arg1, s32 *, 0x2C8);
    gamepads = gGamepads;

    M2C_FIELD(arg1, s16 *, 0x39C) = 0;
    M2C_FIELD(arg1, s16 *, 0x39E) = 0;
    M2C_FIELD(arg1, s32 *, 0x2C8) = flags | 0x5808;
    M2C_FIELD(arg1, s32 *, 0x540) += M2C_FIELD(gamepads, s32 *, 0x1D04);
}