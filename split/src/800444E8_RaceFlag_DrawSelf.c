typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_ERROR(desc) (0)

M2C_UNK RaceFlag_DrawLoadingString();               /* extern */
s32 *RaceFlag_GetOT();                              /* extern */
extern M2C_UNK D_800845A0;
extern s32 D_8008D46C;
extern M2C_UNK DrawSolidBoxData;
extern s16 RaceFlag_CopyLoadStage;
extern u16 RaceFlag_ElapsedTime;
extern M2C_UNK checkerFlagVariables;
extern void *gT;
extern M2C_UNK matrixTitleFlag;
extern s32 ptrToMemcardBuffer1;
extern s32 stage;

void RaceFlag_DrawSelf(void) {
    u16 sp10;
    u16 sp12;
    u16 sp18;
    u16 sp1A;
    u16 sp20;
    u16 sp22;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp34;
    s32 sp38;
    u8 sp40;
    u8 sp41;
    s32 sp48;
    s32 sp4C;
    s32 *sp50;
    s32 sp58;
    u16 *sp5C;
    s32 *temp_fp;
    s32 *var_t1;
    s32 *var_t4;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a1_4;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_s2;
    s32 temp_t2;
    s32 temp_v0;
    s32 temp_v0_3;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s32 temp_v0_6;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s32 temp_v1_4;
    s32 temp_v1_5;
    s32 temp_v1_7;
    s32 var_a0;
    s32 var_a0_10;
    s32 var_a0_11;
    s32 var_a0_12;
    s32 var_a0_13;
    s32 var_a0_2;
    s32 var_a0_3;
    s32 var_a0_4;
    s32 var_a0_5;
    s32 var_a0_6;
    s32 var_a0_8;
    s32 var_a0_9;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a1_4;
    s32 var_a2;
    s32 var_a3;
    s32 var_a3_2;
    s32 var_s5;
    s32 var_s7;
    s32 var_t3;
    s32 var_t6;
    s32 var_t6_2;
    s32 var_t7;
    s32 var_v1;
    s32 var_v1_10;
    s32 var_v1_11;
    s32 var_v1_2;
    s32 var_v1_3;
    s32 var_v1_4;
    s32 var_v1_5;
    s32 var_v1_6;
    s32 var_v1_7;
    s32 var_v1_8;
    s32 var_v1_9;
    u16 *var_a0_14;
    u16 *var_a0_7;
    u16 *var_a2_2;
    u16 temp_v0_2;
    u32 temp_a0_2;
    u32 var_t0;
    void *temp_v1_6;

    if (RaceFlag_CopyLoadStage != 0) {
        if (M2C_FIELD(&DrawSolidBoxData, s32 *, 4) < 0) {
            if ((stage >= 6) && (stage < 8)) {
                M2C_FIELD(&DrawSolidBoxData, s32 *, 4) = 0;
            }
            if (M2C_FIELD(&DrawSolidBoxData, s32 *, 4) >= 0) {
                goto block_6;
            }
        } else {
block_6:
            RaceFlag_DrawLoadingString();
        }
        ptrToMemcardBuffer1 = stage;
        temp_fp = RaceFlag_GetOT();
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        var_t0 = 0;
        var_s7 = 1;
        var_a3 = (s32) D_8008D46C >> 5;
        sp4C = var_a3;
        temp_v1 = M2C_FIELD(&checkerFlagVariables, s32 *, 0x10) + (M2C_FIELD(&checkerFlagVariables, s32 *, 0xC) * M2C_FIELD(gT, s32 *, 0x1D04));
        var_a2 = temp_v1 >> 5;
        M2C_FIELD(&checkerFlagVariables, s32 *, 0x10) = temp_v1;
        if ((u32) var_a2 >= 0x1000U) {
            temp_v0 = temp_v1 & 0x1FFFF;
            var_a2 = temp_v0 >> 5;
            M2C_FIELD(&checkerFlagVariables, s32 *, 0x10) = temp_v0;
            temp_a1 = M2C_FIELD(&checkerFlagVariables, s32 *, 0) + 0x200;
            M2C_FIELD(&checkerFlagVariables, s32 *, 0) = temp_a1;
            var_a0 = *(((temp_a1 & 0x3FF) * 4) + &D_800845A0);
            if (!(temp_a1 & 0x400)) {
                var_a0 <<= 0x10;
            }
            var_a0_2 = var_a0 >> 0x10;
            if (temp_a1 & 0x800) {
                var_a0_2 = -var_a0_2;
            }
            M2C_FIELD(&checkerFlagVariables, s32 *, 4) = (s32) (((s32) ((var_a0_2 + 0xFFF) << 5) >> 0xD) + 0x96);
            temp_a1_2 = M2C_FIELD(&checkerFlagVariables, s32 *, 8) + 0xC8;
            M2C_FIELD(&checkerFlagVariables, s32 *, 8) = temp_a1_2;
            var_a0_3 = *(((temp_a1_2 & 0x3FF) * 4) + &D_800845A0);
            if (!(temp_a1_2 & 0x400)) {
                var_a0_3 <<= 0x10;
            }
            var_a0_4 = var_a0_3 >> 0x10;
            if (temp_a1_2 & 0x800) {
                var_a0_4 = -var_a0_4;
            }
            M2C_FIELD(&checkerFlagVariables, s32 *, 0xC) = (s32) (((s32) ((var_a0_4 + 0xFFF) << 6) >> 0xD) + 0xB4);
        }
        var_a0_5 = *(((var_a2 & 0x3FF) * 4) + &D_800845A0);
        if (!(var_a2 & 0x400)) {
            var_a0_5 <<= 0x10;
        }
        var_a0_6 = var_a0_5 >> 0x10;
        if (var_a2 & 0x800) {
            var_a0_6 = -var_a0_6;
        }
        temp_a2 = var_a2 + 0xC80;
        var_v1 = *(((temp_a2 & 0x3FF) * 4) + &D_800845A0);
        if (!(temp_a2 & 0x400)) {
            var_v1 <<= 0x10;
        }
        var_v1_2 = var_v1 >> 0x10;
        if (temp_a2 & 0x800) {
            var_v1_2 = -var_v1_2;
        }
        var_t6 = 0;
        sp48 = var_v1_2 + 0xFFF;
        sp12 = -0x38EU;
        sp1A = -0x330U;
        sp22 = -0x2D2U;
        temp_v0_2 = -0xBBE - RaceFlag_ElapsedTime;
        sp10 = temp_v0_2;
        sp18 = temp_v0_2;
        sp20 = temp_v0_2;
        do {
            var_a1 = 0;
            var_a0_7 = &sp10;
loop_27:
            var_v1_3 = *(((var_a3 & 0x3FF) * 4) + &D_800845A0);
            if (!(var_a3 & 0x400)) {
                var_v1_3 <<= 0x10;
            }
            var_v1_4 = var_v1_3 >> 0x10;
            if (var_a3 & 0x800) {
                var_v1_4 = -var_v1_4;
            }
            M2C_FIELD(var_a0_7, s16 *, 4) = (s16) (((s32) ((var_a0_6 + 0xFFF) * M2C_FIELD(&checkerFlagVariables, s32 *, 4)) >> 0xD) + 0x280 + ((s32) ((var_v1_4 + 0xFFF) << 5) >> 0xD));
            var_a3 += 0x12C;
            var_a1 += 1;
            var_a0_7 += 8;
            if (var_a1 < 3) {
                goto loop_27;
            }
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            sp12 += 0x11A;
            sp22 += 0x11A;
            sp1A += 0x11A;
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            var_t6 += 1;
        } while (var_t6 < 0xA);
        var_s5 = 1;
        sp50 = &sp48;
        sp5C = &sp10;
        sp28 = M2C_FIELD(&checkerFlagVariables, s32 *, 0);
        sp2C = M2C_FIELD(&checkerFlagVariables, s32 *, 4);
        sp30 = M2C_FIELD(&checkerFlagVariables, s32 *, 8);
        sp34 = M2C_FIELD(&checkerFlagVariables, s32 *, 0xC);
        sp38 = M2C_FIELD(&checkerFlagVariables, s32 *, 0x10);
loop_34:
        var_t1 = (var_s7 * 0x78) + 0x1F7FFFFC;
        var_s7 ^= 1;
        var_t4 = (var_s7 * 0x78) + 0x1F800000;
        var_a3_2 = sp4C + 0x100;
        temp_v1_2 = sp38 + (sp34 << 6);
        var_a1_2 = temp_v1_2 >> 5;
        sp4C = var_a3_2;
        sp38 = temp_v1_2;
        if ((u32) var_a1_2 >= 0x1000U) {
            temp_v0_3 = temp_v1_2 & 0x1FFFF;
            var_a1_2 = temp_v0_3 >> 5;
            sp38 = temp_v0_3;
            temp_v1_3 = sp28 + 0x200;
            sp28 = temp_v1_3;
            var_a0_8 = *(((temp_v1_3 & 0x3FF) * 4) + &D_800845A0);
            if (!(temp_v1_3 & 0x400)) {
                var_a0_8 <<= 0x10;
            }
            var_a0_9 = var_a0_8 >> 0x10;
            if (temp_v1_3 & 0x800) {
                var_a0_9 = -var_a0_9;
            }
            sp2C = ((s32) ((var_a0_9 + 0xFFF) << 5) >> 0xD) + 0x96;
            temp_v1_4 = sp30 + 0xC8;
            sp30 = temp_v1_4;
            var_a0_10 = *(((temp_v1_4 & 0x3FF) * 4) + &D_800845A0);
            if (!(temp_v1_4 & 0x400)) {
                var_a0_10 <<= 0x10;
            }
            var_a0_11 = var_a0_10 >> 0x10;
            if (temp_v1_4 & 0x800) {
                var_a0_11 = -var_a0_11;
            }
            sp34 = ((s32) ((var_a0_11 + 0xFFF) << 6) >> 0xD) + 0xB4;
        }
        var_a0_12 = *(((var_a1_2 & 0x3FF) * 4) + &D_800845A0);
        if (!(var_a1_2 & 0x400)) {
            var_a0_12 <<= 0x10;
        }
        var_a0_13 = var_a0_12 >> 0x10;
        if (var_a1_2 & 0x800) {
            var_a0_13 = -var_a0_13;
        }
        temp_a1_3 = var_a1_2 + 0xC80;
        var_v1_5 = *(((temp_a1_3 & 0x3FF) * 4) + &D_800845A0);
        if (!(temp_a1_3 & 0x400)) {
            var_v1_5 <<= 0x10;
        }
        var_v1_6 = var_v1_5 >> 0x10;
        if (temp_a1_3 & 0x800) {
            var_v1_6 = -var_v1_6;
        }
        var_a1_3 = 0;
        var_a2_2 = sp5C;
        *sp50 = var_v1_6 + 0xFFF;
        sp12 = -0x38EU;
        sp1A = -0x330U;
        sp22 = -0x2D2U;
        sp10 += 0x64;
        sp18 += 0x64;
        sp20 += 0x64;
        temp_s2 = ((s32) ((var_a0_13 + 0xFFF) * sp2C) >> 0xD) + 0x280;
        do {
            var_v1_7 = *(((var_a3_2 & 0x3FF) * 4) + &D_800845A0);
            if (!(var_a3_2 & 0x400)) {
                var_v1_7 <<= 0x10;
            }
            var_v1_8 = var_v1_7 >> 0x10;
            if (var_a3_2 & 0x800) {
                var_v1_8 = -var_v1_8;
            }
            M2C_FIELD(var_a2_2, s16 *, 4) = (s16) (temp_s2 + ((s32) ((var_v1_8 + 0xFFF) << 5) >> 0xD));
            var_a3_2 += 0x12C;
            var_a1_3 += 1;
            var_a2_2 += 8;
        } while (var_a1_3 < 3);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        M2C_ERROR(0);
        var_t7 = 0;
        var_t6_2 = 1;
loop_59:
        if (var_t6_2 < 0xB) {
            M2C_ERROR(0);
            M2C_ERROR(0);
            M2C_ERROR(0);
            var_a1_4 = 0;
            if (var_t6_2 < 0xA) {
                var_a0_14 = sp5C;
                do {
                    var_v1_9 = *(((var_a3_2 & 0x3FF) * 4) + &D_800845A0);
                    if (!(var_a3_2 & 0x400)) {
                        var_v1_9 <<= 0x10;
                    }
                    var_v1_10 = var_v1_9 >> 0x10;
                    if (var_a3_2 & 0x800) {
                        var_v1_10 = -var_v1_10;
                    }
                    M2C_FIELD(var_a0_14, s16 *, 4) = (s16) (temp_s2 + ((s32) ((var_v1_10 + 0xFFF) << 5) >> 0xD));
                    var_a3_2 += 0x12C;
                    var_a1_4 += 1;
                    var_a0_14 += 8;
                } while (var_a1_4 < 3);
                sp12 += 0x11A;
                sp22 += 0x11A;
                sp1A += 0x11A;
                M2C_ERROR(0);
                M2C_ERROR(0);
                M2C_ERROR(0);
                M2C_ERROR(0);
                M2C_ERROR(0);
                M2C_ERROR(0);
                M2C_ERROR(0);
            }
        }
        var_t3 = 0;
        if (var_t7 == 0) {
            var_t3 = 1;
            var_t1 += 4;
        }
        temp_t2 = 0x2000 - sp48;
        sp58 = (s32) ((sp48 * 0x69) + (temp_t2 * 0xA0)) >> 0xD;
loop_71:
        temp_a0 = M2C_FIELD(var_t4, s32 *, 4);
        temp_v1_5 = M2C_FIELD(var_t4, s32 *, 0);
        temp_a1_4 = M2C_FIELD(var_t1, s32 *, 0);
        temp_a2_2 = M2C_FIELD(var_t1, s32 *, 4);
        if (!(temp_v1_5 & (temp_a0 & 0x80008000) & 0x80008000 & temp_a1_4 & 0x80008000 & temp_a2_2) && !((0xD80200 - temp_v1_5) & ((0xD80200 - temp_a0) & 0x80008000) & 0x80008000 & (0xD80200 - temp_a1_4) & 0x80008000 & (0xD80200 - temp_a2_2))) {
            temp_v1_6 = M2C_FIELD(gT, void **, 0x10);
            temp_a0_2 = M2C_FIELD(temp_v1_6, u32 *, 0x80);
            if ((u32) M2C_FIELD(temp_v1_6, u32 *, 0x84) >= temp_a0_2) {
                var_t0 = temp_a0_2;
                M2C_FIELD(temp_v1_6, u32 *, 0x80) = (u32) (temp_a0_2 + 0x24);
            }
            if (var_t0 != 0) {
                if (((var_s5 >> 2) + (var_t7 >> 2)) & 1) {
                    var_v1_11 = (s32) ((sp48 * 0x69) + ((0x2000 - sp48) * 0xA0)) >> 0xD;
                    sp40 = (u8) sp58;
                } else {
                    sp40 = (u8) ((s32) ((sp48 * 0x82) + (temp_t2 * 0xFF)) >> 0xD);
                    var_v1_11 = (s32) ((sp48 * 0x82) + ((0x2000 - sp48) * 0xFF)) >> 0xD;
                }
                sp41 = (u8) var_v1_11;
                temp_v0_4 = M2C_FIELD(var_t4, s32 *, 0);
                var_t4 += 4;
                M2C_FIELD(var_t0, s32 *, 8) = temp_v0_4;
                M2C_FIELD(var_t0, s32 *, 0x18) = (s32) *var_t4;
                temp_v0_5 = M2C_FIELD(var_t1, s32 *, 0);
                var_t1 += 4;
                M2C_FIELD(var_t0, s32 *, 0x10) = temp_v0_5;
                M2C_FIELD(var_t0, s32 *, 0x20) = (s32) *var_t1;
                temp_v1_7 = sp40 | (sp40 << 0x10) | (sp40 << 8);
                M2C_FIELD(var_t0, s32 *, 4) = temp_v1_7;
                M2C_FIELD(var_t0, s32 *, 0x14) = temp_v1_7;
                M2C_FIELD(var_t0, s8 *, 3) = 8;
                M2C_FIELD(var_t0, s8 *, 7) = 0x38;
                temp_v0_6 = var_v1_11 | (var_v1_11 << 0x10) | (var_v1_11 << 8);
                M2C_FIELD(var_t0, s32 *, 0xC) = temp_v0_6;
                M2C_FIELD(var_t0, s32 *, 0x1C) = temp_v0_6;
                M2C_FIELD(var_t0, s32 *, 0) = (s32) ((M2C_FIELD(var_t0, s32 *, 0) & 0xFF000000) | (*temp_fp & 0xFFFFFF));
                *temp_fp = (*temp_fp & 0xFF000000) | (var_t0 & 0xFFFFFF);
                goto block_81;
            }
        } else {
            var_t1 += 4;
block_81:
            var_t3 += 1;
            var_t7 += 1;
            if (var_t3 >= 3) {
                var_t6_2 += 1;
                if (var_t6_2 >= 0xA) {
                    var_s5 += 1;
                    if (var_s5 >= 0x23) {
                        D_8008D46C += M2C_FIELD(gT, s32 *, 0x1D04) * 0x64;
                    } else {
                        goto loop_34;
                    }
                } else {
                    goto loop_59;
                }
            } else {
                goto loop_71;
            }
        }
    }
}