#include "../../common.h"

void *PROC_BirthWithObject();
extern s32 gGamepads;

s32 INSTANCE_BirthWithThread(s32 arg0, M2C_UNK arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 tempA0;
    s32 tempV0;
    s32 tempV1;
    s32 varV0;
    s32 ret;
    void *tempObj;

    tempA0 = M2C_FIELD(gGamepads + (arg0 * 4), s32 *, 0x2160);
    tempV1 = arg5;

    if (tempA0 != 0) {
        tempV0 = tempV1 & 3;
        if (tempV0 != 0) {
            tempV0 -= 4;
            tempV0 = tempV1 - tempV0;
            varV0 = tempV0 << 0x10;
        } else {
            varV0 = tempV1 << 0x10;
        }

        tempObj = PROC_BirthWithObject((arg2 | varV0) | arg3, arg4, arg1, arg6);
        M2C_FIELD(tempObj, s16 *, 0x44) = arg0;

        ret = INSTANCE_Birth3D(tempA0, arg1, tempObj);
        M2C_FIELD(tempObj, s32 *, 0x34) = ret;
    } else {
        ret = 0;
    }

    return ret;
}
