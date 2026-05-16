typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008D2AC;

s32 LOAD_IsOpen_AdvHub(void) {
    return M2C_FIELD(D_8008D2AC, u8 *, 0x2541) == 2;
}