typedef int s32;

typedef s32 M2C_UNK;

M2C_UNK JitPool_Clear();                         /* extern */

void MainInit_JitPoolsReset(s32 arg0) {
    JitPool_Clear(arg0 + 0x18D0);
    JitPool_Clear(arg0 + 0x18F8);
    JitPool_Clear(arg0 + 0x1920);
    JitPool_Clear(arg0 + 0x1948);
    JitPool_Clear(arg0 + 0x1970);
    JitPool_Clear(arg0 + 0x1998);
    JitPool_Clear(arg0 + 0x19C0);
    JitPool_Clear(arg0 + 0x19E8);
}