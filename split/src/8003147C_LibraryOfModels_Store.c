#include "../../common.h"

void LibraryOfModels_Store(GameTracker *gT, s32 modelCountOrMinusOne, void **modelList)
{
    s32 invalidModelId;
    void *model;
    s16 modelId;

    invalidModelId = -1;


    if (modelCountOrMinusOne != 0)
    {
        do
        {
            model = *modelList;

            if (model == NULL)
            {
                return;
            }

            modelId = M2C_FIELD(model, s16 *, 0x10);

            if (modelId != invalidModelId)
            {
                M2C_FIELD((s8 *)gT + (modelId << 2), void **, 0x2160) = model;
            }

            modelCountOrMinusOne--;
            modelList++;
        } while (modelCountOrMinusOne != 0);
    }
}
