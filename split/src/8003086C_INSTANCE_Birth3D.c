#include "../../common.h"

extern void INSTANCE_Birth();
extern void *D_8008D2AC;

Instance *INSTANCE_Birth3D(s32 modelId, M2C_UNK arg1, M2C_UNK arg2)
{
    Instance *instance;

    instance = (Instance *)JitPool_Add((JitPool *)((u8 *)D_8008D2AC + 0x18F8));
    if (instance != 0) {
        INSTANCE_Birth(instance, modelId, arg1, arg2, 0xF);
    }

    return instance;
}
