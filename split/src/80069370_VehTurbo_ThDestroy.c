typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK INSTANCE_Death();                /* extern */

void VehTurbo_ThDestroy(void *arg0) {
    void *temp_a0;
    void *temp_a1;

    temp_a1 = M2C_FIELD(arg0, void **, 0x30);
    temp_a0 = M2C_FIELD(temp_a1, void **, 4);
    M2C_FIELD(temp_a0, s32 *, 0x2C8) = (s32) (M2C_FIELD(temp_a0, s32 *, 0x2C8) & ~0x200);
    INSTANCE_Death(M2C_FIELD(temp_a1, s32 *, 0), temp_a1);
    INSTANCE_Death(M2C_FIELD(arg0, s32 *, 0x34));
}