#include "../../common.h"

typedef struct {
    char pad0[0xC];
    s32 unkC;
} M2cLOADCallbackPodiumsArg0;

extern s32 currSlot;
s32 levBigLodIndex[2];

void LOAD_Callback_Podiums(M2cLOADCallbackPodiumsArg0 *arg0)
{
    levBigLodIndex[1] = 0;
    currSlot = arg0->unkC;
}