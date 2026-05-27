#include "../../common.h"

extern GameTracker *gGamepads;

typedef struct VehTurbo {
    Instance *instTurbo;
    Driver *driver;
} VehTurbo;

void VehTurbo_ProcessBucket(Thread *thread)
{
    VehTurbo *turbo;
    InstDrawPerPlayer *idppTurbo;
    InstDrawPerPlayer *idppDriver;
    InstDrawPerPlayer *idppThread;
    s32 i;

    while (thread != NULL) {
        turbo = thread->object;

        idppThread = (InstDrawPerPlayer *)thread->inst;
        idppTurbo = (InstDrawPerPlayer *)turbo->instTurbo;
        idppDriver = (InstDrawPerPlayer *)turbo->driver->instSelf;

        for (i = 0; i < (u8)gGamepads->numPlyrCurrGame; i++) {
            if ((idppThread->instFlags & 0x100) == 0) {
                idppTurbo->instFlags &= idppThread->instFlags | ~0x40;
                idppDriver->instFlags &= idppThread->instFlags | ~0x40;

                idppDriver->unkE4 = idppThread->unkE4;
                idppTurbo->unkE4 = idppThread->unkE4;

                idppDriver->unkE8 = idppThread->unkE8;
                idppTurbo->unkE8 = idppThread->unkE8;

                idppDriver->depthOffset[0] = idppThread->depthOffset[0];
                idppTurbo->depthOffset[0] = idppThread->depthOffset[0];

                idppDriver->depthOffset[1] = idppThread->depthOffset[1];
                idppTurbo->depthOffset[1] = idppThread->depthOffset[1];
            }

            idppDriver++;
            idppTurbo++;
            idppThread++;
        }

        thread = thread->siblingThread;
    }
}