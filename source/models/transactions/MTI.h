#ifndef MESSAGING_TEMPLATE
#define MESSAGING_TEMPLATE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <generics/generics.h>

typedef struct mti
{
    char message[300];
    char message_version;
    char message_originator;
    char message_function;
    char message_class;

    char bits[200];
    char ** (*unload)();

    int fields[20];
    char * keys[16];
    int (*decode_response)(struct mti*, int);
    int (*encode_request)(struct mti*);
}MTI;

MTI * new_MTI();

#endif