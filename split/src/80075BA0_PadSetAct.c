typedef signed char s8;
typedef int s32;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

extern void *(*D_8008C780)();

void PadSetAct(s32 arg0, s32 arg1, s8 arg2) {
    void *temp_v0;

    temp_v0 = D_8008C780();
    M2C_FIELD(temp_v0, s32 *, 0x28) = arg1;
    M2C_FIELD(temp_v0, s8 *, 0x34) = arg2;
}