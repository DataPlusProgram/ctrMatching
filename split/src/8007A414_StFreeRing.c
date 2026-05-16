typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern s32 D_8009EC24;
extern s32 D_8009EC30;
extern s32 D_8009EC34;

s32 StFreeRing(s32 arg0) {
    s32 temp_a1;
    s32 temp_v0;
    s32 var_a0;
    s32 var_v0;
    s32 temp_v0_2;
    u16 temp_v1_2;
    void *temp_v1;

    temp_a1 = (arg0 - (D_8009EC24 + (D_8009EC34 << 5))) / 2016;
    temp_v1 = (void *)((s8 *)D_8009EC24 + (temp_a1 << 5));
    temp_v1_2 = M2C_FIELD(temp_v1, u16 *, 6);
    var_v0 = 1;

    if (M2C_FIELD(temp_v1, s16 *, 0) == 4) {
        temp_v0_2 = (s16) temp_v1_2;
        if (temp_v0_2 > 0) {
            var_a0 = 0;
            do {
                temp_v0 = var_a0 + temp_a1;
                var_a0 += 1;
                *(s16 *)((s8 *)D_8009EC24 + (temp_v0 << 5)) = 0;
            } while (var_a0 < temp_v0_2);
        } else {
            var_a0 = 0;
        }

        D_8009EC30 = var_a0 + temp_a1;
        var_v0 = 0;
    }

    return var_v0;
}