#include "../../common.h"

int VehPhysGeneral_JumpGetVelY(s16 *param_1, s32 *param_2)
{
    s32 velY;
    s32 absVelY;
    s32 result;

    velY = param_1[1];
    absVelY = velY;

    if (absVelY < 0)
    {
        absVelY = -absVelY;
    }

    result = 0;

    if (absVelY >= 0x15)
    {
        result = ((param_2[0] * param_1[0]) + (param_2[2] * param_1[2])) / velY;
    }

    return result;
}