typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern M2C_UNK D_80011E00;
extern void *D_8008AD78;
extern M2C_UNK (*D_8008AD7C)(M2C_UNK *, s32);
extern u8 D_8008AD82;

void DrawOTag(s32 arg0) {
    if ((u8) D_8008AD82 >= 2U) {
        D_8008AD7C(&D_80011E00, arg0);
    }
    M2C_FIELD(D_8008AD78, M2C_UNK (**)(s32, s32, M2C_UNK, M2C_UNK), 8)(M2C_FIELD(D_8008AD78, s32 *, 0x18), arg0, 0, 0);
}