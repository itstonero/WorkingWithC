#ifndef GENERIC_QUEUE
#define GENERIC_QUEUE
#include <stdlib.h>

typedef struct queue
{
    void * value;
    int priority;
    struct queue * next;
    struct queue * previous;
}QueueItem;




typedef struct queueHead
{
    QueueItem *head;
    QueueItem *end;
    QueueItem *dequeued;
    
    int (*attach)(struct queueHead*, struct queueHead *);
    int (*enqueue)(struct queueHead *, void *);
    void * (*dequeue)(struct queueHead *);
    void * (*peek)(struct queueHead *);
    void (*clear)(struct queueHead *);
    int (*enqueue_P)(struct queueHead *, void *, int);
    int size;
}Queue;

Queue * new_Queue();

#endif