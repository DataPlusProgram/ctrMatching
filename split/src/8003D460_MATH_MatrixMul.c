typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK ApplyMatrixLV_stub();               /* extern */
M2C_UNK MatrixRotate();                             /* extern */

void MATH_MatrixMul(void *arg0, void *arg1, s32 arg2) {
    MatrixRotate();
    ApplyMatrixLV_stub(arg2 + 0x14, arg0 + 0x14);
    M2C_FIELD(arg0, s32 *, 0x14) = (s32) (M2C_FIELD(arg0, s32 *, 0x14) + M2C_FIELD(arg1, s32 *, 0x14));
    M2C_FIELD(arg0, s32 *, 0x18) = (s32) (M2C_FIELD(arg0, s32 *, 0x18) + M2C_FIELD(arg1, s32 *, 0x18));
    M2C_FIELD(arg0, s32 *, 0x1C) = (s32) (M2C_FIELD(arg0, s32 *, 0x1C) + M2C_FIELD(arg1, s32 *, 0x1C));
}