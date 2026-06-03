#include "../../common.h"

s32 LOAD_IsOpen_RacingOrBattle(void);
void func_800ABEFC(Driver *driver, s32 arg1);
void OtherFX_Stop1(void *sound);

extern u8 D_800B0F1C;
extern void VehPhysProc_Driving_Audio(Thread *thread, Driver *driver);
extern void VehStuckProc_PlantEaten_Animate(Thread *thread, Driver *driver);

void VehStuckProc_PlantEaten_Init(Thread *thread, Driver *driver)
{
    Instance *inst;
    Thread *thCloud;
    void *tempAudio;

    inst = thread->inst;

    driver->kartState = 5;
    driver->actionsFlagSet &= 0xFFF7FFBF;
    driver->kartStates.raw[0] = 0;
    driver->turboMeterRoomLeft = 0;
    driver->reserves = 0;
    driver->turboOutsideTimer = 0;

    thCloud = driver->thCloud;
    if (thCloud != 0)
    {
        ((RainCloud *)thCloud->object)->timeMS = 0;
        thCloud->funcThTick = (void (*)(Thread *))&D_800B0F1C;
        driver->thCloud = 0;
    }

    if (LOAD_IsOpen_RacingOrBattle() != 0)
    {
        if ((gT->gameMode1 & 0x100000) == 0)
        {
            func_800ABEFC(driver, -2);
        }
    }

    thread->flags |= 0x1000;
    inst->flags |= 0x80;

    OtherFX_Stop1(driver->driverAudioPtrs[1]);

    tempAudio = driver->driverAudioPtrs[2];
    driver->driverAudioPtrs[1] = 0;
    OtherFX_Stop1(tempAudio);

    tempAudio = driver->driverAudioPtrs[0];
    driver->driverAudioPtrs[2] = 0;
    OtherFX_Stop1(tempAudio);
	driver->driverAudioPtrs[0] = 0;
    driver->funcPtrs[1] = &VehStuckProc_PlantEaten_Update;
    driver->funcPtrs[2] = &VehStuckProc_PlantEaten_PhysLinear;
    driver->funcPtrs[3] = &VehPhysProc_Driving_Audio;
    driver->funcPtrs[0] = 0;
    driver->funcPtrs[4] = 0;
    driver->funcPtrs[5] = 0;
    driver->funcPtrs[6] = 0;
    driver->funcPtrs[7] = 0;
    driver->funcPtrs[8] = 0;
    driver->funcPtrs[9] = 0;
    driver->funcPtrs[10] = 0;
	driver->funcPtrs[11] = &VehStuckProc_PlantEaten_Animate;
    driver->funcPtrs[12] = 0;
}
