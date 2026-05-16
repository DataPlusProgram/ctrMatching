typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 VehPhysGeneral_GetBaseSpeed(void *arg0) {
    void *arg2;
    s32 temp_a0;
    s32 temp_v0;
    s32 temp_v1;
    s32 var_a1;
    s32 var_a3;
    s32 var_t0;

    arg2 = arg0;

    var_a3 = M2C_FIELD(arg2, s8 *, 0x30);
    if (var_a3 >= 10) {
        var_a3 = 9;
    }

    var_t0 = M2C_FIELD(arg2, s8 *, 0x35);
    if (var_t0 >= 6) {
        var_t0 = 5;
    }

    temp_v0 = M2C_FIELD(arg2, s16 *, 0x42E);
    var_a1 = M2C_FIELD(arg2, s16 *, 0x42C);
    temp_v1 = (((temp_v0 - var_a1) << 0xC) / 5) - 1;

    temp_v0 = (var_a3 * temp_v1) / 10;
    var_t0 = var_t0 * temp_v1;
    var_a3 = (temp_v0 + var_t0) >> 0xC;

    if (M2C_FIELD(arg2, s32 *, 0x2C8) & 0x800000) {
        var_a3 += M2C_FIELD(arg2, s16 *, 0x436);
    }

    if (M2C_FIELD(arg2, s16 *, 0x3E2) != 0) {
        temp_a0 = M2C_FIELD(arg2, s16 *, 0x430);
        temp_v1 = M2C_FIELD(arg2, s16 *, 0x3E4);
        temp_v0 = M2C_FIELD(arg2, s16 *, 0x432);

        temp_v0 = temp_v0 - temp_a0;
        temp_v0 = temp_v0 << 1;
        temp_a0 = temp_a0 + temp_v0;
        temp_a0 = temp_a0 - temp_v1;
        var_a1 += temp_v1;

        if (temp_a0 < 0) {
            temp_a0 = 0;
        }

        if (temp_a0 < var_a3) {
            var_a3 = temp_a0;
        }
    }

    var_a1 += var_a3;

    var_a3 = 0;
    if (M2C_FIELD(arg2, s32 *, 0x18) != 0) {
        temp_v0 = M2C_FIELD(arg2, u16 *, 0x438);
        temp_v0 = temp_v0 << 0x10;
        var_a3 = temp_v0 >> 0x11;
    }

    if (M2C_FIELD(arg2, s16 *, 0x402) != 0) {
        var_a3 = M2C_FIELD(arg2, s16 *, 0x438);
    } else if (M2C_FIELD(arg2, s16 *, 0x404) != 0) {
        var_a3 = M2C_FIELD(arg2, s16 *, 0x438);
    } else if (M2C_FIELD(arg2, s16 *, 0x50A) == 0) {
        var_a3 = M2C_FIELD(arg2, s16 *, 0x438);
    }

    if (M2C_FIELD(arg2, s16 *, 0xC) != 0) {
        temp_v0 = 20;
        temp_v1 = M2C_FIELD(arg2, s16 *, 0x482);
        temp_a0 = M2C_FIELD(arg2, s16 *, 0x438);
        temp_v0 = temp_v0 - temp_v1;
        temp_a0 = (temp_a0 * temp_v0) >> 4;

        if (var_a3 < temp_a0) {
            var_a3 = temp_a0;
        }
    }

    var_a1 -= var_a3;

    if (var_a1 >= 0x6401) {
        var_a1 = 0x6400;
    }

    return var_a1;
}