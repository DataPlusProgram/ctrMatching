#include "../../common.h"

extern void JitPool_Clear(JitPool *pool);
extern s32 MEMPACK_AllocMem(s32 size, char *name);
extern M2C_UNK memset();

void JitPool_Init(JitPool *pool, s32 numItems, s32 itemSize, char *name)
{
    s32 bufferSize;

    memset(pool, 0, 0x28);

    bufferSize = numItems * itemSize;
    pool->numItems = numItems;
    pool->itemSize = itemSize;
    pool->bufferSize = bufferSize;
    pool->buffer = (void *)MEMPACK_AllocMem(bufferSize, name);

    JitPool_Clear(pool);
}
