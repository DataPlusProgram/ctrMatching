#include "../../common.h"

extern void LIST_AddFront(LinkedList *list, LinkedListNode *item);
extern void LIST_Clear(LinkedList *list);

void JitPool_Clear(JitPool *pool)
{
    LinkedListNode *item;
    u32 i;

    item = pool->buffer;
    i = 0;

    LIST_Clear(&pool->freeList);
    LIST_Clear(&pool->usedList);

    if (pool->numItems != 0) {
        do {
            LIST_AddFront(&pool->freeList, item);
            i++;
            item = (LinkedListNode *)((u8 *)item + (((u32)pool->itemSize >> 2) << 2));
        } while (i < pool->numItems);
    }
}