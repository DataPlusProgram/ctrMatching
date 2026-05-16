typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void _Unknown_8007DE98(void *arg0) {
    M2C_FIELD(arg0, s8 *, 0x37) = 0x4B;
    M2C_FIELD(arg0, s32 *, 0x2C) = 0;
    M2C_FIELD(arg0, s8 *, 0x36) = 0;
}