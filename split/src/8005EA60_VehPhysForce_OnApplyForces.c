#include "../../common.h"

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

void VehPhysForce_ConvertSpeedToVec(Driver*, void*);
void VehPhysForce_OnGravity(Driver*, void*);


void VehPhysForce_OnApplyForces(void *thread, Driver *driver)
{



  if (driver->speed >= 0x6401)
  {
    driver->speed = 0x6400;
  }

  gte_SetColorMatrix(&driver->matrixFacingDir);
  gte_ldv0_xy(0x190000);
  gte_ldv0_z(0);
  gte_lcv0();
  gte_stmac1(&driver->originToCenter.x);
  gte_stmac2(&driver->originToCenter.y);
  gte_stmac3(&driver->originToCenter.z);

  VehPhysForce_ConvertSpeedToVec(driver, &driver->velocity);

  if (driver->underDriver != 0)
  {
    if (M2C_FIELD(driver->underDriver, u8 *, 0x38) == 0xE)
    {
      if (driver->posCurr.y >= -0xFFF)
      {
        if (driver->velocity.y < (-0x1000 - driver->posCurr.y))
        {
          driver->velocity.y = -0x1000 - driver->posCurr.y;
        }
      }
    }
  }

  VehPhysForce_OnGravity(driver, &driver->velocity);

  *((s32 *) (((s8 *) driver) + 0x0A4)) = 0x10000000;
  driver->currBlockTouching = 0;
  driver->normalVecUp.z = 0;
  driver->axisAngle1NormalVec.z = 0;
  *((s32 *) (((s8 *) driver) + 0x0360)) = 0x10000000;
  driver->unkAA = 0;

  driver->velocity.x += driver->accel.x;
  driver->velocity.y += driver->accel.y;
  driver->velocity.z += driver->accel.z;
}
