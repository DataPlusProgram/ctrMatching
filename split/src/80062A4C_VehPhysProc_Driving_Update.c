typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK VehPhysProc_FreezeVShift_Init();
extern M2C_UNK VehPhysProc_PowerSlide_Init();
extern s32 D_8008D2B0;

void VehPhysProc_Driving_Update(s32 arg0, void *arg1) {
    s32 temp_a2;
    s32 temp_a3;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 tempSign;

    temp_a2 = M2C_FIELD(arg1, s32 *, 0x2C8);
    temp_a3 = arg0;

    if (temp_a2 & 2) {
        temp_v0 = M2C_FIELD(arg1, s8 *, 0x34);
        temp_v0 = temp_v0 << 1;
        tempSign = temp_v0 >> 0x1F;
        temp_a0 = temp_v0 / 5;
        temp_a0 = temp_a0 - tempSign;

        temp_v1 = M2C_FIELD(arg1, s8 *, 0x4B);
        temp_v0 = M2C_FIELD(arg1, u8 *, 0x43A);

        if (temp_v1 < 0) {
            temp_v1 = -temp_v1;
        }

        temp_v0 = (temp_v0 + temp_a0) >> 1;

        if (temp_v0 < temp_v1) {
            temp_a0 = M2C_FIELD(arg1, s16 *, 0x382);

            if (M2C_FIELD((s8 *)D_8008D2B0 + (M2C_FIELD(arg1, u8 *, 0x4A) * 0x50), s32 *, 0x10) & temp_a0) {
                temp_v0 = temp_a2 & 8;

                if (
                    (temp_v0 == 0) &&
                    (M2C_FIELD(arg1, s16 *, 0x38E) >= ((s32)(M2C_FIELD(arg1, u16 *, 0x42C) << 0x10) >> 0x11))
                ) {
                    VehPhysProc_PowerSlide_Init(temp_a3);
                    return;
                }
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