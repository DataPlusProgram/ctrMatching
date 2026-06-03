typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

typedef s32 M2C_UNK;

#define M2C_ERROR(desc) (0)

M2C_UNK AnimateWaterVertex();                       /* extern */

void AnimateWater1P(u32 arg0, s32 arg2, u16 *arg3, s32 *arg4) {
    /* Flowgraph is not reducible, falling back to gotos-only mode. */
    *(s32 *)0x1F800000 = saved_reg_s0;
    *(s32 *)0x1F800004 = saved_reg_s1;
    *(s32 *)0x1F800008 = saved_reg_s2;
    *(s32 *)0x1F80000C = saved_reg_s3;
    *(s32 *)0x1F800010 = saved_reg_s4;
    *(s32 *)0x1F800014 = saved_reg_s5;
    *(s32 *)0x1F800018 = saved_reg_s6;
    *(s32 *)0x1F80001C = saved_reg_s7;
    *(s32 *)0x1F800028 = saved_reg_ra;
    M2C_ERROR(/* unknown instruction: mtc2 $t1, $8 */);
    if (0 >= 0) {
        goto block_2;
    }
block_1:
    AnimateWaterVertex();
block_2:
    if (M2C_ERROR(/* Read from unset register $a1 */) == 0) {
        goto block_5;
    }
    if (M2C_ERROR(/* Read from unset register $t6 */) != 0) {
        goto block_1;
    }
    if (0 >= 0) {
        goto block_1;
    }
block_5:
    return;
}