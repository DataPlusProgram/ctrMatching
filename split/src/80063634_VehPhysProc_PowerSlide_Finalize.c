#include "../../common.h"



void VehPhysProc_PowerSlide_Finalize(Driver *driver)
{
    driver->previousFrameMultDrift = driver->multDrift;
    driver->timeUntilDriftSpinout = driver->unk46B << 5;

}