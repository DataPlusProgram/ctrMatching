#include "../../common.h"



M2C_UNK SquareRoot0_stub(s32 arg0);

void MATH_VectorLength(s32 *arg0) {
    register s32 tempT4 asm("$12");
    register s32 tempT5 asm("$13");
    register s32 tempA0 asm("$4");

    tempT4 = arg0[0];
    tempT5 = *(s16 *)(arg0 + 1);
    gte_ldR11R12_mem(tempT4);
    gte_ldR13R21_mem(tempT5);

    tempT4 = arg0[0];
    tempT5 = *(s16 *)(arg0 + 1);
    gte_ldVXY0(tempT4);
    gte_ldVZ0(tempT5);

    gte_lcv0_exact();
    gte_mfc2_mac1(tempA0);
    SquareRoot0_stub(tempA0);
}