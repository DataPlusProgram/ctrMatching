#include "../../common.h"

M2C_UNK DMACallback();

void _SpuDataCallback(s32 arg0) {
    DMACallback(4, arg0);
}