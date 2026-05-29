#include "../../common.h"

void LibraryOfModels_Store(GameTracker *gT, s32 modelCountOrMinusOne, void **modelList);
extern void *AkuAkuHintState;
extern GameTracker *gT;
extern void *podiumModel_firstPlace;

void LOAD_GlobalModelPtrs_MPK(void) {
    s32 count;
    s32 minusOne;
    void **modelPtr;
    void *model;
    s32 modelIndex;

    count = 0;
    minusOne = -1;
    modelPtr = &podiumModel_firstPlace;

    do {
        model = *modelPtr;
        if (model != NULL) {
            modelIndex = M2C_FIELD(model, s16 *, 0x10);
            if (modelIndex != minusOne) {
                modelIndex = modelIndex << 2;
                M2C_FIELD((s8 *)gT + modelIndex, void **, 0x2160) = model;
            }
        }

        count++;
        modelPtr++;
    } while (count < 3);

    if (AkuAkuHintState != 0) {
        LibraryOfModels_Store(gT, -1, (void **)AkuAkuHintState);
    }
}
