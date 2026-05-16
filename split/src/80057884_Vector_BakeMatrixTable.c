#include "../../common.h"

#define M2C_ERROR(desc) (0)

M2C_UNK ConvertRotToMatrix();         /* extern */
s32 MATH_Sin();                                  /* extern */
M2C_UNK MatrixRotate();        /* extern */
extern M2C_UNK D_80087EF4;
extern M2C_UNK D_80087F24;

void Vector_BakeMatrixTable(void) {
    s32 sp10;                                       /* compiler-managed */
    s32 sp14;
    s32 sp18;                                       /* compiler-managed */
    s32 sp1C;
    u16 sp20;
    M2C_UNK sp30;
    s32 sp50;
    s32 sp54;
    s32 sp58;
    M2C_UNK *var_s3_2;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 var_s1;
    s32 var_s3;
    s32 var_s4;
    s32 var_s4_3;
    s32 var_v0;
    u32 var_s4_2;
    void *temp_s2;
    void *temp_s2_2;
    void *temp_s2_3;

    if (M2C_FIELD(saved_reg_gp, u8 *, 0x624) == 0) {
        temp_v1 = M2C_FIELD(&D_80087F24, s32 *, 4);
        M2C_FIELD(saved_reg_gp, u8 *, 0x624) = 1U;
        var_s4 = 0;
        if (temp_v1 > 0) {
            var_s3 = 0;
            do {
                temp_s0 = var_s4 << 0xD;
                temp_s2 = M2C_FIELD(&D_80087F24, s32 *, 0) + (var_s4 << 5);
                M2C_FIELD(temp_s2, s16 *, 0xC) = (s16) (temp_s0 / temp_v1);
                M2C_FIELD(temp_s2, s16 *, 8) = (s16) (-MATH_Sin(var_s3 / (s32) M2C_FIELD(&D_80087F24, s32 *, 4)) / 7);
                M2C_FIELD(temp_s2, s16 *, 0x10) = (s16) (((MATH_Sin(temp_s0 / (s32) M2C_FIELD(&D_80087F24, s32 *, 4)) * 6) / 40) + 0x1000);
                M2C_FIELD(temp_s2, s16 *, 0x14) = (s16) (((MATH_Sin(temp_s0 / (s32) M2C_FIELD(&D_80087F24, s32 *, 4)) * 6) / 40) + 0x1000);
                var_v0 = MATH_Sin(temp_s0 / (s32) M2C_FIELD(&D_80087F24, s32 *, 4));
                if (var_v0 < 0) {
                    var_v0 += 3;
                }
                M2C_FIELD(temp_s2, s16 *, 0x10) = (s16) ((var_v0 >> 2) + 0x1000);
                var_s4 += 1;
                var_s3 += 0x3000;
            } while (var_s4 < M2C_FIELD(&D_80087F24, s32 *, 4));
        }
        var_s4_2 = 0;
        var_s3_2 = &D_80087EF4;
        sp10 = 0;
        sp14 = 0;
        sp18 = 0;
        sp1C = 0;
        sp20 = 0;
        do {
            temp_v1_2 = M2C_FIELD(var_s3_2, s32 *, 4);
            if ((temp_v1_2 != 0) && (M2C_FIELD(var_s3_2, s32 *, 0) != 0)) {
                var_s1 = 0;
                if (temp_v1_2 > 0) {
                    do {
                        temp_s2_2 = M2C_FIELD(var_s3_2, s32 *, 0) + (var_s1 << 5);
                        temp_s0_2 = temp_s2_2 + 8;
                        ConvertRotToMatrix(&sp30, temp_s0_2);
                        sp10 = M2C_FIELD(temp_s2_2, u16 *, 0x10);
                        sp18 = M2C_FIELD(temp_s2_2, u16 *, 0x12);
                        sp20 = M2C_FIELD(temp_s2_2, u16 *, 0x14);
                        MatrixRotate(temp_s0_2, &sp10, &sp30);
                        var_s1 += 1;
                    } while (var_s1 < M2C_FIELD(var_s3_2, s32 *, 4));
                }
            }
            var_s4_2 += 1;
            var_s3_2 += 8;
        } while (var_s4_2 < 0x14U);
        var_s4_3 = 0;
        if (M2C_FIELD(&D_80087F24, s32 *, 4) > 0) {
            do {
                sp50 = 0;
                sp54 = 0x2000;
                sp58 = 0;
                temp_s2_3 = M2C_FIELD(&D_80087F24, s32 *, 0) + (var_s4_3 << 5);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $0 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $1 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $2 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $3 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t6, $4 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $5 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $6 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t6, $7 */);
                M2C_ERROR(/* unknown instruction: mtc2 $a3, $0 */);
                M2C_ERROR(/* unknown instruction: mtc2 $a2, $1 */);
                M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x0, 0x0 */);
                M2C_FIELD(temp_s2_3, s16 *, 0) = (s16) M2C_ERROR(/* unknown instruction: mfc2 $v0, $25 */);
                M2C_FIELD(temp_s2_3, s16 *, 2) = (s16) M2C_ERROR(/* unknown instruction: mfc2 $v1, $26 */);
                M2C_FIELD(temp_s2_3, s16 *, 4) = (s16) M2C_ERROR(/* unknown instruction: mfc2 $a0, $27 */);
                var_s4_3 += 1;
            } while (var_s4_3 < M2C_FIELD(&D_80087F24, s32 *, 4));
        }
    }
}