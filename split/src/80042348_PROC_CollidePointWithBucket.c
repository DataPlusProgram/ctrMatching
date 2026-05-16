typedef signed char s8;
typedef int s32;

#define NULL 0

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK PROC_CollidePointWithSelf();

void PROC_CollidePointWithBucket(void *arg0, M2C_UNK arg1) {
    void *var_s0;
    M2C_UNK var_s1;

    var_s0 = arg0;
    var_s1 = arg1;

    if (var_s0 != NULL) {
        do {
            PROC_CollidePointWithSelf(var_s0, var_s1);
            var_s0 = M2C_FIELD(var_s0, void **, 0x10);
        } while (var_s0 != NULL);
    }
}