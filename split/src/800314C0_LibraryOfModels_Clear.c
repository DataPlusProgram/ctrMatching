typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void LibraryOfModels_Clear(s32 arg0) {
    s32 var_v0;
    void *var_a0;

    var_v0 = 0xE1;
    var_a0 = arg0 + 0x384;
    do {
        M2C_FIELD(var_a0, s32 *, 0x2160) = 0;
        var_v0 -= 1;
        var_a0 -= 4;
    } while (var_v0 >= 0);
}