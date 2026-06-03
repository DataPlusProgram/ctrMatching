#include "../../common.h"


typedef struct VehTurbo {
    Instance *instTurbo;
    Driver *driver;
} VehTurbo;

typedef struct TurboDrawFields {
    char padB8[0xb8];
    u32 instFlags;
    char padBC[0x20];
    u16 depthOffset[2];
    char padE0[4];
    u32 unkE4;
    u32 unkE8;
} TurboDrawFields;

void VehTurbo_ProcessBucket(Thread *thread)
{
    VehTurbo *turbo;
    TurboDrawFields *idppTurbo;
    TurboDrawFields *idppDriver;
    TurboDrawFields *idppThread;
    s32 i;
    u32 temp;
    u16 temp16;

    if (thread == NULL)
        return;

    do {
        turbo = thread->object;

        idppTurbo = (TurboDrawFields *)turbo->instTurbo;
        idppDriver = (TurboDrawFields *)turbo->driver->instSelf;
        idppThread = (TurboDrawFields *)thread->inst;

        for (i = 0; i < (u8)gT->numPlyrCurrGame; i++) {
            if ((idppDriver->instFlags & 0x100) == 0) {
                idppTurbo->instFlags &= idppDriver->instFlags | ~0x40;
                idppThread->instFlags &= idppDriver->instFlags | ~0x40;

                temp = idppDriver->unkE4;
                idppThread->unkE4 = temp;
                idppTurbo->unkE4 = temp;

                temp = idppDriver->unkE8;
                idppThread->unkE8 = temp;
                idppTurbo->unkE8 = temp;

                temp16 = idppDriver->depthOffset[0];
                idppThread->depthOffset[0] = temp16;
                idppTurbo->depthOffset[0] = temp16;

                temp16 = idppDriver->depthOffset[1];
                idppThread->depthOffset[1] = temp16;
                idppTurbo->depthOffset[1] = temp16;
            }

            idppThread = (TurboDrawFields *)((char *)idppThread + 0x88);
            idppTurbo = (TurboDrawFields *)((char *)idppTurbo + 0x88);
            idppDriver = (TurboDrawFields *)((char *)idppDriver + 0x88);
        }

        thread = thread->siblingThread;
    } while (thread != NULL);
}
