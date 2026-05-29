typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void *PROC_SearchForModel(void *arg0, s32 arg1) {
    void *result;

    while (arg0 != NULL) {
        if (M2C_FIELD(arg0, s16 *, 0x44) == arg1) {
            return arg0;
        }

        result = PROC_SearchForModel(M2C_FIELD(arg0, void **, 0x14), arg1);
        if (result != NULL) {
            return result;
        }

        arg0 = M2C_FIELD(arg0, void **, 0x10);
    }

    return arg0;
}