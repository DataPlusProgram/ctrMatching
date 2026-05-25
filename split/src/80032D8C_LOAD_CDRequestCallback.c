typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

s8 levBigLodIndex;

void LOAD_CDRequestCallback(void *arg0) {
    M2C_UNK (*temp_v0)();

    temp_v0 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x14);
    if (temp_v0 != NULL) {
        temp_v0();
    }
    levBigLodIndex = 1;
}