typedef signed char s8;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s32 _Unknown_8007DECC(); /* extern */
extern s32 *D_8008C7E0;
extern void *D_8008C7E4;

s32 GPU_Unknown_8007D49C(void) {
    s32 *tempV1;
    void *tempA0;
    s32 tempV0;

    tempV1 = D_8008C7E0;
    tempV0 = -0x81;
    tempA0 = D_8008C7E4;
    *tempV1 = tempV0;

    if (!(M2C_FIELD(tempA0, u16 *, 4) & 0x80)) {
        goto block3;
    }

loop1:
    if (_Unknown_8007DECC() != 0) {
        return 0;
    }

    if (M2C_FIELD(D_8008C7E4, u16 *, 4) & 0x80) {
        goto loop1;
    }

block3:
    tempA0 = D_8008C7E4;
    M2C_FIELD(tempA0, u16 *, 0xA) = M2C_FIELD(tempA0, u16 *, 0xA) | 0x10;
    return 1;
}