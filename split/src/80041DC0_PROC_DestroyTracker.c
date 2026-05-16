typedef signed char s8;
typedef int s32;

typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK PROC_DestroyInstance();                     /* extern */
extern void *D_8008D2AC;

void PROC_DestroyTracker(void) {
    s32 temp_v0;

    temp_v0 = M2C_FIELD(D_8008D2AC, s32 *, 0x1EC0);
    if (temp_v0 > 0) {
        M2C_FIELD(D_8008D2AC, s32 *, 0x1EC0) = (s32) (temp_v0 - 1);
    }
    PROC_DestroyInstance();
}