typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LIST_AddFront();                 /* extern */
M2C_UNK LIST_Clear();                         /* extern */

void JitPool_Clear(void *arg0) {
    s32 var_s2;
    u32 var_s0;

    var_s2 = M2C_FIELD(arg0, s32 *, 0x24);
    var_s0 = 0;
    LIST_Clear();
    LIST_Clear(arg0 + 0xC);
    if (M2C_FIELD(arg0, u32 *, 0x18) != 0) {
        do {
            LIST_AddFront(arg0, var_s2);
            var_s0 += 1;
            var_s2 += ((u32) M2C_FIELD(arg0, u32 *, 0x1C) >> 2) * 4;
        } while (var_s0 < (u32) M2C_FIELD(arg0, u32 *, 0x18));
    }
}