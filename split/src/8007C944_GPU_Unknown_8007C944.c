typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

extern M2C_UNK D_8008C734;

void GPU_Unknown_8007C944(s32 arg0, s32 arg1) {
    s8 *tempV0;
    s32 *tempA0;

    tempV0 = (s8 *)&D_8008C734;
    arg0 = arg0 * 4;
    tempA0 = (s32 *)(tempV0 + arg0);

    if (arg1 != *tempA0) {
        *tempA0 = arg1;
    }
}