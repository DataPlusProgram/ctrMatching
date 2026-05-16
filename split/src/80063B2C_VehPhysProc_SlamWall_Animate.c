typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 VehFrameInst_GetNumAnimFrames();      /* extern */
u16 VehFrameInst_GetStartFrame();       /* extern */
extern M2C_UNK VehPhysProc_Driving_Init;

void VehPhysProc_SlamWall_Animate(void *arg0, void *arg1) {
    s16 temp_s0;
    s32 temp_v0;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(temp_s1, u16 *, 0x54) = (u16) (M2C_FIELD(temp_s1, u16 *, 0x54) + 1);
    M2C_FIELD(arg1, u8 *, 0x4D) = (u8) (M2C_FIELD(arg1, u8 *, 0x4D) + 1);
    temp_s0 = (s16) M2C_FIELD(temp_s1, u16 *, 0x54);
    if (temp_s0 >= (VehFrameInst_GetNumAnimFrames(temp_s1, M2C_FIELD(temp_s1, u8 *, 0x52)) - 1)) {
        temp_v0 = VehFrameInst_GetNumAnimFrames(temp_s1, 0U);
        if (temp_v0 > 0) {
            M2C_FIELD(temp_s1, u8 *, 0x52) = 0U;
            M2C_FIELD(temp_s1, u16 *, 0x54) = VehFrameInst_GetStartFrame(0, temp_v0);
            M2C_FIELD(arg1, s8 *, 0x4C) = 0;
            M2C_FIELD(arg1, u8 *, 0x4D) = 0U;
        }
        M2C_FIELD(arg1, M2C_UNK **, 0x54) = &VehPhysProc_Driving_Init;
    }
}