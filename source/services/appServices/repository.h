#ifndef APP_REPOSITORY
#define APP_REPOSITORY
#include <transactions/mti.h>

typedef struct repo
{
    int (*insert_MTI)(MTI *);
    void (*clear)(struct repo *);
}Repository;

Repository * new_Repo();

#endif