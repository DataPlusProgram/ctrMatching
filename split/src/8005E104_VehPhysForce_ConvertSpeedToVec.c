#include "../../common.h"

extern s32 D_800845A0[];

void VehPhysForce_ConvertSpeedToVec(Driver *driver, Vec3 *vec)
{
    s32 rotY;
    s32 rotX;
    s32 packedSinCos;
    s32 sin;
    s32 cos;
    s32 horizontalSpeed;

    rotY = driver->axisRotationY;
    packedSinCos = D_800845A0[rotY & 0x3FF];

    if (rotY & 0x400)
    {
        sin = (s16)packedSinCos;
        cos = packedSinCos >> 0x10;

        if (!(rotY & 0x800))
        {
            sin = -sin;
        }
    }
    else
    {
        sin = packedSinCos >> 0x10;
        cos = (packedSinCos << 0x10) >> 0x10;

        if (rotY & 0x800)
        {
            sin = -sin;
            cos = -cos;
        }
    }

    vec->y = (driver->speed * cos) >> 0xC;

    rotX = driver->axisRotationX;
    horizontalSpeed = (driver->speed * sin) >> 0xC;

    packedSinCos = D_800845A0[rotX & 0x3FF];

    if (rotX & 0x400)
    {
        sin = (s16)packedSinCos;
        cos = packedSinCos >> 0x10;

        if (!(rotX & 0x800))
        {
            sin = -sin;
        }
    }
    else
    {
        sin = packedSinCos >> 0x10;
        cos = (packedSinCos << 0x10) >> 0x10;

        if (rotX & 0x800)
        {
            sin = -sin;
            cos = -cos;
        }
    }

    vec->x = (horizontalSpeed * cos) >> 0xC;
    vec->z = (horizontalSpeed * sin) >> 0xC;
}