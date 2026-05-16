#include "../../common.h"


void VehPhysForce_ConvertSpeedToVec(Driver*, void*);
void VehPhysForce_OnGravity(Driver*, void*);



void func_8005EA60(void* thread, Driver* driver)
{
    if (driver->speed >= 0x6401)
    {
        driver->speed = 0x6400;
    }

    gte_SetColorMatrix(driver->unk330);
    gte_ldv0_xy(0x190000);
    gte_ldv0_z(0);
    gte_lcv0();
    gte_stmac1(&driver->originToCenter.x);
    gte_stmac2(&driver->originToCenter.y);
    gte_stmac3(&driver->originToCenter.z);

    VehPhysForce_ConvertSpeedToVec(driver, &driver->velocity);

    if (driver->underDriver != 0)
    {
        if (driver->underDriver->terrain_type == 0xE)
        {
            if (driver->posCurrY >= -0xFFF)
            {
                if (driver->velocity.y < -0x1000 - driver->posCurrY)
                {
                    driver->velocity.y = -0x1000 - driver->posCurrY;
                }
            }
        }
    }

    VehPhysForce_OnGravity(driver, &driver->velocity);

    driver->unkA0 = 0;
    driver->unkA4 = 0x10000000;
    driver->unkA8 = 0;
    driver->unk360 = 0x10000000;
    driver->unk364 = 0;
    driver->unkAA = 0;
    driver->velocity.x += driver->accel.x;
    driver->velocity.y += driver->accel.y;
    driver->velocity.z += driver->accel.z;
}
