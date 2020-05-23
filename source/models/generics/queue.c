#include "queue.h"

int GQ_enqueue(Queue * queue, void * item)
{
    QueueItem * newItem = (QueueItem *)calloc(1, sizeof(QueueItem));
    if(newItem == NULL)
    {
        return 1;
    }

    newItem->priority = 0;
    newItem->value = item;
    newItem->next = queue->end;
    newItem->previous = queue->end->previous;
    queue->end->previous->next = newItem;
    queue->end->previous = newItem;

    queue->size += 1;
    return 0;
}

void * GQ_dequeue(Queue * queue)
{
    if(queue->size == 0)
    {
        return NULL;
    }
    if(queue->dequeued != NULL) free(queue->dequeued);
    queue->dequeued = queue->head->next;

    queue->head->next = queue->dequeued->next;
    queue->size -= 1;

    return queue->dequeued->value;
}

void * GQ_peek(Queue * queue)
{
    if(queue->size == 0)
    {
        return NULL;
    }

    return queue->head->next->value;
}

int GQ_enqueue_P(Queue * queue, void * item, int priority)
{
    if(priority < 0)
    {
        return 1;
    }
    if(priority == 0)
    {
        return GQ_enqueue(queue, item);
    }

    QueueItem * newItem = (QueueItem *)calloc(1, sizeof(QueueItem));

    if(newItem == NULL)
    {
        return 99;
    }

    QueueItem * temp = queue->head;
    while(temp->next)
    {
        if(priority > temp->next->priority)
        {
            temp = temp->next;

            newItem->priority = priority;
            newItem->value = item;
            newItem->next = temp;
            newItem->previous = temp->previous;

            temp->previous->next = newItem;
            temp->previous = newItem;
            
            queue->size += 1;
            return 0;        
        }

        temp = temp->next;
    }

    free(newItem);
    return 1;        

}

void GQ_clear(Queue * queue)
{
    QueueItem *temp = queue->end;
    while(temp->previous != NULL)
    {
        QueueItem * to_be_freed = temp;
        temp = temp->previous;

        if(to_be_freed->value != NULL)
        {
            free(to_be_freed->value);
        }
        
        free(to_be_freed);
    }

    free(temp);
    free(queue);
    return;
}

int GQ_attach(Queue * destination, Queue * source)
{
    QueueItem * temp = source->head->next;
    while(temp->next != NULL)
    {
        GQ_enqueue_P(destination, temp->value, temp->priority);
        temp = temp->next;
    }
}

Queue * new_Queue()
{
    Queue * queue = (Queue *)calloc(1, sizeof(Queue));
    queue->head = (QueueItem *)calloc(1, sizeof(QueueItem));
    queue->end = (QueueItem *)calloc(1, sizeof(QueueItem));
    queue->head->next = queue->end;
    queue->end->previous = queue->head;
    queue->end->next = NULL;
    queue->head->previous = NULL;
    queue->dequeued = NULL;

    queue->head->priority = -1;
    queue->end->priority = -1;

    queue->attach = GQ_attach;
    queue->clear = GQ_clear;
    queue->dequeue = GQ_dequeue;
    queue->enqueue = GQ_enqueue;
    queue->enqueue_P = GQ_enqueue_P;
    queue->peek = GQ_peek;

    queue->size = 0;
    return queue;
}
