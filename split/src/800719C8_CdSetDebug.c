#include "../../common.h"

extern s32 D_8008C424;

s32 CdSetDebug(s32 arg0) {
    s32 temp_v0;

    temp_v0 = D_8008C424;
    D_8008C424 = arg0;
    return temp_v0;
}