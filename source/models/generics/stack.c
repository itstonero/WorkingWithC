#include "stack.h"



int GS_push(Stack * stack, void * item)
{
    StackItem * newItem = (StackItem *)calloc(1, sizeof(StackItem));
    if(newItem == 0)
    {
        return 99;
    }

    newItem->value = item;
    newItem->next = stack->end;
    newItem->previous = stack->end->previous;
    stack->end->previous->next = newItem;
    stack->end->previous = newItem;

    stack->size += 1;

    return 0;
}

void * GS_pop(Stack * stack)
{
    if(stack == 0)
    {
        return NULL;
    }

    if(stack->popped != NULL) free(stack->popped);
    stack->popped = stack->end->previous;

    stack->popped->previous->next = stack->end;
    stack->end->previous = stack->popped->previous;
    stack->size -= 1;

    return stack->popped->value;
}

void * GS_peek(Stack * stack)
{
    if(stack->size == 0)
    {
        return NULL;
    }

    return stack->end->previous->value;
}

void GS_clear(Stack * stack)
{
    StackItem * temp = stack->head;
    StackItem * to_be_freed;

    while(temp->next != NULL)
    {
        to_be_freed = temp;
        temp = temp->next;
        if(to_be_freed->previous != NULL)
        {
            free(to_be_freed->value);
        }

        free(to_be_freed);
    }
    if(stack->popped != NULL) free(stack->popped);
    free(temp);
    free(stack);
    return;
}

int GS_attach(Stack * destination, Stack * source)
{
    StackItem * temp = source->head->next;
    while(temp->next != NULL)
    {
        GS_push(destination, temp->value);
        temp = temp->next;
    }
    return 0;
}

Stack * new_Stack()
{
    Stack * stack = (Stack *)calloc(1, sizeof(Stack));
    StackItem *head = (StackItem *)calloc(1, sizeof(StackItem));
    StackItem *end = (StackItem *)calloc(1, sizeof(StackItem));
    
    stack->head = head;
    stack->end = end;
    stack->popped = NULL;

    stack->attach = GS_attach;
    stack->clear = GS_clear;
    stack->peek = GS_peek;
    stack->pop = GS_pop;
    stack->push = GS_push;

    stack->head->previous = NULL;
    stack->end->next = NULL;
    stack->head->next = stack->end;
    stack->end->previous = stack->head;
    stack->size = 0;
    return stack;
}
