typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehPhysProc_FreezeVShift_Init(); /* extern */
M2C_UNK VehPhysProc_PowerSlide_Init();   /* extern */
extern s32 D_8008D2B0;

void VehPhysProc_Driving_Update(s32 arg0, void *arg1) {
    register s32 temp_a2 asm("a2");
    register s32 temp_a3 asm("a3");
    register s32 abs_v1 asm("v1");
    s32 temp_a0;
    s32 temp_v0;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0x2C8);
    temp_a3 = arg0;

    if (temp_a2 & 2) {
        temp_a0 = (M2C_FIELD(arg1, s8 *, 0x34) * 2) / 5;

        abs_v1 = M2C_FIELD(arg1, s8 *, 0x4B);
        if (abs_v1 < 0) {
            abs_v1 = -abs_v1;
        }

        temp_v0 = M2C_FIELD(arg1, u8 *, 0x43A);
        temp_v0 = (temp_v0 + temp_a0) >> 1;

        if (
            (temp_v0 < abs_v1) &&
            (M2C_FIELD((s8 *) D_8008D2B0 + (M2C_FIELD(arg1, u8 *, 0x4A) * 0x50), s32 *, 0x10) & M2C_FIELD(arg1, s16 *, 0x382))
        ) {
            temp_v0 = temp_a2 & 8;
            if (
                (temp_v0 == 0) &&
                (M2C_FIELD(arg1, s16 *, 0x38E) >= ((s32) (M2C_FIELD(arg1, u16 *, 0x42C) << 0x10) >> 0x11))
            ) {
                arg0 = temp_a3;
                VehPhysProc_PowerSlide_Init(arg0);
                return;
            }
        }
    }

    if ((M2C_FIELD(arg1, s16 *, 0x406) == 0) && (M2C_FIELD(arg1, s16 *, 0x40A) >= 5)) {
        VehPhysProc_FreezeVShift_Init(temp_a3);
        return;
    }

    if (M2C_FIELD(arg1, s16 *, 0x408) == 0) {
        M2C_FIELD(arg1, s16 *, 0x40A) = 0;
    }
}