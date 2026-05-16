#include "../../common.h"

extern void *D_8008D2AC;

s32 LOAD_IsOpen_AdvHub(void) {
    return M2C_FIELD(D_8008D2AC, u8 *, 0x2541) == 2;
}