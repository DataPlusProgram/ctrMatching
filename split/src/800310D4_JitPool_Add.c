#include "../../common.h"

extern void LIST_AddFront(LinkedList *list, LinkedListNode *item);
extern LinkedListNode *LIST_RemoveMember(LinkedList *list, LinkedListNode *item);

LinkedListNode *JitPool_Add(JitPool *pool)
{
    LinkedListNode *item;

    item = pool->freeList.first;

    if (item != 0) {
        LIST_RemoveMember(&pool->freeList, item);
        LIST_AddFront(&pool->usedList, item);
        return item;
    }

    return 0;
}
