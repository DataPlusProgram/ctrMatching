#include "../../common.h"

extern s32 D_800845A0[];

void VehPhysForce_ConvertSpeedToVec(Driver *driver, Vec3 *vec)
{
  s32 temp_a3;
  s32 var_a2;
  s32 temp_a0;
  s32 temp_v1;
  s32 var_v1;
  temp_a3 = driver->axisRotationY;
  temp_v1 = D_800845A0[temp_a3 & 0x3FF];
  if (temp_a3 & 0x400)
  {
    var_a2 = (s16) temp_v1;
    var_v1 = temp_v1 >> 0x10;
    if (!(temp_a3 & 0x800))
    {
      var_a2 = -var_a2;
    }
  }
  else
  {
    var_a2 = temp_v1 >> 0x10;
    temp_v1 = temp_v1 << 0x10;
    var_v1 = temp_v1 >> 0x10;
    if (temp_a3 & 0x800)
    {
      var_a2 = -var_a2;
      var_v1 = -var_v1;
    }
  }
  vec->y = (driver->speed * var_v1) >> 0xC;
  temp_a3 = driver->axisRotationX;
  temp_v1 = D_800845A0[temp_a3 & 0x3FF];
  temp_a0 = (driver->speed * var_a2) >> 0xC;
  if (temp_a3 & 0x400)
  {
    var_a2 = (s16) temp_v1;
    var_v1 = temp_v1 >> 0x10;
    if (!(temp_a3 & 0x800))
    {
      var_a2 = -var_a2;
    }
  }
  else
  {
    var_a2 = temp_v1 >> 0x10;
    temp_v1 = temp_v1 << 0x10;
    var_v1 = temp_v1 >> 0x10;
    if (temp_a3 & 0x800)
    {
      var_a2 = -var_a2;
      var_v1 = -var_v1;
    }
  }
  vec->x = (temp_a0 * var_v1) >> 0xC;
  vec->z = (temp_a0 * var_a2) >> 0xC;
}
