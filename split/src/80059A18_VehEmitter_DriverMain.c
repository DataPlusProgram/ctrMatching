typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_ERROR(desc) (0)

M2C_UNK GAMEPAD_JogCon1();  /* extern */
M2C_UNK GAMEPAD_JogCon2();  /* extern */
M2C_UNK GAMEPAD_ShockForce1(); /* extern */
M2C_UNK GAMEPAD_ShockForce2();        /* extern */
M2C_UNK GAMEPAD_ShockFreq();          /* extern */
s32 MATH_Cos();                                  /* extern */
s32 MATH_Sin();                                  /* extern */
M2C_UNK OtherFX_RecycleNew();  /* extern */
M2C_UNK OtherFX_Stop1();                         /* extern */
s32 PROC_SearchForModel();              /* extern */
void *Particle_Init();       /* extern */
s32 VehCalc_MapToRange(); /* extern */
M2C_UNK VehEmitter_Exhaust(); /* extern */
M2C_UNK VehEmitter_Sparks_Ground(); /* extern */
M2C_UNK VehEmitter_Sparks_Wall();  /* extern */
M2C_UNK VehEmitter_Terrain_Ground();     /* extern */
extern M2C_UNK emSet_GroundSparks;
extern M2C_UNK emSet_MudSplash;
extern M2C_UNK emSet_WallSparks;
extern void *gGamepads;

