typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysProc_Driving_PhysLinear();           /* extern */

void VehPhysProc_SpinLast_PhysLinear(s32 arg0, void *arg1) {
    VehPhysProc_Driving_PhysLinear();
    M2C_FIELD(arg1, s16 *, 0x39C) = 0;
    M2C_FIELD(arg1, s16 *, 0x39E) = 0;
    M2C_FIELD(arg1, s32 *, 0x2C8) = M2C_FIELD(arg1, s32 *, 0x2C8) | 0x4008;
}