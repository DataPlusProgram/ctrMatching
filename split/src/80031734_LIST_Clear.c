#include "../../common.h"

void LIST_Clear(LinkedList *list)
{
    list->first = NULL;
    list->last = NULL;
    list->count = 0;
}
