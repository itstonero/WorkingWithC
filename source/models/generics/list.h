#ifndef GENERIC_LIST
#define GENERIC_LIST
#include <stdlib.h>

typedef struct list
{
    void * value;
    struct list * next;
    struct list * previous;
}ListItem;


typedef struct listHead
{
    ListItem *head;
    ListItem *tail;
    
    int (*add)(struct listHead*, void *);
    int (*append)(struct listHead*, void *, int);
    int (*attach)(struct listHead*, struct listHead*);
    int (*update)(struct listHead*, void *, int);
    void * (*retrieve)(struct listHead*, int);
    int (*remove)(struct listHead*, int);
    void (*clear)(struct listHead*);
    int size;
}List;

List * new_List();

#endif