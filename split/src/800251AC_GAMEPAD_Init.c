typedef signed char s8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK PadInitMtap();                      /* extern */
M2C_UNK PadStartCom();                              /* extern */

void GAMEPAD_Init(void *arg0) {
    s32 var_a0;
    void *var_v1;
    void **new_var;

    PadInitMtap(arg0 + 0x2D0, arg0 + 0x2F2);
    PadStartCom();

    var_a0 = 0;
    var_v1 = arg0;
    do {
        M2C_FIELD(*(new_var = &var_v1), s16 *, 0x26) = 0;
        M2C_FIELD(var_v1, s8 *, 0x44) = 0;
        var_v1 += 0x50;
    } while (++var_a0 < 8);

    M2C_FIELD(arg0, s32 *, 0x318) = -1;
}