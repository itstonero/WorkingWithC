#ifndef MESSAGING_TEMPLATE
#define MESSAGING_TEMPLATE
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <generics/generics.h>
#include <appServices/utilities.h>

typedef struct mti
{
    char message[300];
    char message_version[1];
    char message_originator[1];
    char message_function[1];
    char message_class[1];

    char bits[200];
    int (*unload)(List *);

    int fields[20];
    char * keys[16];
    int (*decode_response)(struct mti*, int);
    int (*encode_request)(struct mti*);
    void (*get_time)(char *);
}MTI;

MTI * new_MTI();

#endif