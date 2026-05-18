typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

#define NULL 0
#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern s32 D_8008D2AC;

s32 VehGroundShadow_Subset1(void *arg0, s32 arg1)
{
    void *tempA1;
    s32 base;
    s32 offset;

    base = D_8008D2AC;
    offset = arg1 * 4;
    tempA1 = M2C_FIELD((base + offset), void **, 0x1EEC);

    if (tempA1 != NULL) {
        goto success;
    }

    return 0;

success:
    M2C_FIELD(arg0, s32 *, 0) = M2C_FIELD(tempA1, s32 *, 0x14);
    M2C_FIELD(arg0, s32 *, 4) = (M2C_FIELD(tempA1, s32 *, 0x18) & 0xFF9FFFFF) | 0x400000;
    M2C_FIELD(arg0, u16 *, 8) = M2C_FIELD(tempA1, u16 *, 0x1C);
    M2C_FIELD(arg0, u16 *, 0xA) = M2C_FIELD(tempA1, u16 *, 0x1E);

    return 1;
}