typedef signed char s8;
typedef unsigned char u8;
typedef short s16;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK memmove();           /* extern */
s16 D_8008D91A;
extern void *gT;

void SubmitName_RestoreName(s16 arg0) {
    s16 var_v1;

    D_8008D91A = arg0;
    memmove(gT + 0x1D65, gT + 0x1D54, 0x11);
    var_v1 = 0;
    if (M2C_FIELD(gT, u8 *, 0x1D65) != 0) {
        var_v1 = 0x3E9;
    }
    M2C_FIELD(gT, s16 *, 0x1D4C) = var_v1;
}