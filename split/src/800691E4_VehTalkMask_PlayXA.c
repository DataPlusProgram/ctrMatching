typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK CDSYS_XAPlay();                          /* extern */
s32 VehPickupItem_MaskBoolGoodGuy();             /* extern */
extern void *D_8008D2AC;

void VehTalkMask_PlayXA(s32 arg0, s16 arg1) {
    register s16 temp_s1 asm("$17");
    s16 var_s0;
    s32 temp_a0;

    temp_s1 = arg1;
    temp_a0 = M2C_FIELD(D_8008D2AC, s32 *, 0x24EC);
    var_s0 = temp_s1;

    if (temp_a0 != 0) {
        if ((VehPickupItem_MaskBoolGoodGuy(temp_a0) << 0x10) == 0) {
            var_s0 = temp_s1 + 0x1F;
        }
    }

    CDSYS_XAPlay(1, var_s0);
}