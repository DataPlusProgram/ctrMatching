typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK D_80011D2C;
extern M2C_UNK (*D_8008AD7C)(M2C_UNK *, s32);
extern M2C_UNK D_8008AD82;

s32 DrawSyncCallback(s32 arg0)
{
    s8 *ptr;
    s32 temp_v0;
    s32 temp_s1;

    ptr = (s8 *)&D_8008AD82;
    temp_s1 = arg0;

    if ((u8)ptr[0] >= 2U)
    {
        D_8008AD7C(&D_80011D2C, temp_s1);
    }

    temp_v0 = M2C_FIELD(ptr, s32 *, 0xA);
    M2C_FIELD(ptr, s32 *, 0xA) = temp_s1;
    return temp_v0;
}