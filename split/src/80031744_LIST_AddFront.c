#include "../../common.h"

void LIST_AddFront(LinkedList *list, LinkedListNode *item)
{
    LinkedListNode *firstItem;

    if (item != NULL) {
        item->prev = NULL;
        firstItem = list->first;
        item->next = firstItem;

        if (firstItem != NULL) {
            list->first->prev = item;
        } else {
            list->last = item;
        }

        list->first = item;
        list->count++;
    }
}