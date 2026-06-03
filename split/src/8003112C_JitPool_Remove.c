#include "../../common.h"

extern void LIST_AddFront(LinkedList *list, LinkedListNode *item);
extern LinkedListNode *LIST_RemoveMember(LinkedList *list, LinkedListNode *item);

void JitPool_Remove(JitPool *pool, LinkedListNode *item)
{
    LIST_RemoveMember(&pool->usedList, item);
    LIST_AddFront(&pool->freeList, item);
}
