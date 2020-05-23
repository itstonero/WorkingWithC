#ifndef APP_REPOSITORY
#define APP_REPOSITORY
#include <transactions/mti.h>

typedef struct repo
{
    int (*insertMTI)(MTI *);
}Repository;

#endif