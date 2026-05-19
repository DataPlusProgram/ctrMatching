typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

#define NULL 0

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} M2cDecalGlobalFindInLEVArg1;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} DecalEntry;

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 count;
    DecalEntry **items;
} DecalLev;

typedef struct {
    s8 pad[0x3C];
    DecalLev *lev;
} DecalGlobal;

void *DecalGlobal_FindInLEV(DecalGlobal *arg0, M2cDecalGlobalFindInLEVArg1 *arg1) {
    DecalLev *tempV1;
    DecalEntry **varA2;
    DecalEntry **endA3;
    DecalEntry *tempA0;
    s32 tempT0;

    tempV1 = arg0->lev;
    if (tempV1 != NULL) {
        varA2 = tempV1->items;
        endA3 = varA2 + tempV1->count;

        if (varA2 < endA3) {
            tempT0 = arg1->unk0;
            do {
                tempA0 = *varA2;

                if (
                    (tempA0->unk0 == tempT0) &&
                    (tempA0->unk4 == arg1->unk4) &&
                    (tempA0->unk8 == arg1->unk8) &&
                    (tempA0->unkC == arg1->unkC)
                ) {
                    return tempA0;
                }

                varA2++;
            } while (varA2 < endA3);
        }
    }

    return NULL;
}