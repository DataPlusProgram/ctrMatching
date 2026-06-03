#include "../../common.h"

extern void LIST_AddBack(LinkedList *list, LinkedListNode *item);

void LIST_Init(LinkedList *list, LinkedListNode *firstItem, s32 itemSize, s32 count)
{
    s32 i;
    LinkedListNode *item;

    item = firstItem;
    i = count - 1;
    if (count != 0) {
        do {
            LIST_AddBack(list, item);
            i--;
            item = (LinkedListNode *)((u8 *)item + itemSize);
        } while (i != -1);
    }
}
