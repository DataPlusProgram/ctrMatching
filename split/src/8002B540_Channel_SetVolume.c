#include "../../common.h"

typedef struct
{
    char pad[0xC];
    u16 volL;
    u16 volR;
} M2cChannelSetVolumeArg0;

u8 howl_songOffsets;
extern u8 volumeLR[];

void Channel_SetVolume(M2cChannelSetVolumeArg0 *arg0, s32 arg1, s32 arg2)
{
    s32 var_a1;

    var_a1 = arg1;
    if (var_a1 >= 0x4000U)
    {
        var_a1 = 0x3FFF;
    }

    if (howl_songOffsets == 1)
    {
        arg0->volL = (u32)(var_a1 * volumeLR[0xFF - arg2]) >> 8;
        arg0->volR = (u32)(var_a1 * volumeLR[arg2]) >> 8;
        return;
    }

    arg0->volL = var_a1;
    arg0->volR = var_a1;
}