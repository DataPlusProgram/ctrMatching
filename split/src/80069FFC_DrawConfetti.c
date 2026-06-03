typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_ERROR(desc) (0)

void *TRIG_AngleSinCos_r15r16r17();                 /* extern */
extern s32 D_8008A2A0;

void DrawConfetti(void *arg0, void *arg1, s32 arg4) {
    s16 temp_t0_3;
    s16 temp_t0_4;
    s32 *var_t0;
    s32 *var_v1;
    s32 temp_gp;
    s32 temp_lo;
    s32 temp_s2;
    s32 temp_s3;
    s32 temp_s4;
    s32 temp_s5;
    s32 temp_s6;
    s32 temp_sp;
    s32 temp_t0_5;
    s32 temp_t1;
    s32 temp_t1_2;
    s32 temp_t1_3;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t2_3;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 var_fp;
    s32 var_gp;
    s32 var_s0;
    s32 var_s1;
    s32 var_t0_2;
    s32 var_t1;
    s32 var_t5;
    u16 temp_t0;
    u16 temp_v1;
    u32 *temp_t6;
    u32 temp_s7;
    u32 temp_s7_2;
    u32 temp_s7_3;
    u32 temp_s7_4;
    u32 temp_t8;
    u32 temp_t8_2;
    u32 temp_t8_3;
    u32 temp_t8_4;
    u32 temp_t8_5;
    u32 temp_t8_6;
    u32 temp_t8_7;
    u32 temp_t8_8;
    u32 temp_t8_9;
    u32 var_s7;
    u32 var_t8;
    u8 temp_t0_2;
    void *var_sp;
    void *var_v0;

    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    var_sp = sp;
    var_gp = saved_reg_gp;
    *(s32 *)0x1F800000 = saved_reg_s0;
    *(s32 *)0x1F800004 = saved_reg_s1;
    *(s32 *)0x1F800008 = saved_reg_s2;
    *(s32 *)0x1F80000C = saved_reg_s3;
    *(s32 *)0x1F800010 = saved_reg_s4;
    *(s32 *)0x1F800014 = saved_reg_s5;
    *(s32 *)0x1F800018 = saved_reg_s6;
    *(s32 *)0x1F80001C = saved_reg_s7;
    *(s32 *)0x1F800020 = saved_reg_gp;
    *(s32 *)0x1F800024 = sp;
    *(s32 *)0x1F800028 = saved_reg_fp;
    *(s32 *)0x1F80002C = saved_reg_ra;
    M2C_ERROR(/* unknown instruction: ctc2 $zero, $5 */);
    M2C_ERROR(/* unknown instruction: ctc2 $zero, $6 */);
    M2C_ERROR(/* unknown instruction: ctc2 $zero, $7 */);
    var_v1 = &D_8008A2A0;
    var_t0 = (s32 *)0x1F800000;
    var_t1 = 8;
loop_1:
    temp_t2 = *var_v1;
    var_v1 += 4;
    *var_t0 = temp_t2;
    var_t0 += 4;
    var_t1 -= 1;
    if (var_t1 > 0) {
        goto loop_1;
    }
    M2C_ERROR(/* unknown instruction: ctc2 $v1, $0 */);
    M2C_ERROR(/* unknown instruction: ctc2 $t0, $1 */);
    M2C_ERROR(/* unknown instruction: ctc2 $t1, $2 */);
    M2C_ERROR(/* unknown instruction: ctc2 $t2, $3 */);
    M2C_ERROR(/* unknown instruction: ctc2 $t3, $4 */);
    var_v0 = TRIG_AngleSinCos_r15r16r17();
    var_s0 = (s32) saved_reg_s0 >> 2;
    temp_s5 = var_s0 + 0x400;
    var_s1 = (s32) saved_reg_s1 >> 2;
    temp_s6 = var_s1 + 0x400;
    M2C_ERROR(/* unknown instruction: ctc2 $v1, $24 */);
    M2C_ERROR(/* unknown instruction: ctc2 $t0, $25 */);
    M2C_ERROR(/* unknown instruction: ctc2 $t1, $26 */);
    var_t5 = *M2C_ERROR(/* Read from unset register $a2 */);
    temp_v1 = M2C_FIELD(M2C_ERROR(/* Read from unset register $a2 */), u16 *, 4);
    if (arg4 != 0) {
        goto block_10;
    }
    temp_t0 = M2C_FIELD(M2C_ERROR(/* Read from unset register $a2 */), u16 *, 6);
    temp_t1 = temp_v1 - var_t5;
    if (temp_v1 == var_t5) {
        goto block_10;
    }
    if (temp_t1 >= 0) {
        goto block_7;
    }
    var_t5 -= temp_t0;
    if ((temp_t1 + temp_t0) <= 0) {
        goto block_9;
    }
    var_t5 = (s32) temp_v1;
    if (0 >= 0) {
        goto block_9;
    }
block_7:
    var_t5 += temp_t0;
    if ((temp_t1 - temp_t0) >= 0) {
        goto block_9;
    }
    var_t5 = (s32) temp_v1;
block_9:
    *M2C_ERROR(/* Read from unset register $a2 */) = var_t5;
block_10:
    temp_s3 = (M2C_FIELD(M2C_ERROR(/* Read from unset register $a2 */), s32 *, 8) * M2C_ERROR(/* Read from unset register $a3 */)) - M2C_FIELD(M2C_ERROR(/* Read from unset register $a0 */), s16 *, 2);
    temp_s2 = (0 - *M2C_ERROR(/* Read from unset register $a0 */)) + temp_s5;
    temp_s4 = (0 - M2C_FIELD(M2C_ERROR(/* Read from unset register $a0 */), s16 *, 4)) + temp_s6;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x34) = 0x28000000;
    var_fp = 6;
    var_s7 = 0x30125400;
    var_t8 = 0x493583FE;
    if (0 >= 0) {
        goto block_26;
    }