void VehEmitter_DriverMain(void *arg0, void *arg1) {
    M2C_UNK sp18;
    s32 sp28;
    s32 sp2C;
    s32 sp30;
    s32 sp38;
    M2C_UNK var_a1_4;
    M2C_UNK var_a1_5;
    M2C_UNK var_a2_2;
    s16 temp_s4;
    s16 temp_t1;
    s16 temp_t1_2;
    s16 temp_t1_3;
    s16 temp_t1_4;
    s16 temp_v0_5;
    s16 temp_v1_13;
    s16 var_a0;
    s16 var_a0_2;
    s16 var_a0_3;
    s16 var_a0_4;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_v0_2;
    s16 var_v0_3;
    s16 var_v0_4;
    s16 var_v0_5;
    s16 var_v0_6;
    s16 var_v0_7;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_3;
    s32 temp_a0_4;
    s32 temp_a0_5;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_a2;
    s32 temp_a2_10;
    s32 temp_a2_2;
    s32 temp_a2_3;
    s32 temp_a2_4;
    s32 temp_a2_5;
    s32 temp_a2_6;
    s32 temp_a2_7;
    s32 temp_a2_8;
    s32 temp_a2_9;
    s32 temp_a3;
    s32 temp_a3_2;
    s32 temp_a3_3;
    s32 temp_a3_4;
    s32 temp_a3_5;
    s32 temp_a3_6;
    s32 temp_a3_7;
    s32 temp_a3_8;
    s32 temp_a3_9;
    s32 temp_fp;
    s32 temp_lo;
    s32 temp_s0;
    s32 temp_s0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s1;
    s32 temp_s2_2;
    s32 temp_s4_2;
    s32 temp_t0_2;
    s32 temp_t0_3;
    s32 temp_t0_5;
    s32 temp_t0_6;
    s32 temp_t2;
    s32 temp_v1_11;
    s32 temp_v1_2;
    s32 temp_v1_5;
    s32 temp_v1_7;
    s32 temp_v1_9;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_a1_3;
    s32 var_a2;
    s32 var_s0;
    s32 var_v0;
    s32 var_v0_8;
    s8 temp_s5;
    s8 temp_v0_6;
    s8 temp_v1_3;
    s8 var_s1_3;
    u16 temp_v0_3;
    u16 temp_v0_4;
    u8 temp_t0;
    u8 temp_t0_4;
    u8 temp_v1;
    u8 temp_v1_12;
    u8 temp_v1_14;
    u8 var_v0_9;
    void *temp_a1_4;
    void *temp_a1_5;
    void *temp_a1_6;
    void *temp_a1_7;
    void *temp_s2;
    void *temp_s7;
    void *temp_v0;
    void *temp_v0_2;
    void *temp_v1_10;
    void *temp_v1_4;
    void *temp_v1_6;
    void *temp_v1_8;

    temp_s2 = M2C_FIELD(arg1, void **, 0x358);
    temp_s7 = M2C_FIELD(arg0, void **, 0x34);
    M2C_FIELD(arg1, s32 *, 0x2C4) = (s32) ((M2C_FIELD(arg1, s32 *, 0x2C4) * 0x10) & 0xFFFFFF);
    M2C_FIELD(arg1, u8 *, 0xC3) = (u8) ((M2C_FIELD(arg1, u8 *, 0xC3) - 1) & 7);
    sp38 = M2C_FIELD(temp_s2, s32 *, 4);
    temp_s4 = M2C_FIELD(temp_s2, s16 *, 0x30);
    if (M2C_FIELD(arg0, s16 *, 0x44) == 0x18) {
        var_s1 = -1;
        if (M2C_FIELD(arg1, s32 *, 0x2C8) & 1) {
            if (!(sp38 & 0x20)) {
                var_s1 = M2C_FIELD(temp_s2, s16 *, 0x32);
            }
        }
        var_a0 = M2C_FIELD(arg1, s16 *, 0x38E);
        if (var_a0 < 0) {
            var_a0 = -var_a0;
        }
        temp_s0 = VehCalc_MapToRange(var_a0, 0, 0x1388, 0, 0xC8);
        var_a0_2 = M2C_FIELD(arg1, s16 *, 0x38E);
        if (var_a0_2 < 0) {
            var_a0_2 = -var_a0_2;
        }
        temp_a1 = VehCalc_MapToRange(var_a0_2, 0, 0x2EE0, 0x6C, 0xD2) << 8;
        temp_a2 = temp_s0 << 0x10;
        if (M2C_FIELD(arg1, s32 *, 0x2C8) & 0x10000) {
            var_v0 = temp_a2 | (temp_a1 | 0x01000000);
        } else {
            var_v0 = temp_a2 | temp_a1;
        }
        OtherFX_RecycleNew(arg1 + 0x304, var_s1, var_v0 | 0x80);
        if (!(M2C_FIELD(arg1, s32 *, 0x2C8) & 0x100000)) {
            var_v0_2 = M2C_FIELD(arg1, s16 *, 0x38E);
            if (var_v0_2 < 0) {
                var_v0_2 = -var_v0_2;
            }
            if (var_v0_2 >= 0x201) {
                GAMEPAD_ShockFreq(arg1, M2C_FIELD(temp_s2, u8 *, 0x2C), M2C_FIELD(temp_s2, u8 *, 0x2D));
                GAMEPAD_ShockForce2(arg1, M2C_FIELD(temp_s2, u8 *, 0x2E), M2C_FIELD(temp_s2, u8 *, 0x2F));
            }
            if (M2C_FIELD(arg1, s32 *, 0x2C8) & 2) {
                var_v0_3 = M2C_FIELD(arg1, s16 *, 0x392);
                if (var_v0_3 < 0) {
                    var_v0_3 = -var_v0_3;
                }
                if (var_v0_3 >= 0x1601) {
                    GAMEPAD_ShockForce1(arg1, 3, 0xFF);
                }
            }
        }
    }
    if ((u8) M2C_FIELD(gGamepads, u8 *, 0x1CA8) < 2U) {
        var_v0_4 = M2C_FIELD(arg1, s16 *, 0x38C);
        if (var_v0_4 < 0) {
            var_v0_4 = -var_v0_4;
        }
        if ((var_v0_4 >= 0x501) && (M2C_FIELD(arg1, u8 *, 0xC2) == 0xE)) {
            var_s0 = 0xA;
            if (M2C_FIELD(arg1, s32 *, 0x2C8) & 2) {
                do {
                    temp_v0 = Particle_Init(0, M2C_FIELD(gGamepads, s32 *, 0x2148), &emSet_MudSplash);
                    if (temp_v0 != NULL) {
                        M2C_FIELD(temp_v0, u8 *, 0x18) = (u8) M2C_FIELD(M2C_FIELD(arg1, void **, 0x1C), u8 *, 0x50);
                        M2C_FIELD(temp_v0, void **, 0x20) = (void *) M2C_FIELD(arg1, void **, 0x1C);
                        M2C_FIELD(temp_v0, s32 *, 0x24) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x24) + (M2C_FIELD(temp_v0, s16 *, 0x28) * 0x10));
                        M2C_FIELD(temp_v0, u8 *, 0x19) = (u8) M2C_FIELD(arg1, u8 *, 0x4A);
                        M2C_FIELD(temp_v0, s32 *, 0x34) = (s32) (M2C_FIELD(temp_v0, s32 *, 0x34) + (M2C_FIELD(temp_v0, s16 *, 0x38) * 0x10));
                        M2C_FIELD(temp_v0, u16 *, 0x2A) = (u16) (M2C_FIELD(temp_v0, u16 *, 0x2A) - ((s32) ((u16) M2C_FIELD(temp_v0, s16 *, 0x28) << 0x10) >> 0x14));
                        M2C_FIELD(temp_v0, u16 *, 0x3A) = (u16) (M2C_FIELD(temp_v0, u16 *, 0x3A) - ((s32) ((u16) M2C_FIELD(temp_v0, s16 *, 0x38) << 0x10) >> 0x14));
                    }
                    var_s0 -= 1;
                } while (var_s0 != 0);
            } else {
                temp_v0_2 = Particle_Init(0, M2C_FIELD(gGamepads, s32 *, 0x2148), &emSet_MudSplash);
                if (temp_v0_2 != NULL) {
                    M2C_FIELD(temp_v0_2, u8 *, 0x18) = (u8) M2C_FIELD(M2C_FIELD(arg1, void **, 0x1C), u8 *, 0x50);
                    M2C_FIELD(temp_v0_2, void **, 0x20) = (void *) M2C_FIELD(arg1, void **, 0x1C);
                    M2C_FIELD(temp_v0_2, s32 *, 0x24) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 0x24) + (M2C_FIELD(temp_v0_2, s16 *, 0x28) * 0x10));
                    M2C_FIELD(temp_v0_2, u8 *, 0x19) = (u8) M2C_FIELD(arg1, u8 *, 0x4A);
                    M2C_FIELD(temp_v0_2, s32 *, 0x34) = (s32) (M2C_FIELD(temp_v0_2, s32 *, 0x34) + (M2C_FIELD(temp_v0_2, s16 *, 0x38) * 0x10));
                    M2C_FIELD(temp_v0_2, u16 *, 0x2A) = (u16) (M2C_FIELD(temp_v0_2, u16 *, 0x2A) - ((s32) ((u16) M2C_FIELD(temp_v0_2, s16 *, 0x28) << 0x10) >> 0x14));
                    M2C_FIELD(temp_v0_2, u16 *, 0x3A) = (u16) (M2C_FIELD(temp_v0_2, u16 *, 0x3A) - ((s32) ((u16) M2C_FIELD(temp_v0_2, s16 *, 0x38) << 0x10) >> 0x14));
                }
            }
        }
        if ((u8) M2C_FIELD(gGamepads, u8 *, 0x1CA8) < 2U) {
            if ((sp38 & 0x40) && (M2C_FIELD(arg1, s32 *, 0x2C8) & 2)) {
                var_v0_5 = M2C_FIELD(arg1, s16 *, 0x38E);
                if (var_v0_5 < 0) {
                    var_v0_5 = -var_v0_5;
                }
                if (var_v0_5 >= 0x601) {
                    var_v0_6 = M2C_FIELD(arg1, s16 *, 0x392);
                    if (var_v0_6 < 0) {
                        var_v0_6 = -var_v0_6;
                    }
                    if (var_v0_6 >= 0x1601) {
                        M2C_ERROR(/* unknown instruction: ctc2 $t4, $0 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t5, $1 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t4, $2 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t5, $3 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t6, $4 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t4, $5 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t5, $6 */);
                        M2C_ERROR(/* unknown instruction: ctc2 $t6, $7 */);
                        VehEmitter_Sparks_Ground(arg1, &emSet_GroundSparks);
                    }
                }
            }
            if (M2C_FIELD(temp_s2, s32 *, 0x18) != 0) {
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $0 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $1 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $2 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $3 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t6, $4 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $5 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $6 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t6, $7 */);
                var_a1 = M2C_FIELD(temp_s2, s32 *, 0x1C);
                if ((var_a1 == 0) || !(M2C_FIELD(gGamepads, s32 *, 0x1CEC) & 1)) {
                    var_a1 = M2C_FIELD(temp_s2, s32 *, 0x18);
                }
                VehEmitter_Terrain_Ground(arg1, var_a1);
            }
            if ((M2C_FIELD(arg1, s16 *, 0x3FE) == 0xF0) && (M2C_FIELD(arg1, u8 *, 0x376) != 5)) {
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $0 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $1 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $2 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $3 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t6, $4 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t4, $5 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t5, $6 */);
                M2C_ERROR(/* unknown instruction: ctc2 $t6, $7 */);
                VehEmitter_Sparks_Wall(arg1, &emSet_WallSparks);
                var_s1_2 = 0x14;
                temp_v0_3 = M2C_FIELD(arg1, u16 *, 0x496) + 0x14;
                M2C_FIELD(arg1, u16 *, 0x496) = temp_v0_3;
                if ((s16) temp_v0_3 >= 0x100) {
                    M2C_FIELD(arg1, u16 *, 0x496) = 0xFFU;
                }
            } else {
                if (M2C_FIELD(arg1, s16 *, 0x3FE) == 0) {
                    M2C_FIELD(arg1, s16 *, 0x50) = 0;
                }
                temp_v0_4 = M2C_FIELD(arg1, u16 *, 0x496) - 0x14;
                M2C_FIELD(arg1, u16 *, 0x496) = temp_v0_4;
                if (temp_v0_4 & 0x8000) {
                    M2C_FIELD(arg1, u16 *, 0x496) = 0U;
                }
                var_s1_2 = 0x14;
                if ((s16) M2C_FIELD(arg1, u16 *, 0x496) == 0) {
                    var_s1_2 = -1;
                }
            }
            if (M2C_FIELD(arg0, s16 *, 0x44) == 0x18) {
                temp_a2_2 = (s16) M2C_FIELD(arg1, u16 *, 0x496) << 0x10;
                if (M2C_FIELD(arg1, s32 *, 0x2C8) & 0x10000) {
                    var_a2 = temp_a2_2 | 0x01008080;
                } else {
                    var_a2 = temp_a2_2 | 0x8080;
                }
                OtherFX_RecycleNew(arg1 + 0x308, var_s1_2, var_a2);
            }
        }
    }
    if (sp38 & 8) {
        M2C_FIELD(arg1, s32 *, 0x2C8) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C8) | 0x1800);
    }
    temp_v1 = M2C_FIELD(arg1, u8 *, 0x4C);
    switch (temp_v1) {                              /* irregular */
    case 0:
        break;
    case 1:
        M2C_FIELD(arg1, s32 *, 0x2C8) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C8) | 0x800);
        /* fallthrough */
    default:
        M2C_FIELD(arg1, s32 *, 0x2C8) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C8) & ~0x1000);
        break;
    }
    temp_v1_2 = M2C_FIELD(arg1, s32 *, 0x2C8);
    if ((temp_v1_2 & 1) && (temp_v1_2 & 0x1800)) {
        temp_v0_5 = M2C_FIELD(arg1, s16 *, 0x38E);
        var_a0_3 = temp_v0_5;
        if (temp_v0_5 < 0) {
            var_a0_3 = -var_a0_3;
        }
        if (var_a0_3 >= 0x201) {
            if (M2C_FIELD(arg0, s16 *, 0x44) == 0x18) {
                temp_v1_3 = M2C_FIELD(arg1, s8 *, 0x4B);
                var_s1_3 = temp_v1_3;
                if (temp_v1_3 < 0) {
                    var_s1_3 = -var_s1_3;
                }
                temp_s0_2 = VehCalc_MapToRange(var_a0_3, 0x7D0, 0x2EE0, 0x14, 0xAA) + (var_s1_3 >> 1);
                var_a0_4 = M2C_FIELD(arg1, s16 *, 0x38E);
                if (var_a0_4 < 0) {
                    var_a0_4 = -var_a0_4;
                }
                var_a1_2 = VehCalc_MapToRange(var_a0_4, 0x7D0, 0x2EE0, 0x92, 0x78);
                if (M2C_FIELD(arg1, u8 *, 0x376) == 2) {
                    var_v0_7 = M2C_FIELD(arg1, s16 *, 0x3D4);
                    if (var_v0_7 < 0) {
                        var_v0_7 = -var_v0_7;
                    }
                    temp_a1_2 = var_a1_2 - var_v0_7;
                    var_a1_3 = temp_a1_2 + var_s1_3;
                    if (temp_a1_2 < 0) {
                        var_a1_2 = 0;
                        goto block_88;
                    }
                } else {
block_88:
                    var_a1_3 = var_a1_2 + var_s1_3;
                }
                if (var_a1_3 >= 0x93) {
                    var_a1_3 = 0x92;
                }
                temp_a3 = temp_s0_2 << 0x10;
                temp_a1_3 = var_a1_3 << 8;
                if (M2C_FIELD(arg1, s32 *, 0x2C8) & 0x10000) {
                    var_v0_8 = temp_a3 | (temp_a1_3 | 0x01000000);
                } else {
                    var_v0_8 = temp_a3 | temp_a1_3;
                }
                OtherFX_RecycleNew(arg1 + 0x300, temp_s4, var_v0_8 | (0x80 - ((s32) ((u8) M2C_FIELD(arg1, s8 *, 0x4B) << 0x18) >> 0x1A)), temp_a3);
            }
            if (M2C_FIELD(temp_s7, s32 *, 0x28) & 0x2000) {
                var_v0_9 = M2C_FIELD(temp_s7, u8 *, 0x51);
            } else {
                var_v0_9 = M2C_FIELD(temp_s7, u8 *, 0x50);
            }
            temp_s5 = var_v0_9 + 2;
            MATH_Cos(M2C_FIELD(arg1, s16 *, 0x396));
            temp_fp = MATH_Sin(M2C_FIELD(arg1, s16 *, 0x396)) * 0xF;
            temp_s2_2 = MATH_Cos(M2C_FIELD(arg1, s16 *, 0x396));
            MATH_Sin(M2C_FIELD(arg1, s16 *, 0x396));
            temp_s0_3 = MATH_Cos(M2C_FIELD(arg1, s16 *, 0x396));
            MATH_Sin(M2C_FIELD(arg1, s16 *, 0x396));
            temp_lo = temp_s2_2 * 0xF;
            temp_s0_4 = (s32) (temp_s0_3 * 0xA) >> 0xC;
            MATH_Cos(M2C_FIELD(arg1, s16 *, 0x396));
            temp_s4_2 = temp_lo >> 0xC;
            temp_s1 = temp_fp >> 0xC;
            temp_t2 = (s32) -(MATH_Sin(M2C_FIELD(arg1, s16 *, 0x396)) * 0xA) >> 0xC;
            M2C_ERROR(/* unknown instruction: ctc2 $t4, $0 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t5, $1 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t4, $2 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t5, $3 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t6, $4 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t4, $5 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t5, $6 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t6, $7 */);
            if (M2C_FIELD(arg1, s32 *, 0x2C8) & 0x800) {
                M2C_FIELD(arg1, s32 *, 0x2C4) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C4) | 1);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $0 */);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $1 */);
                M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x0, 0x0 */);
                temp_t1 = M2C_ERROR(/* unknown instruction: mfc2 $t1, $26 */);
                temp_a2_3 = M2C_ERROR(/* unknown instruction: mfc2 $a2, $25 */) - (temp_fp >> 0xD);
                temp_t0 = M2C_FIELD(arg1, u8 *, 0xC3);
                temp_a3_2 = M2C_ERROR(/* unknown instruction: mfc2 $a3, $27 */) - (temp_lo >> 0xD);
                temp_v1_4 = arg1 + (temp_t0 << 6);
                M2C_FIELD(temp_v1_4, s16 *, 0xC4) = (s16) (temp_a2_3 + temp_s0_4);
                M2C_FIELD(temp_v1_4, s16 *, 0xC8) = (s16) (temp_a3_2 + temp_t2);
                M2C_FIELD(temp_v1_4, s16 *, 0xCC) = (s16) (temp_a2_3 - temp_s0_4);
                M2C_FIELD(temp_v1_4, s16 *, 0xC6) = temp_t1;
                M2C_FIELD(temp_v1_4, s16 *, 0xCE) = temp_t1;
                M2C_FIELD(temp_v1_4, s16 *, 0xD0) = (s16) (temp_a3_2 - temp_t2);
                M2C_FIELD(temp_v1_4, s8 *, 0xCA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_v1_4, s8 *, 0xCB) = 1;
                } else {
                    M2C_FIELD(temp_v1_4, s8 *, 0xCB) = 0;
                }
                temp_a2_4 = temp_a2_3 + temp_s1;
                temp_a3_3 = temp_a3_2 + temp_s4_2;
                temp_t0_2 = (temp_t0 - 1) & 7;
                temp_a1_4 = arg1 + (temp_t0_2 << 6);
                temp_a0 = temp_s0_4 >> 1;
                temp_v1_5 = temp_t2 >> 1;
                M2C_FIELD(temp_a1_4, s16 *, 0xC4) = (s16) (temp_a2_4 + temp_a0);
                M2C_FIELD(temp_a1_4, s16 *, 0xC6) = temp_t1;
                M2C_FIELD(temp_a1_4, s16 *, 0xC8) = (s16) (temp_a3_3 + temp_v1_5);
                M2C_FIELD(temp_a1_4, s16 *, 0xCC) = (s16) (temp_a2_4 - temp_a0);
                M2C_FIELD(temp_a1_4, s16 *, 0xCE) = temp_t1;
                M2C_FIELD(temp_a1_4, s16 *, 0xD0) = (s16) (temp_a3_3 - temp_v1_5);
                M2C_FIELD(temp_a1_4, s8 *, 0xCA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_a1_4, s8 *, 0xCB) = 1;
                } else {
                    M2C_FIELD(temp_a1_4, s8 *, 0xCB) = 0;
                }
                M2C_FIELD(arg1, s32 *, 0x2C4) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C4) | 2);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $0 */);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $1 */);
                M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x0, 0x0 */);
                temp_t1_2 = M2C_ERROR(/* unknown instruction: mfc2 $t1, $26 */);
                temp_t0_3 = (temp_t0_2 + 1) & 7;
                temp_a2_5 = M2C_ERROR(/* unknown instruction: mfc2 $a2, $25 */) - (temp_s1 >> 1);
                temp_a3_4 = M2C_ERROR(/* unknown instruction: mfc2 $a3, $27 */) - (temp_s4_2 >> 1);
                temp_v1_6 = arg1 + (temp_t0_3 << 6);
                M2C_FIELD(temp_v1_6, s16 *, 0xD4) = (s16) (temp_a2_5 + temp_s0_4);
                M2C_FIELD(temp_v1_6, s16 *, 0xD8) = (s16) (temp_a3_4 + temp_t2);
                M2C_FIELD(temp_v1_6, s16 *, 0xDC) = (s16) (temp_a2_5 - temp_s0_4);
                M2C_FIELD(temp_v1_6, s16 *, 0xD6) = temp_t1_2;
                M2C_FIELD(temp_v1_6, s16 *, 0xDE) = temp_t1_2;
                M2C_FIELD(temp_v1_6, s16 *, 0xE0) = (s16) (temp_a3_4 - temp_t2);
                M2C_FIELD(temp_v1_6, s8 *, 0xDA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_v1_6, s8 *, 0xDB) = 1;
                } else {
                    M2C_FIELD(temp_v1_6, s8 *, 0xDB) = 0;
                }
                temp_a2_6 = temp_a2_5 + temp_s1;
                temp_a3_5 = temp_a3_4 + temp_s4_2;
                temp_a1_5 = arg1 + (((temp_t0_3 - 1) & 7) << 6);
                temp_a0_2 = temp_s0_4 >> 1;
                temp_v1_7 = temp_t2 >> 1;
                M2C_FIELD(temp_a1_5, s16 *, 0xD4) = (s16) (temp_a2_6 + temp_a0_2);
                M2C_FIELD(temp_a1_5, s16 *, 0xD6) = temp_t1_2;
                M2C_FIELD(temp_a1_5, s16 *, 0xD8) = (s16) (temp_a3_5 + temp_v1_7);
                M2C_FIELD(temp_a1_5, s16 *, 0xDC) = (s16) (temp_a2_6 - temp_a0_2);
                M2C_FIELD(temp_a1_5, s16 *, 0xDE) = temp_t1_2;
                M2C_FIELD(temp_a1_5, s16 *, 0xE0) = (s16) (temp_a3_5 - temp_v1_7);
                M2C_FIELD(temp_a1_5, s8 *, 0xDA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_a1_5, s8 *, 0xDB) = 1;
                } else {
                    M2C_FIELD(temp_a1_5, s8 *, 0xDB) = 0;
                }
            }
            if (M2C_FIELD(arg1, s32 *, 0x2C8) & 0x1000) {
                M2C_FIELD(arg1, s32 *, 0x2C4) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C4) | 4);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $0 */);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $1 */);
                M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x0, 0x0 */);
                temp_t1_3 = M2C_ERROR(/* unknown instruction: mfc2 $t1, $26 */);
                temp_a2_7 = M2C_ERROR(/* unknown instruction: mfc2 $a2, $25 */) - (temp_s1 >> 1);
                temp_t0_4 = M2C_FIELD(arg1, u8 *, 0xC3);
                temp_a3_6 = M2C_ERROR(/* unknown instruction: mfc2 $a3, $27 */) - (temp_s4_2 >> 1);
                temp_v1_8 = arg1 + (temp_t0_4 << 6);
                M2C_FIELD(temp_v1_8, s16 *, 0xE4) = (s16) (temp_a2_7 + temp_s0_4);
                M2C_FIELD(temp_v1_8, s16 *, 0xE8) = (s16) (temp_a3_6 + temp_t2);
                M2C_FIELD(temp_v1_8, s16 *, 0xEC) = (s16) (temp_a2_7 - temp_s0_4);
                M2C_FIELD(temp_v1_8, s16 *, 0xE6) = temp_t1_3;
                M2C_FIELD(temp_v1_8, s16 *, 0xEE) = temp_t1_3;
                M2C_FIELD(temp_v1_8, s16 *, 0xF0) = (s16) (temp_a3_6 - temp_t2);
                M2C_FIELD(temp_v1_8, s8 *, 0xEA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_v1_8, s8 *, 0xEB) = 1;
                } else {
                    M2C_FIELD(temp_v1_8, s8 *, 0xEB) = 0;
                }
                temp_a2_8 = temp_a2_7 + temp_s1;
                temp_a3_7 = temp_a3_6 + temp_s4_2;
                temp_t0_5 = (temp_t0_4 - 1) & 7;
                temp_a1_6 = arg1 + (temp_t0_5 << 6);
                temp_a0_3 = temp_s0_4 >> 1;
                temp_v1_9 = temp_t2 >> 1;
                M2C_FIELD(temp_a1_6, s16 *, 0xE4) = (s16) (temp_a2_8 + temp_a0_3);
                M2C_FIELD(temp_a1_6, s16 *, 0xE6) = temp_t1_3;
                M2C_FIELD(temp_a1_6, s16 *, 0xE8) = (s16) (temp_a3_7 + temp_v1_9);
                M2C_FIELD(temp_a1_6, s16 *, 0xEC) = (s16) (temp_a2_8 - temp_a0_3);
                M2C_FIELD(temp_a1_6, s16 *, 0xEE) = temp_t1_3;
                M2C_FIELD(temp_a1_6, s16 *, 0xF0) = (s16) (temp_a3_7 - temp_v1_9);
                M2C_FIELD(temp_a1_6, s8 *, 0xEA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_a1_6, s8 *, 0xEB) = 1;
                } else {
                    M2C_FIELD(temp_a1_6, s8 *, 0xEB) = 0;
                }
                M2C_FIELD(arg1, s32 *, 0x2C4) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C4) | 8);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $0 */);
                M2C_ERROR(/* unknown instruction: mtc2 $t3, $1 */);
                M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x0, 0x0 */);
                temp_t1_4 = M2C_ERROR(/* unknown instruction: mfc2 $t1, $26 */);
                temp_t0_6 = (temp_t0_5 + 1) & 7;
                temp_a2_9 = M2C_ERROR(/* unknown instruction: mfc2 $a2, $25 */) - (temp_s1 >> 1);
                temp_a3_8 = M2C_ERROR(/* unknown instruction: mfc2 $a3, $27 */) - (temp_s4_2 >> 1);
                temp_v1_10 = arg1 + (temp_t0_6 << 6);
                M2C_FIELD(temp_v1_10, s16 *, 0xF4) = (s16) (temp_a2_9 + temp_s0_4);
                M2C_FIELD(temp_v1_10, s16 *, 0xF8) = (s16) (temp_a3_8 + temp_t2);
                M2C_FIELD(temp_v1_10, s16 *, 0xFC) = (s16) (temp_a2_9 - temp_s0_4);
                M2C_FIELD(temp_v1_10, s16 *, 0xF6) = temp_t1_4;
                M2C_FIELD(temp_v1_10, s16 *, 0xFE) = temp_t1_4;
                M2C_FIELD(temp_v1_10, s16 *, 0x100) = (s16) (temp_a3_8 - temp_t2);
                M2C_FIELD(temp_v1_10, s8 *, 0xFA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_v1_10, s8 *, 0xFB) = 1;
                } else {
                    M2C_FIELD(temp_v1_10, s8 *, 0xFB) = 0;
                }
                temp_a2_10 = temp_a2_9 + temp_s1;
                temp_a3_9 = temp_a3_8 + temp_s4_2;
                temp_a1_7 = arg1 + (((temp_t0_6 - 1) & 7) << 6);
                temp_a0_4 = temp_s0_4 >> 1;
                temp_v1_11 = temp_t2 >> 1;
                M2C_FIELD(temp_a1_7, s16 *, 0xF4) = (s16) (temp_a2_10 + temp_a0_4);
                M2C_FIELD(temp_a1_7, s16 *, 0xF6) = temp_t1_4;
                M2C_FIELD(temp_a1_7, s16 *, 0xF8) = (s16) (temp_a3_9 + temp_v1_11);
                M2C_FIELD(temp_a1_7, s16 *, 0xFC) = (s16) (temp_a2_10 - temp_a0_4);
                M2C_FIELD(temp_a1_7, s16 *, 0xFE) = temp_t1_4;
                M2C_FIELD(temp_a1_7, s16 *, 0x100) = (s16) (temp_a3_9 - temp_v1_11);
                M2C_FIELD(temp_a1_7, s8 *, 0xFA) = temp_s5;
                if (sp38 & 8) {
                    M2C_FIELD(temp_a1_7, s8 *, 0xFB) = 1;
                } else {
                    M2C_FIELD(temp_a1_7, s8 *, 0xFB) = 0;
                }
            }
        } else {
            goto block_124;
        }
    } else {
block_124:
        temp_a0_5 = M2C_FIELD(arg1, s32 *, 0x300);
        if (temp_a0_5 != 0) {
            OtherFX_Stop1(temp_a0_5);
            M2C_FIELD(arg1, s32 *, 0x300) = 0;
        }
    }
    if (M2C_FIELD(arg0, s16 *, 0x44) == 0x3F) {
        if ((M2C_FIELD(gGamepads, s32 *, 0x1CEC) & 3) != (M2C_FIELD(arg1, u8 *, 0x4A) & 3)) {

        } else {
            goto block_138;
        }
    } else if ((M2C_FIELD(arg1, u8 *, 0x4FE) != 2) && ((temp_v1_12 = M2C_FIELD(gGamepads, u8 *, 0x1CA8), ((temp_v1_12 < 2U) != 0)) || ((temp_v1_12 == 2) && ((M2C_FIELD(gGamepads, s32 *, 0x1CEC) & 1) == M2C_FIELD(arg1, u8 *, 0x4A))) || ((M2C_FIELD(gGamepads, s32 *, 0x1CEC) & 3) == M2C_FIELD(arg1, u8 *, 0x4A)))) {
        if (M2C_FIELD(arg1, u8 *, 0x381) == 0) {
            temp_v1_13 = M2C_FIELD(arg1, s16 *, 0x3DC);
            if (((temp_v1_13 >= 0x81) && (((M2C_FIELD(arg1, u8 *, 0x477) + 2) << 5) >= temp_v1_13)) || (PROC_SearchForModel(M2C_FIELD(arg0, s32 *, 0x14), 0x2C) == 0)) {
block_138:
                if (M2C_FIELD(arg1, u8 *, 0x381) != 0) {
                    goto block_139;
                }
                goto block_140;
            }
        } else {
block_139:
            M2C_FIELD(arg1, u8 *, 0x381) = (u8) (M2C_FIELD(arg1, u8 *, 0x381) - 1);
block_140:
            M2C_ERROR(/* unknown instruction: ctc2 $t4, $0 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t5, $1 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t4, $2 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t5, $3 */);
            M2C_ERROR(/* unknown instruction: ctc2 $t6, $4 */);
            M2C_ERROR(/* unknown instruction: mtc2 $t3, $0 */);
            M2C_ERROR(/* unknown instruction: mtc2 $t3, $1 */);
            M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x3, 0x0 */);
            sp28 = M2C_ERROR(/* unknown instruction: mfc2 $v0, $25 */);
            sp2C = M2C_ERROR(/* unknown instruction: mfc2 $v1, $26 */);
            sp30 = M2C_ERROR(/* unknown instruction: mfc2 $a0, $27 */);
            M2C_ERROR(/* unknown instruction: mtc2 $v1, $0 */);
            M2C_ERROR(/* unknown instruction: mtc2 $v0, $1 */);
            M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x3, 0x0 */);
            M2C_ERROR(/* unknown instruction: swc2 $25, ($s0) */);
            M2C_ERROR(/* unknown instruction: swc2 $26, 0x4($s0) */);
            M2C_ERROR(/* unknown instruction: swc2 $27, 0x8($s0) */);
            VehEmitter_Exhaust(arg1, &sp18, &sp28);
            M2C_ERROR(/* unknown instruction: mtc2 $v1, $0 */);
            M2C_ERROR(/* unknown instruction: mtc2 $v0, $1 */);
            M2C_ERROR(/* unknown instruction: mvmva 0x1, 0x0, 0x0, 0x3, 0x0 */);
            M2C_ERROR(/* unknown instruction: swc2 $25, ($s0) */);
            M2C_ERROR(/* unknown instruction: swc2 $26, 0x4($s0) */);
            M2C_ERROR(/* unknown instruction: swc2 $27, 0x8($s0) */);
            VehEmitter_Exhaust(arg1, &sp18, &sp28);
        }
    }
    if (M2C_FIELD(arg1, s16 *, 0x402) != 0) {
        M2C_FIELD(arg1, s16 *, 0x508) = 0x1000;
        M2C_FIELD(M2C_FIELD(arg1, void **, 0x1C), s16 *, 0x22) = 0x1000;
    }
    if (M2C_FIELD(arg1, s32 *, 0x28) != 0) {
        M2C_FIELD(temp_s7, s16 *, 0x22) = 0x1000;
    }
    temp_v1_14 = M2C_FIELD(arg1, u8 *, 0x376);
    if ((temp_v1_14 != 0) && (temp_v1_14 != 2)) {
        M2C_FIELD(arg1, s32 *, 0x2C8) = (s32) (M2C_FIELD(arg1, s32 *, 0x2C8) & 0xFFF7FFFF);
    }
    if ((u32) (M2C_FIELD(arg1, u8 *, 0x376) - 4) >= 2U) {
        if (!(M2C_FIELD(arg1, s32 *, 0x2C8) & 1)) {
            var_a1_4 = 0;
            if (M2C_FIELD(arg1, s16 *, 0x3FC) < 0x80) {
                temp_v0_6 = M2C_FIELD(arg1, s8 *, 0x4B);
                var_a1_5 = 0x12;
                if ((temp_v0_6 < 0) || (var_a1_5 = 0x22, (temp_v0_6 > 0))) {
                    GAMEPAD_JogCon1(arg1, var_a1_5, 0x20);
                }
                var_a1_4 = 0;
            }
            var_a2_2 = 0;
            goto block_162;
        }
        goto block_157;
    }
block_157:
    GAMEPAD_JogCon2(arg1, 0x27, 0);
    if (M2C_FIELD(arg1, s16 *, 0x3D4) != 0) {
        if (M2C_FIELD(gGamepads, s32 *, 0x1CEC) & 3) {
            var_a1_4 = 0xF0;
        } else {
            var_a1_4 = 0x27;
        }
        var_a2_2 = 0x100;
block_162:
        GAMEPAD_JogCon2(arg1, var_a1_4, var_a2_2);
    }
}