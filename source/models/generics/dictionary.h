#ifndef GENERIC_DICTIONARY
#define GENERIC_DICTIONARY
#include <stdlib.h>

typedef struct dicItem
{
    char value[120];
    char key[120];
}Dict;

typedef struct dicHead
{
    Dict * tables;
    int (*add)(struct dicHead, void *, void *);
    void (*clear)(struct dicHead*);
    int size;
    int capacity;
}Dictionary;

Dictionary * new_Dictionary();

#endif