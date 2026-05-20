typedef signed char s8;
typedef short s16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void func_800765B4(void *arg0) __attribute__((noreturn));
extern s32 D_8008C3B4;

void SpuSetVoicePitch(s32 arg0, s16 arg1) {
    void *tempA0;
    volatile s32 stack0;
    volatile s32 stack1;

    tempA0 = (void *)((arg0 << 4) + D_8008C3B4);
    M2C_FIELD(tempA0, s16 *, 4) = arg1;

    stack1 = 1;
    stack0 = 0;

    func_800765B4(tempA0);
}