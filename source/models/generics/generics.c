#include "generics.h"

int deep_copy_list(List * _dest, List * _src)
{
    ListItem * temp = _src->head->next;
    while(temp->next != NULL)
    {
        void * value;
        _dest->add(_dest, value);
        temp = temp->next;
    }

    return 0;
}

int deep_copy_stack(Stack * _dest, Stack * _src)
{
    StackItem * temp = _src->end->previous;
    while(temp->previous != NULL)
    {
        void * value;
        _dest->push(_dest, value);
        temp = temp->previous;
    }
    return 0;
}

int deep_copy_queue(Queue * _dest, Queue * _src)
{
    QueueItem * temp = _src->head->next;
    while(temp->next != NULL)
    {
        void * value;
        _dest->enqueue(_dest, value);
        temp = temp->next;
    }
    return 0;
}