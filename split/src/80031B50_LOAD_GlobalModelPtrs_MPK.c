typedef signed char s8;
typedef short s16;
typedef int s32;

#define NULL 0
typedef s32 M2C_UNK;

#define M2C_FIELD(expr, typePtr, offset) (*(typePtr)((s8 *)(expr) + (offset)))

M2C_UNK LibraryOfModels_Store(); /* extern */
extern s32 AkuAkuHintState;
extern s32 gGamepads;
extern void *podiumModel_firstPlace;

void LOAD_GlobalModelPtrs_MPK(void) {
    s32 count;
    s32 gamepads;
    s32 minusOne;
    void **modelPtr;
    void *model;
    s32 modelIndex;

    count = 0;
    minusOne = -1;
    modelPtr = &podiumModel_firstPlace;
    gamepads = gGamepads;

    do {
        model = *modelPtr;
        if (model != NULL) {
            modelIndex = M2C_FIELD(model, s16 *, 0x10);
            if (modelIndex != minusOne) {
                modelIndex = modelIndex << 2;
                M2C_FIELD(gamepads + modelIndex, void **, 0x2160) = model;
            }
        }

        count++;
        modelPtr++;
    } while (count < 3);

    if (AkuAkuHintState != 0) {
        LibraryOfModels_Store(gGamepads, -1, AkuAkuHintState);
    }
}