typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK MatrixRotate(); /* extern */
extern void *gGamepads;

void UI_ThTick_big1(void *arg0)
{
    void *temp_a1;
    void *temp_s0;
    s32 temp_a0;
    s32 var_v0;

    temp_a1 = M2C_FIELD(arg0, void **, 0x30);
    temp_s0 = M2C_FIELD(arg0, void **, 0x34);

    var_v0 = M2C_FIELD(temp_a1, u16 *, 6);
    temp_a0 = (s32)temp_s0 + 0x30;
    M2C_FIELD(temp_s0, s16 *, 0x32) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x34) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x36) = 0;
    M2C_FIELD(temp_s0, u16 *, 0x30) = var_v0;

    var_v0 = M2C_FIELD(temp_a1, u16 *, 6);
    M2C_FIELD(temp_s0, s16 *, 0x3A) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x3C) = 0;
    M2C_FIELD(temp_s0, s16 *, 0x3E) = 0;
    M2C_FIELD(temp_s0, u16 *, 0x38) = var_v0;

    var_v0 = M2C_FIELD(temp_a1, u16 *, 6);
    M2C_FIELD(temp_s0, u16 *, 0x40) = var_v0;

    MatrixRotate(temp_a0, temp_a1 + 8, temp_a0);

    var_v0 = M2C_FIELD(gGamepads, s32 *, 0x1D30) & 0xFF0100;

    if (var_v0 != 0x100)
    {
        var_v0 = M2C_FIELD(temp_s0, s32 *, 0x28) | 0x80;
    }
    else
    {
        var_v0 = M2C_FIELD(temp_s0, s32 *, 0x28) & ~0x80;
    }

    M2C_FIELD(temp_s0, s32 *, 0x28) = var_v0;
}