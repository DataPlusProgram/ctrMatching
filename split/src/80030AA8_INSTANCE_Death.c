typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK JitPool_Remove();                   /* extern */
extern s32 D_8008D2AC;

void INSTANCE_Death(s32 arg0) {
    JitPool_Remove(D_8008D2AC + 0x18F8, arg0);
}