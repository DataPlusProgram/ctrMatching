#include "../../common.h"

s32 VehPhysGeneral_JumpGetVelY(s16 *normalVec, Vec3 *movement)
{
    s32 velY = normalVec[1];
    s32 result;

    if (abs(velY) >= 21)
    {
        result = ((movement->x * normalVec[0]) + (movement->z * normalVec[2])) / velY;
    }
    else
    {
        result = 0;
    }

    return result;
}
