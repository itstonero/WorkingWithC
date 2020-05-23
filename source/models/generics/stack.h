#ifndef GENERIC_STACK
#define GENERIC_STACK
#include <stdlib.h>

typedef struct stack
{
    void * value;
    struct stack * next;
    struct stack * previous;
}StackItem;

typedef struct stackHead
{
    StackItem *head;
    StackItem *end;
    StackItem *popped;

    int (*push)(struct stackHead *, void *);
    void * (*pop)(struct stackHead* );
    int (*attach)(struct stackHead*, struct stackHead*);
    void * (*peek)(struct stackHead* );
    void (*clear)(struct stackHead* );
    int size;
}Stack;

Stack * new_Stack();

#endif