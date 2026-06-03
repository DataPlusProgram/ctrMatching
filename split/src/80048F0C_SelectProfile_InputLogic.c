typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK OtherFX_Play();             /* extern */
M2C_UNK RECTMENU_ClearInput();                      /* extern */
extern s16 D_8008D48E;
extern s32 buttonTapPerPlayer;
s16 flags_timeTrialEndOfRace;

s32 SelectProfile_InputLogic(void *arg0, s16 arg1, s32 arg2) {
    s32 var_s2;
    u16 temp_a0;
    u16 var_v0;

    var_s2 = 0;
    if (buttonTapPerPlayer & 0x4007F) {
        if (!(arg2 & 1)) {
            temp_a0 = M2C_FIELD(arg0, u16 *, 0x1A);
            var_v0 = temp_a0 - 2;
            if ((buttonTapPerPlayer & 1) || (var_v0 = temp_a0 + 2, ((buttonTapPerPlayer & 2) != 0)) || (var_v0 = temp_a0 ^ 1, ((buttonTapPerPlayer & 0xC) != 0))) {
                M2C_FIELD(arg0, u16 *, 0x1A) = var_v0;
            }
            if ((s16) M2C_FIELD(arg0, u16 *, 0x1A) < 0) {
                M2C_FIELD(arg0, u16 *, 0x1A) = 0U;
            }
            if ((s16) M2C_FIELD(arg0, u16 *, 0x1A) >= arg1) {
                M2C_FIELD(arg0, u16 *, 0x1A) = (u16) (arg1 - 1);
            }
            if ((s16) M2C_FIELD(arg0, u16 *, 0x1A) != (s16) temp_a0) {
                OtherFX_Play(0, 1);
            }
            if (buttonTapPerPlayer & 0x50) {
                if (arg1 == 0) {
                    if (flags_timeTrialEndOfRace == 1) {
                        goto block_16;
                    }
                    goto block_18;
                }
block_16:
                OtherFX_Play(1, 1);
                var_s2 = 1;
                if (D_8008D48E == 1) {
                    M2C_FIELD(arg0, u16 *, 0x1A) = 0U;
                }
            } else {
block_18:
                if (buttonTapPerPlayer & 0x40020) {
                    OtherFX_Play(2, 1);
                    var_s2 = 1;
                    M2C_FIELD(arg0, u16 *, 0x1A) = -1U;
                }
            }
        } else {
            if (buttonTapPerPlayer & 0x40020) {
                OtherFX_Play(2, 1);
                var_s2 = 1;
                M2C_FIELD(arg0, u16 *, 0x1A) = -1U;
            }
            if ((arg2 & 2) && (buttonTapPerPlayer & 0x50)) {
                OtherFX_Play(1, 1);
                var_s2 = 1;
            }
        }
        RECTMENU_ClearInput();
    }
    return var_s2;
}