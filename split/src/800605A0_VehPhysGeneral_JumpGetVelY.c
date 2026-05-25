#include "../../common.h"

s32 VehPhysGeneral_JumpGetVelY(struct Vec16 *normalVec, Vec3 *speedXYZ) {
    s32 tempA2;
    s32 varV0;
    s32 varV1;

    tempA2 = normalVec->y;
    varV0 = tempA2;

    if (tempA2 < 0) {
        varV0 = -varV0;
    }

    varV1 = 0;

    if (varV0 >= 0x15) {
        varV1 = ((speedXYZ->x * normalVec->x) + (speedXYZ->z * normalVec->z)) / tempA2;
    }

    return varV1;
}
