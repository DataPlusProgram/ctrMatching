typedef signed char s8;
typedef int s32;
typedef unsigned int u32;

extern s32 D_8009EC24;

void init_ring_status(s32 arg0, u32 arg1) {
    s32 tempV0;
    u32 varA2;

    varA2 = 0;
    if (arg1 != 0) {
        do {
            tempV0 = varA2 + arg0;
            varA2 += 1;
            *(s32 *)((s8 *)D_8009EC24 + (tempV0 << 5)) = 0;
        } while (varA2 < arg1);
    }
}