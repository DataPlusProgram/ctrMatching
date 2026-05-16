typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysProc_Driving_PhysLinear();           /* extern */
extern void *D_8008D2AC;

void VehPhysProc_PowerSlide_PhysLinear(s32 arg0, void *arg1) {
    void *temp_v1;
    s32 temp_v0;

    VehPhysProc_Driving_PhysLinear();

    temp_v0 = M2C_FIELD(arg1, s32 *, 0x2C8);
    temp_v1 = D_8008D2AC;
    M2C_FIELD(arg1, s32 *, 0x2C8) = temp_v0 | 0x1800;
    M2C_FIELD(arg1, s32 *, 0x538) = M2C_FIELD(arg1, s32 *, 0x538) + M2C_FIELD(temp_v1, s32 *, 0x1D04);
}