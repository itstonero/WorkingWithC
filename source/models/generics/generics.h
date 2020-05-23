
#ifndef GENERIC_ITEMS
#define GENERIC_ITEMS

#include "list.h"
#include "stack.h"
#include "queue.h"
#include "dictionary.h"

int deep_copy_list(List * super, List * sub);
int deep_copy_stack(Stack * super, Stack * sub);
int deep_copy_queue(Queue * super, Queue * sub);

#endif