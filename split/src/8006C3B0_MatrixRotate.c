typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))
#define M2C_ERROR(desc) (0)

M2C_UNK SetRotMatrixRegs();                         /* extern */
M2C_UNK TRIG_Unknown_8006C49C();                    /* extern */

void MatrixRotate(void *arg1) {
    *(s32 *)0x1F800000 = saved_reg_s0;
    *(s32 *)0x1F800004 = saved_reg_s1;
    *(s32 *)0x1F800008 = saved_reg_s2;
    *(s32 *)0x1F80000C = saved_reg_s3;
    *(s32 *)0x1F800010 = saved_reg_s4;
    *(s32 *)0x1F80002C = saved_reg_ra;
    SetRotMatrixRegs();
    TRIG_Unknown_8006C49C();
    *M2C_ERROR(/* Read from unset register $a0 */) = M2C_ERROR(/* Read from unset register $t3 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $a0 */), s32 *, 4) = (s32) M2C_ERROR(/* Read from unset register $t4 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $a0 */), s32 *, 8) = (s32) M2C_ERROR(/* Read from unset register $t5 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $a0 */), s32 *, 0xC) = (s32) M2C_ERROR(/* Read from unset register $t6 */);
    M2C_FIELD(M2C_ERROR(/* Read from unset register $a0 */), s32 *, 0x10) = (s32) M2C_ERROR(/* Read from unset register $t7 */);
}