typedef signed char s8;
typedef short s16;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK CTR_CycleTex_Model();           /* extern */

void CTR_CycleTex_AllModels(s32 arg0, void **arg1, M2C_UNK arg2) {
    register s32 var_s3 asm("s3");
    register s32 var_s4 asm("s4");
    register M2C_UNK temp_s5 asm("s5");
    register u32 var_s0 asm("s0");
    register u32 var_s1 asm("s1");
    u32 temp_s2;
    void *temp_v1;
    s32 temp_a0;

    var_s3 = arg0;
    var_s4 = (s32) arg1;
    temp_s5 = arg2;

    if ((var_s4 != 0) && (var_s3 != 0)) {
loop_2:
        temp_v1 = M2C_FIELD(var_s4, void **, 0);
        if (temp_v1 != NULL) {
            var_s0 = M2C_FIELD(temp_v1, u32 *, 0x14);
            temp_s2 = var_s0 + (M2C_FIELD(temp_v1, s16 *, 0x12) << 6);

            if (var_s0 < temp_s2) {
                var_s1 = var_s0 + 0x16;

                do {
                    temp_a0 = M2C_FIELD(var_s1, s32 *, 0x26);
                    if ((temp_a0 != 0) && !(M2C_FIELD(var_s1, u16 *, 0) & 2)) {
                        CTR_CycleTex_Model(temp_a0, temp_s5);
                    }

                    var_s0 += 0x40;
                    var_s1 += 0x40;
                } while (var_s0 < temp_s2);
            }

            var_s3 -= 1;
            var_s4 += 4;

            if (var_s3 != 0) {
                goto loop_2;
            }
        }
    }
}