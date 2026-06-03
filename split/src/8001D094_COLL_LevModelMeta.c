#include "../../common.h"

extern s8 D_80081088[];

LevModelMetaView *COLL_LevModelMeta(u32 arg0)
{
    s32 offset;

    if (arg0 >= 0xE2)
    {
        return (LevModelMetaView *)D_80081088;
    }

    offset = arg0 << 1;
    offset += arg0;
    offset <<= 2;

    return (LevModelMetaView *)(D_80081088 + offset);
}
