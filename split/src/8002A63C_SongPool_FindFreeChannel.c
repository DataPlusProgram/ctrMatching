typedef unsigned char u8;
typedef int s32;

#define NULL 0

extern u8 songSeq;

u8 *SongPool_FindFreeChannel(void) {
    s32 varA0;
    u8 *varV1;
    u8 *ret;

    varA0 = 0;
    varV1 = &songSeq;

loop:
    if ((*varV1 & 1) != 0) {
        goto usedChannel;
    }

    varA0 += 1;
    ret = varV1;
    return ret;

usedChannel:
    varA0 += 1;
    if (varA0 < 0x18) {
        varV1 += 0x1C;
        goto loop;
    }

    ret = NULL;
    return ret;
}