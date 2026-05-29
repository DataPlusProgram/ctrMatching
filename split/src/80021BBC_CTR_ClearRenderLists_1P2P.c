#include "../../common.h"

extern s32 ptrRenderedQuadblockDestination_forEachPlayer;

void CTR_ClearRenderLists_1P2P(void *arg0, s32 arg1)
{
    s32 *varV1;
    s32 tempV0;
    s32 varA2;
    void *varA0;

    varA0 = arg0;
    varA2 = 0;

    if (arg1 > 0) {
        varV1 = &ptrRenderedQuadblockDestination_forEachPlayer;

        do {
            M2C_FIELD(varA0, s32 *, 0x180C) = 0;

            tempV0 = *varV1;
            M2C_FIELD(varA0, s32 *, 0x1808) = tempV0;

            tempV0 = *varV1;
            M2C_FIELD(varA0, s32 *, 0x1814) = 0;
            M2C_FIELD(varA0, s32 *, 0x1810) = tempV0;

            tempV0 = *varV1;
            M2C_FIELD(varA0, s32 *, 0x181C) = 0;
            M2C_FIELD(varA0, s32 *, 0x1818) = tempV0;

            tempV0 = *varV1;
            varA2 += 1;
            M2C_FIELD(varA0, s32 *, 0x1824) = 0;
            M2C_FIELD(varA0, s32 *, 0x1820) = tempV0;

            tempV0 = *varV1;
            varV1 += 1;
            M2C_FIELD(varA0, s32 *, 0x182C) = 0;
            M2C_FIELD(varA0, s32 *, 0x1830) = 0;
            M2C_FIELD(varA0, s32 *, 0x1834) = 0;
            M2C_FIELD(varA0, s32 *, 0x1828) = tempV0;

            varA0 = (s8 *)varA0 + 0x30;
        } while (varA2 < arg1);
    }
}
