#include "../../common.h"

LinkedListNode *LIST_RemoveMember(LinkedList *list, LinkedListNode *item)
{
    LinkedListNode *nextItem;
    LinkedListNode *prevItem;

    if (item != NULL) {
        if (list->first != NULL) {
            prevItem = item->prev;
            if (prevItem != NULL) {
                prevItem->next = item->next;
            } else {
                list->first = item->next;
            }

            nextItem = item->next;
            if (nextItem != NULL) {
                nextItem->prev = item->prev;
            } else {
                list->last = item->prev;
            }

            list->count--;
        }

        item->next = NULL;
        item->prev = NULL;
    }

    return item;
}
