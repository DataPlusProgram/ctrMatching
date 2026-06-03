#include "../../common.h"

LinkedListNode *LIST_RemoveFront(LinkedList *list)
{
    LinkedListNode *nextItemPrev;
    LinkedListNode *nextItem;
    LinkedListNode *item;

    item = list->first;
    if (item != NULL) {
        nextItemPrev = item->prev;
        if (nextItemPrev != NULL) {
            nextItemPrev->next = item->next;
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
        item->next = NULL;
        item->prev = NULL;
    }

    return item;
}
