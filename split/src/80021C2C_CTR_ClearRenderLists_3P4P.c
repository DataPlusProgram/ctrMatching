#include "../../common.h"

extern s32 ptrRenderedQuadblockDestination_again;

void CTR_ClearRenderLists_3P4P(void *arg0, s32 arg1)
{
    GameTracker *gGT;
    LevRenderList *levRenderList;
    s32 *varV1;
    s32 tempV0;
    s32 varA2;

    gGT = arg0;
    varA2 = 0;

    if (arg1 > 0) {
        varV1 = &ptrRenderedQuadblockDestination_again;
        levRenderList = &gGT->levRenderLists[0];

        do {
            levRenderList->list0Count = 0;

            tempV0 = *varV1;
            levRenderList->list0Base = tempV0;

            tempV0 = *varV1;
            levRenderList->list1Count = 0;
            levRenderList->list1Base = tempV0;

            tempV0 = *varV1;
            varA2 += 1;
            levRenderList->list2Count = 0;
            levRenderList->list2Base = tempV0;

            tempV0 = *varV1;
            varV1 += 1;
            levRenderList->list3Count = 0;
            levRenderList->list4Base = 0;
            levRenderList->list3Base = tempV0;

            levRenderList += 1;
        } while (varA2 < arg1);
    }
}
