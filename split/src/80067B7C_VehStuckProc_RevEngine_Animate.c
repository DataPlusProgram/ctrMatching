typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK OtherFX_Play_Echo();                         /* extern */
s32 VehCalc_InterpBySpeed();                         /* extern */
s16 VehCalc_MapToRange(s32, s32, s32, s32, s32);     /* extern */
extern void *gGamepads;

void VehStuckProc_RevEngine_Animate(void *arg0, void *arg1) {
    s16 temp_v1_2;
    s16 var_a1_3;
    s32 var_a2;
    s32 temp_a0;
    s32 temp_a1;
    s32 temp_a2;
    s32 temp_a2_2;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a1;
    s32 var_a1_2;
    s32 var_v0;
    s32 var_v0_2;
    s32 var_v0_3;
    u16 temp_v1;
    u8 var_a3;
    void *temp_s1;

    temp_s1 = M2C_FIELD(arg0, void **, 0x34);

    if ((M2C_FIELD(arg1, s16 *, 0x39E) > 0) && (M2C_FIELD(arg1, s16 *, 0x58E) == 0) && !(M2C_FIELD(arg1, u8 *, 0x593) & 3)) {
        temp_a0 = M2C_FIELD(arg1, s32 *, 0x588);
        temp_a2 = M2C_FIELD(arg1, s32 *, 0x584);
        var_v0 = temp_a0 - temp_a2;

        if (var_v0 < 0) {
            var_v0 = -var_v0;
        }

        var_a1 = var_v0 >> 1;
        var_v0_2 = var_a1 < 0x100;

        if (var_a1 >= 0x1389) {
            var_a1 = 0x1388;
            var_v0_2 = var_a1 < 0x100;
        }

        if (var_v0_2 != 0) {
            var_a1 = 0x100;
        }

        temp_v0 = VehCalc_InterpBySpeed(temp_a0, var_a1, temp_a2);
        M2C_FIELD(arg1, s32 *, 0x588) = temp_v0;
        M2C_FIELD(arg1, u8 *, 0x592) = 2U;

        if (temp_v0 >= M2C_FIELD(arg1, s32 *, 0x584)) {
            temp_v1 = M2C_FIELD(arg1, u16 *, 0x58C) + M2C_FIELD(gGamepads, u16 *, 0x1D04);
            M2C_FIELD(arg1, u16 *, 0x58C) = temp_v1;

            if ((s16) temp_v1 >= 0xC1) {
                M2C_FIELD(arg1, u8 *, 0x592) = 0U;
                M2C_FIELD(arg1, u8 *, 0x593) = (u8) (M2C_FIELD(arg1, u8 *, 0x593) | 3);
                OtherFX_Play_Echo(0xF, 1, M2C_FIELD(arg1, u16 *, 0x2CA) & 1);
            }
        } else {
            M2C_FIELD(arg1, u16 *, 0x58C) = 0U;
        }
    } else {
        M2C_FIELD(arg1, u16 *, 0x58C) = 0U;

        if (M2C_FIELD(arg1, u8 *, 0x592) == 2) {
            M2C_FIELD(arg1, s16 *, 0x58E) = 0x100;
            M2C_FIELD(arg1, u8 *, 0x592) = 0U;

            if (M2C_FIELD(arg1, s16 *, 0x42E) < M2C_FIELD(arg1, s32 *, 0x588)) {
                M2C_FIELD(arg1, u8 *, 0x592) = 1U;
            }
        }

        if (M2C_FIELD(arg1, u8 *, 0x592) != 0) {
            temp_v1_2 = M2C_FIELD(arg1, s16 *, 0x42E);

            if (M2C_FIELD(arg1, s32 *, 0x588) < temp_v1_2) {
                temp_a2_2 = temp_v1_2 + M2C_FIELD(arg1, s16 *, 0x432);
                M2C_FIELD(arg1, u8 *, 0x592) = 0U;
                M2C_FIELD(arg1, s32 *, 0x584) = VehCalc_InterpBySpeed(
                    M2C_FIELD(arg1, s32 *, 0x584),
                    ((temp_a2_2 - temp_v1_2) / 3) + 3,
                    temp_a2_2
                );
            }
        }

        temp_a1 = M2C_FIELD(arg1, s32 *, 0x588);

        if (temp_a1 > 0) {
            var_a1_2 = temp_a1 >> 1;

            if (M2C_FIELD(arg1, u8 *, 0x593) & 2) {
                var_v0_3 = var_a1_2 < 0x100;

                if (var_a1_2 >= 0xBB9) {
                    var_a1_2 = 0xBB8;
                    goto block_25;
                }
            } else {
                var_v0_3 = var_a1_2 < 0x100;

                if (var_a1_2 >= 0x3E9) {
                    var_a1_2 = 0x3E8;
block_25:
                    var_v0_3 = var_a1_2 < 0x100;
                }
            }

            if (var_v0_3 != 0) {
                var_a1_2 = 0x100;
            }

            temp_v0_2 = M2C_FIELD(arg1, s32 *, 0x588) - var_a1_2;
            M2C_FIELD(arg1, s32 *, 0x588) = temp_v0_2;

            if (temp_v0_2 <= 0) {
                M2C_FIELD(arg1, s16 *, 0x590) = 0xC0;
                M2C_FIELD(arg1, s32 *, 0x588) = 0;
            }
        } else {
            M2C_FIELD(arg1, u8 *, 0x593) = (u8) (M2C_FIELD(arg1, u8 *, 0x593) & 0xFD);
            M2C_FIELD(arg1, s32 *, 0x584) =
                M2C_FIELD(arg1, s16 *, 0x42E) + (M2C_FIELD(arg1, s16 *, 0x432) / 3);
        }

        if (M2C_FIELD(arg1, s16 *, 0x39E) <= 0) {
            M2C_FIELD(arg1, u8 *, 0x593) = (u8) (M2C_FIELD(arg1, u8 *, 0x593) & 0xFE);
        }
    }

    if (M2C_FIELD(arg1, s32 *, 0x590) & 0x0200FFFF) {
        M2C_FIELD(arg1, s8 *, 0x4FE) = 2;
    } else if (M2C_FIELD(arg1, s32 *, 0x588) >= M2C_FIELD(arg1, s16 *, 0x42E)) {
        M2C_FIELD(arg1, s8 *, 0x4FE) = 1;
    } else {
        M2C_FIELD(arg1, s8 *, 0x4FE) = 0;
    }

    var_a2 = M2C_FIELD(arg1, s16 *, 0x42E);
    temp_v0_3 = M2C_FIELD(arg1, s32 *, 0x588);
    M2C_FIELD(arg1, u16 *, 0x36E) = (u16) temp_v0_3;

    if (temp_v0_3 < var_a2) {
        var_a3 = M2C_FIELD(arg1, u8 *, 0x476);

        M2C_FIELD(arg1, s16 *, 0x3DC) = VehCalc_MapToRange(
            temp_v0_3,
            0,
            var_a2,
            var_a3 << 5,
            (M2C_FIELD(arg1, u8 *, 0x477) << 5) + 1
        );
    } else {
        var_a1_3 = var_a2;
        var_a2 = var_a1_3 + M2C_FIELD(arg1, s16 *, 0x432);
        var_a3 = M2C_FIELD(arg1, u8 *, 0x477);

        M2C_FIELD(arg1, s16 *, 0x3DC) = VehCalc_MapToRange(
            temp_v0_3,
            var_a1_3,
            var_a2,
            var_a3 << 5,
            1
        );
    }

    M2C_FIELD(arg1, s32 *, 0x490) = 0;

    temp_v0_3 = (s32) (M2C_FIELD(arg1, u16 *, 0x36E) << 0x10) >> 0x16;
    M2C_FIELD(arg1, u16 *, 0x40C) = (u16) temp_v0_3;

    if (temp_v0_3 >= 0x401) {
        M2C_FIELD(arg1, u16 *, 0x40C) = 0x400U;
    } else if (temp_v0_3 < 0) {
        M2C_FIELD(arg1, u16 *, 0x40C) = 0U;
    }

    M2C_FIELD(temp_s1, s16 *, 0x1E) = (s16) (0xCCC - M2C_FIELD(arg1, u16 *, 0x40C));
    M2C_FIELD(temp_s1, s16 *, 0x1C) = (s16) ((((s16) M2C_FIELD(arg1, u16 *, 0x40C) * 6) / 10) + 0xCCC);
    M2C_FIELD(temp_s1, s16 *, 0x20) = (s16) ((((s16) M2C_FIELD(arg1, u16 *, 0x40C) * 6) / 10) + 0xCCC);
}