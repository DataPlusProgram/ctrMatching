typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysProc_Driving_PhysLinear(); /* extern */
extern void *D_8008D2AC;

void VehStuckProc_Tumble_PhysLinear(s32 arg0, void *arg1) {
    s16 temp_v1;

    temp_v1 = M2C_FIELD(arg1, u16 *, 0x400) - M2C_FIELD(D_8008D2AC, u16 *, 0x1D04);
    M2C_FIELD(arg1, u16 *, 0x400) = temp_v1;

    if (temp_v1 < 0) {
        M2C_FIELD(arg1, u16 *, 0x400) = 0;
    }

    VehPhysProc_Driving_PhysLinear(arg0, arg1);

    M2C_FIELD(arg1, s16 *, 0x3F6) = 0x60;
    M2C_FIELD(arg1, s16 *, 0x39C) = 0;
    M2C_FIELD(arg1, s16 *, 0x39E) = 0;
    M2C_FIELD(arg1, s32 *, 0x2C8) = M2C_FIELD(arg1, s32 *, 0x2C8) | 0x5808;
    M2C_FIELD(arg1, s16 *, 0x3F8) = (M2C_FIELD(arg1, u16 *, 0x400) * 2) + 0x1770;
}