typedef signed char s8;
typedef unsigned char u8;
typedef int s32;

#define NULL 0

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} M2cDecalGlobalFindInMPKArg1;

u8 *DecalGlobal_FindInMPK(u8 *arg0, M2cDecalGlobalFindInMPKArg1 *arg1) {
    u8 *varA0;
    void *varA2;
    s32 tempA3;

    varA0 = arg0;
    varA2 = varA0 + 0xC;

    if (*varA0 != 0) {
        tempA3 = arg1->unk0;

loop_2:
        if (
            (*(s32 *)varA0 == tempA3) &&
            (*(s32 *)((s8 *)varA2 - 8) == arg1->unk4) &&
            (*(s32 *)((s8 *)varA2 - 4) == arg1->unk8) &&
            (*(s32 *)((s8 *)varA2 + 0) == arg1->unkC)
        ) {
            return varA0;
        }

        varA0 += 0x20;
        varA2 = (s8 *)varA2 + 0x20;

        if (*varA0 != 0) {
            goto loop_2;
        }
    }

    return NULL;
}