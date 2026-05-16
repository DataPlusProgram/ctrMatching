typedef signed char s8;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LIST_AddFront();                 /* extern */
M2C_UNK PROC_DestroyObject();               /* extern */
extern s32 D_8008D2AC;

void PROC_DestroySelf(void *arg0) {
    M2C_UNK (*temp_v0)();

    if (arg0 != NULL) {
        temp_v0 = M2C_FIELD(arg0, M2C_UNK (**)(), 0x24);
        if (temp_v0 != NULL) {
            temp_v0();
        }
        M2C_FIELD(arg0, s32 *, 0x20) = (s32) (M2C_FIELD(arg0, s32 *, 0x20) + 1);
        PROC_DestroyObject(M2C_FIELD(arg0, s32 *, 0x30), M2C_FIELD(arg0, s32 *, 0x1C));
        LIST_AddFront(D_8008D2AC + 0x18D0, arg0);
    }
}