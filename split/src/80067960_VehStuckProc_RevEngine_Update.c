typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK VehFire_Increment(); /* extern */
M2C_UNK VehPhysProc_Driving_Init(); /* extern */
extern void *D_8008D2AC;

void VehStuckProc_RevEngine_Update(s32 arg0, void *arg1) {
    s16 temp_a0;
    void *temp_v0;

    if (M2C_FIELD(arg1, u8 *, 0x594) != 0) {
        if (M2C_FIELD(arg1, s32 *, 0x2D8) < (M2C_FIELD(arg1, s32 *, 0x2D0) + 0x4000)) {
            goto block_4;
        }
    } else if (M2C_FIELD(D_8008D2AC, s32 *, 0x1D0C) <= 0) {
block_4:
        if (M2C_FIELD(arg1, u8 *, 0x594) != 0) {
            temp_v0 = M2C_FIELD(arg1, void **, 0x580);
            if (temp_v0 != NULL) {
                M2C_FIELD(temp_v0, s16 *, 6) = 0;
            }
        }

        temp_a0 = M2C_FIELD(arg1, s16 *, 0x42E);
        if ((temp_a0 < M2C_FIELD(arg1, s32 *, 0x588)) && !(M2C_FIELD(arg1, u8 *, 0x593) & 3)) {
            if (M2C_FIELD(arg1, s32 *, 0x584) >= (temp_a0 + M2C_FIELD(arg1, s16 *, 0x432))) {
                VehFire_Increment(arg1, 0x3C0, 0, 0x80);
            } else {
                VehFire_Increment(arg1, 0x3C0, 0, 0x20);
            }
        }

        M2C_FIELD(arg1, s16 *, 0x3DC) = 0;
        M2C_FIELD(arg1, s8 *, 0x4FE) = 0;
        VehPhysProc_Driving_Init(arg0, arg1);
    }
}