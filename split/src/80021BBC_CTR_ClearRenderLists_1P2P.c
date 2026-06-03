#include "../../common.h"

extern s32 ptrRenderedQuadblockDestination_forEachPlayer;

void CTR_ClearRenderLists_1P2P(GameTracker *gGT, s32 arg1)
{
    s32 *varV1;
    s32 tempV0;
    s32 varA2;

    varA2 = 0;

    if (arg1 > 0)
    {
        varV1 = &ptrRenderedQuadblockDestination_forEachPlayer;

loop:
        tempV0 = *varV1;
        gGT->levRenderLists[0].list0Count = 0;
        gGT->levRenderLists[0].list0Base = tempV0;

        tempV0 = *varV1;
        gGT->levRenderLists[0].list1Count = 0;
        gGT->levRenderLists[0].list1Base = tempV0;

        tempV0 = *varV1;
        gGT->levRenderLists[0].list2Count = 0;
        gGT->levRenderLists[0].list2Base = tempV0;

        tempV0 = *varV1;
        varA2 += 1;
        gGT->levRenderLists[0].list3Count = 0;
        gGT->levRenderLists[0].list3Base = tempV0;

        tempV0 = *varV1;
        varV1 += 1;
        gGT->levRenderLists[0].unk24 = 0;
        gGT->levRenderLists[0].unk28 = 0;
        gGT->levRenderLists[0].unk2C = 0;
        gGT->levRenderLists[0].list4Base = tempV0;

        gGT = (GameTracker *)((s32)gGT + 0x30);

        if (varA2 < arg1)
            goto loop;
    }
}
