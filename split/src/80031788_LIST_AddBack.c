#include "../../common.h"

void LIST_AddBack(LinkedList *list, LinkedListNode *item)
{
    LinkedListNode *lastItem;

    if (item != NULL) {
        item->next = NULL;
        lastItem = list->last;
        item->prev = lastItem;

        if (lastItem != NULL) {
            list->last->next = item;
        } else {
            list->first = item;
        }

        list->last = item;
        list->count++;
    }
}