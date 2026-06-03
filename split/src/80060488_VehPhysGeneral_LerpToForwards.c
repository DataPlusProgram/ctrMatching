
#include "../../common.h"

s32 VehPhysGeneral_LerpToForwards(Driver *driver, s32 targetForward, s32 inputSpeed, s32 currentForward)
{
  s32 wasNegative;
  s32 interpSpeed;
  s32 currentForwardLocal;
  s32 strengthArg;
  s32 lerpStrength;
  s32 steerValue;
  s32 tempSteer;
  driver->unk3CA = 0;
  interpSpeed = inputSpeed;
  currentForwardLocal = currentForward;
  wasNegative = 0;
  if ((currentForwardLocal < 0) || ((currentForwardLocal == 0) && (targetForward < 0)))
  {
    wasNegative = 1;
    targetForward = -targetForward;
    interpSpeed = -interpSpeed;
    currentForwardLocal = -currentForwardLocal;
  }
  lerpStrength = 0;
  if (driver->set0xF0OnWallRub != 0xF0)
  {
    if (currentForwardLocal < targetForward)
    {
      if (driver->constModelRotVelMax < targetForward)
      {
        tempSteer = driver->unk458;
        strengthArg = targetForward - currentForwardLocal;
        steerValue = tempSteer << 4;
        steerValue -= tempSteer;
      }
      else
      {
        steerValue = driver->unk458;
        strengthArg = targetForward - currentForwardLocal;
      }
      lerpStrength = -VehPhysGeneral_LerpQuarterStrength(steerValue, strengthArg);
    }
    else
      if (targetForward < currentForwardLocal)
    {
      if (targetForward < 0)
      {
        lerpStrength = VehPhysGeneral_LerpQuarterStrength((u8)driver->unk459, currentForwardLocal - targetForward);
      }
      else
      {
        lerpStrength = VehPhysGeneral_LerpQuarterStrength((u8)driver->angleMaxCounterSteer, currentForwardLocal - targetForward);
        driver->unk3CA = currentForwardLocal;
      }
    }
  }
  interpSpeed = VehCalc_InterpBySpeed(interpSpeed, (u8)driver->unk45A, lerpStrength);
  if (wasNegative)
  {
    return -interpSpeed;
  }
  return interpSpeed;
}
