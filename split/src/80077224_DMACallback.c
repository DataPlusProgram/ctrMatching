typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *D_8008C020;

void DMACallback(void) {
    M2C_FIELD(D_8008C020, M2C_UNK (**)(), 4)();
}