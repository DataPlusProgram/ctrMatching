#include "../../common.h"

void SetRotMatrixRegs(void)
{
    register s32 inT3 asm("t3");
    register s32 inT4 asm("t4");
    register s32 inT5 asm("t5");
    register s32 inT6 asm("t6");
    register s32 inT7 asm("t7");

    gte_ldR11R12(inT3);
    gte_ldR13R21(inT4);
    gte_ldR22R23(inT5);
    gte_ldR31R32(inT6);
    gte_ldR33(inT7);
}