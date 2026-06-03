#include "../../common.h"

void MainInit_JitPoolsReset(void *base)
{
    JitPool_Clear((JitPool *)((u8 *)base + 0x18D0));
    JitPool_Clear((JitPool *)((u8 *)base + 0x18F8));
    JitPool_Clear((JitPool *)((u8 *)base + 0x1920));
    JitPool_Clear((JitPool *)((u8 *)base + 0x1948));
    JitPool_Clear((JitPool *)((u8 *)base + 0x1970));
    JitPool_Clear((JitPool *)((u8 *)base + 0x1998));
    JitPool_Clear((JitPool *)((u8 *)base + 0x19C0));
    JitPool_Clear((JitPool *)((u8 *)base + 0x19E8));
}
