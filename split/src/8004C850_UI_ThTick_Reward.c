typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ConvertRotToMatrix();         /* extern */
M2C_UNK MatrixRotate();       /* extern */
M2C_UNK Vector_SpecLightSpin2D(); /* extern */
extern void *gGamepads;
void UI_ThTick_Reward(void *arg0) {
    s32 var_v0;
    void *temp_s0;
    void *temp_s1;
    void *temp_s2;

    temp_s2 = M2C_FIELD(arg0, void **, 0x34);
    temp_s0 = M2C_FIELD(arg0, void **, 0x30);
    M2C_FIELD(temp_s0, u16 *, 2) = (u16) (M2C_FIELD(temp_s0, u16 *, 2) + 0x40);
    Vector_SpecLightSpin2D(temp_s2, temp_s0, temp_s0 + 0x28);
    temp_s1 = temp_s2 + 0x30;
    ConvertRotToMatrix(temp_s1, temp_s0);
    MatrixRotate(temp_s1, temp_s0 + 8, temp_s1);

    if (((M2C_FIELD(gGamepads, s32 *, 0x1D30) & 0xFF0100) != 0x100) || (M2C_FIELD(gGamepads, s16 *, 0x139A) < 0x1000)) {
        var_v0 = M2C_FIELD(temp_s2, s32 *, 0x28) | 0x80;
    } else {
        var_v0 = M2C_FIELD(temp_s2, s32 *, 0x28);
        var_v0 &= ~0x80;
    }
    M2C_FIELD(temp_s2, s32 *, 0x28) = var_v0;
}