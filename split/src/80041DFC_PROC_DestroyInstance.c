typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK INSTANCE_Death();                        /* extern */

void PROC_DestroyInstance(void *arg0) {
    INSTANCE_Death(M2C_FIELD(arg0, s32 *, 0x34));
}