block_11:
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x30) = var_t5;
    temp_gp = (((var_gp >> 0x15) + temp_s3) & 0x7FF) - 0x400;
    if (!(var_fp & 1)) {
        goto block_13;
    }
block_13:
    TRIG_AngleSinCos_r15r16r17();
    temp_sp = (((((s32) var_sp >> 0x15) + temp_s4) & 0x7FF) - temp_s6) + (var_s1 >> 5);
    var_v0 = TRIG_AngleSinCos_r15r16r17();
    var_t0_2 = var_s1 >> 7;
    if (var_s1 > 0) {
        goto block_15;
    }
    var_t0_2 = (s32) -var_s1 >> 7;
block_15:
    temp_t0_2 = M2C_FIELD((var_t0_2 + M2C_ERROR(/* Read from unset register $at */)), u8 *, 0x58);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s8 *, 0x34) = 0;
    if (!(var_fp & 1)) {
        goto block_17;
    }
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), u8 *, 0x34) = temp_t0_2;
block_17:
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s8 *, 0x35) = 0;
    if (!(var_fp & 2)) {
        goto block_19;
    }
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), u8 *, 0x35) = temp_t0_2;
block_19:
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s8 *, 0x36) = 0;
    if (!(var_fp & 4)) {
        goto block_21;
    }
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), u8 *, 0x36) = temp_t0_2;
block_21:
    var_s1 = var_s1 >> 8;
    temp_t0_3 = temp_gp - var_s1;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x3A) = temp_t0_3;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x42) = temp_t0_3;
    temp_t0_4 = temp_gp + var_s1;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x4A) = temp_t0_4;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x52) = temp_t0_4;
    temp_v1_2 = (s32) (var_s0 * M2C_ERROR(/* Read from unset register $t1 */)) >> 0x14;
    temp_lo = var_s0 * M2C_ERROR(/* Read from unset register $t2 */);
    var_s0 = var_s0 >> 8;
    temp_t2_2 = (s32) M2C_ERROR(/* Read from unset register $t2 */) >> 8;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x38) = (s16) ((M2C_ERROR(/* Read from unset register $t9 */) - temp_t2_2) - temp_v1_2);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x40) = (s16) ((M2C_ERROR(/* Read from unset register $t9 */) + temp_t2_2) - temp_v1_2);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x48) = (s16) ((M2C_ERROR(/* Read from unset register $t9 */) - temp_t2_2) + temp_v1_2);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s16 *, 0x50) = (s16) (M2C_ERROR(/* Read from unset register $t9 */) + temp_t2_2 + temp_v1_2);
    temp_t1_2 = (s32) M2C_ERROR(/* Read from unset register $t1 */) >> 8;
    temp_v1_3 = temp_lo >> 0x14;
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x3C) = (s32) ((temp_sp - temp_t1_2) + temp_v1_3);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x44) = (s32) (temp_sp + temp_t1_2 + temp_v1_3);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x4C) = (s32) ((temp_sp - temp_t1_2) - temp_v1_3);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x54) = (s32) ((temp_sp + temp_t1_2) - temp_v1_3);
    M2C_ERROR(/* unknown instruction: lwc2 $0, 0x38($at) */);
    M2C_ERROR(/* unknown instruction: lwc2 $1, 0x3c($at) */);
    M2C_ERROR(/* unknown instruction: lwc2 $2, 0x40($at) */);
    M2C_ERROR(/* unknown instruction: lwc2 $3, 0x44($at) */);
    M2C_ERROR(/* unknown instruction: lwc2 $4, 0x48($at) */);
    M2C_ERROR(/* unknown instruction: lwc2 $5, 0x4c($at) */);
    temp_t8 = (u32) M2C_ERROR(/* Read from unset register $t8 */) >> 8;
    M2C_ERROR(/* unknown instruction: rtpt */);
    temp_s7 = (var_s7 >> 8) | (M2C_ERROR(/* Read from unset register $t8 */) << 0x18);
    temp_t8_2 = temp_t8 | ((var_s7 + temp_t8 + (temp_s7 >> 8)) << 0x18);
    temp_t8_3 = temp_t8_2 >> 8;
    temp_s7_2 = (temp_s7 >> 8) | (temp_t8_2 << 0x18);
    var_gp = (temp_s7 + temp_t8_3 + (temp_s7_2 >> 8)) << 0x18;
    temp_t8_4 = temp_t8_3 | var_gp;
    temp_t8_5 = temp_t8_4 >> 8;
    var_s7 = (temp_s7_2 >> 8) | (temp_t8_4 << 0x18);
    var_sp = (void *) ((temp_s7_2 + temp_t8_5 + (var_s7 >> 8)) << 0x18);
    var_t8 = temp_t8_5 | (s32) var_sp;
    temp_v1_4 = M2C_ERROR(/* unknown instruction: mfc2 $v1, $12 */);
    temp_t0_5 = M2C_ERROR(/* unknown instruction: mfc2 $t0, $13 */);
    temp_t1_3 = M2C_ERROR(/* unknown instruction: mfc2 $t1, $14 */);
    M2C_ERROR(/* unknown instruction: swc2 $12, 0x8($v0) */);
    M2C_ERROR(/* unknown instruction: lwc2 $0, 0x50($at) */);
    M2C_ERROR(/* unknown instruction: lwc2 $1, 0x54($at) */);
    if (M2C_ERROR(/* unknown instruction: cfc2 $t2, $31 */) & 0x20000) {
        goto block_27;
    }
    M2C_ERROR(/* unknown instruction: rtps */);
    temp_t2_3 = M2C_ERROR(/* unknown instruction: mfc2 $t2, $14 */);
    temp_v1_5 = ~((temp_v1_4 - M2C_ERROR(/* Read from unset register $t4 */)) | (temp_t0_5 - M2C_ERROR(/* Read from unset register $t4 */)) | (temp_t1_3 - M2C_ERROR(/* Read from unset register $t4 */)) | temp_t2_3) | (temp_v1_4 & temp_t0_5 & temp_t1_3 & temp_t2_3);
    if (M2C_ERROR(/* unknown instruction: cfc2 $t1, $31 */) & 0x20000) {
        goto block_27;
    }
    M2C_ERROR(/* unknown instruction: avsz4 */);
    if (temp_v1_5 < 0) {
        goto block_27;
    }
    if (temp_v1_5 & 0x8000) {
        goto block_27;
    }
    M2C_ERROR(/* unknown instruction: swc2 $12, 0xc($v0) */);
    M2C_ERROR(/* unknown instruction: swc2 $13, 0x10($v0) */);
    M2C_ERROR(/* unknown instruction: swc2 $14, 0x14($v0) */);
    M2C_FIELD(var_v0, s32 *, 4) = (s32) M2C_FIELD(M2C_ERROR(/* Read from unset register $at */), s32 *, 0x34);
    temp_t6 = (((u32) M2C_ERROR(/* unknown instruction: mfc2 $t6, $24 */) >> 0x12) * 4) + M2C_ERROR(/* Read from unset register $t3 */);
    M2C_FIELD(var_v0, s32 *, 0) = (s32) (*temp_t6 | 0x05000000);
    *temp_t6 = (u32) ((s32) var_v0 << 8) >> 8;
    var_v0 += 0x18;
    if (0 >= 0) {
        goto block_27;
    }
