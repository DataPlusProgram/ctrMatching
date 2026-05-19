typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

typedef struct {
    char pad0[0x44];
    s32 unk44;
    s32 unk48;
    s32 unk4C;
} M2cPlaySound3DArg1;

M2C_UNK GTE_AudioLR_Inst();
u32 GTE_GetSquaredLength();
M2C_UNK OtherFX_Play_LowLevel();
u32 SquareRoot0_stub();
s32 VehCalc_MapToRange();
s32 ratan2();

extern void *D_8008D2AC;

void PlaySound3D(s32 arg0, M2cPlaySound3DArg1 *arg1)
{
    s32 sp18[12];
    u32 sp48[4];
    s32 var_a2;
    s32 var_s0;
    s32 var_s1;
    s32 var_s2;
    s32 var_s3;
    s32 var_s4;
    s32 var_v0;
    u32 temp_v0;
    u32 temp_v0_2;
    u32 var_s5;
    void *temp_a0;
    void *temp_a1;
    void *temp_a1_2;
    void *temp_s0_2;

    temp_a1 = D_8008D2AC;
    var_s5 = 0x2328;
    var_s1 = 0;
    var_s4 = 0;

    if (M2C_FIELD(temp_a1, u8 *, 0x1CA8) != 0) {
        var_s3 = 0;
        var_s2 = 0;
        do {
            temp_a0 = (s8 *)sp18 + var_s2;
            temp_a1_2 = temp_a1 + var_s3;

            M2C_FIELD(temp_a0, s32 *, 0) = arg1->unk44 - M2C_FIELD(temp_a1_2, s16 *, 0x168);
            M2C_FIELD(temp_a0, s32 *, 4) = arg1->unk48 - M2C_FIELD(temp_a1_2, s16 *, 0x16A);
            M2C_FIELD(temp_a0, s32 *, 8) = arg1->unk4C - M2C_FIELD(temp_a1_2, s16 *, 0x16C);

            temp_v0 = GTE_GetSquaredLength(temp_a0, temp_a1_2);
            sp48[var_s1] = temp_v0;

            temp_v0_2 = SquareRoot0_stub(temp_v0);
            sp48[var_s1] = temp_v0_2;

            if (temp_v0_2 < var_s5) {
                var_s5 = temp_v0_2;
                var_s4 = var_s1;
            }

            var_s3 += 0x110;
            temp_a1 = D_8008D2AC;
            var_s2 += 0xC;
        } while ((var_s1 += 1) < (s32)M2C_FIELD(temp_a1, u8 *, 0x1CA8));
    }

    if (var_s5 != 0x2328) {
        temp_s0_2 = (s8 *)sp18 + (var_s4 * 0xC);

        GTE_AudioLR_Inst((var_s4 * 0x110) + D_8008D2AC + 0x1D0, temp_s0_2);

        var_s0 = ratan2(M2C_FIELD(temp_s0_2, s32 *, 0), -M2C_FIELD(temp_s0_2, s32 *, 8));
        var_s0 += 0x800;
        var_s0 = -((var_s0 << 0x14) >> 0x17);

        if (var_s0 >= 0x81) {
            var_v0 = 0x100;
            goto block_9;
        }

        var_v0 = -0x100;
        if (var_s0 < -0x80) {
block_9:
            var_s0 = var_v0 - var_s0;
        }

        var_s0 += 0x80;
        if (var_s0 < 0) {
            var_s0 = 0;
            goto block_14;
        }

        var_v0 = var_s5 < 0x12D;
        if (var_s0 >= 0x100) {
            var_s0 = 0xFF;
block_14:
            var_v0 = var_s5 < 0x12D;
        }

        if (var_v0 == 0) {
            var_a2 = VehCalc_MapToRange(var_s5, 0x12C, 0x2328, 0xFF, 0);
        } else {
            var_a2 = 0xFF;
        }

        OtherFX_Play_LowLevel(
            arg0 & 0xFFFF,
            1,
            ((M2C_FIELD(M2C_FIELD(D_8008D2AC + (var_s4 * 0xDC), void **, 0x14B4), u16 *, 0x12) & 0x80) << 0x18)
                | ((var_a2 & 0xFF) << 0x10)
                | ((var_s0 & 0xFF) | 0x8000)
        );
    }
}