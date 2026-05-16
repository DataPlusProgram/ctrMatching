typedef signed char s8;
typedef short s16;
typedef int s32;
typedef unsigned int u32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    s32 unk0;
    s32 unk4;
    u32 unk8;
} M2cVehPhysCrashConvertVecToSpeedArg1;

u32 VehCalc_FastSqrt(); /* extern */
s16 ratan2();          /* extern */

void VehPhysCrash_ConvertVecToSpeed(void *arg0, M2cVehPhysCrashConvertVecToSpeedArg1 *arg1) {
    s16 temp_a0;
    s16 temp_a1;
    s16 temp_v1_4;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_lo_3;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3_2;
    s32 temp_v0;
    s32 temp_v1;
    s32 temp_v1_2;
    u32 temp_s3;
    u32 temp_v0_2;
    u32 temp_v1_3;
    u32 temp_v1_5;

    temp_v0 = arg1->unk0;
    temp_v0_2 = arg1->unk8;
    temp_lo = temp_v0 * temp_v0;
    temp_lo_2 = temp_v0_2 * temp_v0_2;
    temp_s3 = VehCalc_FastSqrt(temp_lo + temp_lo_2, 0x10, temp_lo_2);

    temp_v1 = arg1->unk0;
    temp_lo_3 = temp_v1 * temp_v1;
    temp_v1_2 = arg1->unk4;
    temp_lo = temp_v1_2 * temp_v1_2;
    temp_v1_3 = arg1->unk8;
    temp_v1_3 = temp_v1_3 * temp_v1_3;

    temp_v0_2 = VehCalc_FastSqrt(temp_lo_3 + temp_lo + temp_v1_3, 0x10, temp_lo_3);
    M2C_FIELD(arg0, s16 *, 0x38C) = (s16)(temp_v0_2 >> 8);

    M2C_FIELD(arg0, s16 *, 0x394) = ratan2(arg1->unk4 << 8, temp_s3);
    M2C_FIELD(arg0, s16 *, 0x396) = ratan2(arg1->unk0, arg1->unk8);

    temp_a1 = M2C_FIELD(arg0, s16 *, 0x312);
    temp_v0 = arg1->unk0;
    temp_lo_3 = temp_v0 * temp_a1;

    temp_a0 = M2C_FIELD(arg0, s16 *, 0x318);
    temp_v0 = arg1->unk4;
    temp_lo = temp_v0 * temp_a0;

    temp_v1_4 = M2C_FIELD(arg0, s16 *, 0x31E);
    temp_v0 = arg1->unk8;
    temp_v1 = temp_v0 * temp_v1_4;

    temp_v0 = temp_lo_3 + temp_lo;
    temp_v0 += temp_v1;
    temp_s3_2 = temp_v0 >> 0xC;

    temp_lo_3 = temp_a1 * temp_s3_2;
    temp_lo = temp_a0 * temp_s3_2;
    temp_v1 = temp_v1_4 * temp_s3_2;

    temp_s0 = temp_lo_3 >> 0xC;
    temp_s1 = temp_lo >> 0xC;
    temp_s2 = temp_v1 >> 0xC;

    temp_v0_2 = VehCalc_FastSqrt((temp_s0 * temp_s0) + (temp_s1 * temp_s1) + (temp_s2 * temp_s2), 0x10) >> 8;
    M2C_FIELD(arg0, s16 *, 0x390) = (s16)temp_v0_2;

    if (temp_s3_2 < 0) {
        M2C_FIELD(arg0, s16 *, 0x390) = (s16)-temp_v0_2;
    }

    temp_s0 = arg1->unk0 - temp_s0;
    temp_s1 = arg1->unk4 - temp_s1;
    temp_s2 = arg1->unk8 - temp_s2;

    temp_v1_5 = VehCalc_FastSqrt((temp_s0 * temp_s0) + (temp_s1 * temp_s1) + (temp_s2 * temp_s2), 0x10) >> 8;
    M2C_FIELD(arg0, s16 *, 0x38E) = (s16)temp_v1_5;

    if (((temp_s0 * M2C_FIELD(arg0, s16 *, 0x314)) + (temp_s1 * M2C_FIELD(arg0, s16 *, 0x31A)) + (temp_s2 * M2C_FIELD(arg0, s16 *, 0x320))) < 0) {
        M2C_FIELD(arg0, s16 *, 0x38E) = (s16)-temp_v1_5;
    }
}