block_26:
    temp_t8_6 = var_t8 >> 8;
    temp_s7_3 = (var_s7 >> 8) | (var_t8 << 0x18);
    temp_t8_7 = temp_t8_6 | ((var_s7 + temp_t8_6 + (temp_s7_3 >> 8)) << 0x18);
    temp_t8_8 = temp_t8_7 >> 8;
    temp_s7_4 = (temp_s7_3 >> 8) | (temp_t8_7 << 0x18);
    var_gp = (temp_s7_3 + temp_t8_8 + (temp_s7_4 >> 8)) << 0x18;
    temp_t8_9 = temp_t8_8 | var_gp;
    var_s7 = (temp_s7_4 >> 8) | (temp_t8_9 << 0x18);
    var_sp = (void *) ((temp_s7_4 + (temp_t8_9 >> 8) + (var_s7 >> 8)) << 0x18);
block_27:
    var_fp -= 1;
    if (var_fp != 0) {
        goto block_29;
    }
    var_fp = 6;
block_29:
    var_t5 = M2C_ERROR(/* Read from unset register $t5 */) - 1;
    if (M2C_ERROR(/* Read from unset register $t5 */) != 0) {
        goto block_11;
    }
    M2C_FIELD(M2C_ERROR(/* Read from unset register $a1 */), void **, 0xC) = var_v0;
    return;
}