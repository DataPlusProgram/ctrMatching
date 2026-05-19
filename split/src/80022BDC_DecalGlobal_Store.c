typedef signed char s8;
typedef unsigned short u16;
typedef int s32;
typedef unsigned int u32;

#define NULL 0

typedef struct {
    s32 count0;
    void *items0;
    s32 count1;
    void **items1;
} DecalGlobalHeader;

void DecalGlobal_Store(s32 arg0, DecalGlobalHeader *arg1) {
    void *varA2;
    void **varA1;
    void *tempA2;
    void *endA3;
    u32 tempV1;
    u16 tempV1_2;

    if (arg1 != NULL) {
        varA2 = arg1->items0;
        endA3 = (s8 *)varA2 + (arg1->count0 << 5);

        if (varA2 < endA3) {
            do {
                tempV1 = *(u32 *)((s8 *)varA2 + 0x10);
                if (tempV1 < 0x88U) {
                    *(void **)(arg0 + (tempV1 << 2) + 0x1EEC) = varA2;
                }

                varA2 = (s8 *)varA2 + 0x20;
            } while (varA2 < endA3);
        }

        varA1 = arg1->items1;
        endA3 = varA1 + arg1->count1;

        if (varA1 < endA3) {
            do {
                tempA2 = *varA1;
                tempV1_2 = *(u16 *)((s8 *)tempA2 + 0x10);

                if (tempV1_2 < 0x11U) {
                    *(void **)(arg0 + (((s32)(tempV1_2 << 0x10)) >> 0xE) + 0x2114) = tempA2;
                }

                varA1++;
            } while (varA1 < endA3);
        }
    }
}