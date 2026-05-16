typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysGeneral_JumpAndFriction();           /* extern */
M2C_UNK VehPhysProc_Driving_Init();      /* extern */

void VehPhysProc_FreezeVShift_ReverseOneFrame(s32 arg0, void *arg1) {
    s32 temp_v1;

    VehPhysGeneral_JumpAndFriction();
    temp_v1 = M2C_FIELD(arg1, s32 *, 0x2C8);
    if (temp_v1 & 0x400) {
        VehPhysProc_Driving_Init(arg0, arg1);
        return;
    }
    if (!(temp_v1 & 0x10000000)) {
        M2C_FIELD(arg1, s32 *, 0x3A0) = 0;
        M2C_FIELD(arg1, s32 *, 0x3A4) = 0;
        M2C_FIELD(arg1, s32 *, 0x3A8) = 0;
        M2C_FIELD(arg1, s16 *, 0x38C) = 0;
        M2C_FIELD(arg1, s16 *, 0x38E) = 0;
        M2C_FIELD(arg1, s32 *, 0x2D4) = (s32) M2C_FIELD(arg1, s32 *, 0x2E0);
        M2C_FIELD(arg1, s32 *, 0x2D8) = (s32) M2C_FIELD(arg1, s32 *, 0x2E4);
        M2C_FIELD(arg1, s32 *, 0x2DC) = (s32) M2C_FIELD(arg1, s32 *, 0x2E8);
    }
}