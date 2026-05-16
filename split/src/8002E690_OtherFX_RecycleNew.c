#include "../../common.h"

M2C_UNK OtherFX_Modify();
s32 OtherFX_Play_LowLevel();
M2C_UNK OtherFX_Stop1();

void OtherFX_RecycleNew(s32 *arg0, s32 arg1, M2C_UNK arg2) {
    s32 temp_a0;
    s32 temp_a0_2;

    temp_a0 = *arg0;
    if (temp_a0 != 0) {
        if ((temp_a0 & 0xFFFF) != arg1) {
            OtherFX_Stop1(temp_a0);
            *arg0 = 0;
        }
    }
    if (arg1 != -1) {
        temp_a0_2 = *arg0;
        if (temp_a0_2 == 0) {
            *arg0 = OtherFX_Play_LowLevel(arg1 & 0xFFFF, 0, arg2);
            return;
        }
        OtherFX_Modify(temp_a0_2, arg2);
    }
}