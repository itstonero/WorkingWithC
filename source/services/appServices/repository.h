#ifndef APP_REPOSITORY
#define APP_REPOSITORY
#define TIMESTAMP "TIMESTAMP="
#define VERSION "||VERSION="
#define MESSAGE "||MESSAGE="
#define FUNCTION "||FUNCTION="
#define CLASS "||CLASS="
#define ORIGINATOR "||ORIGINATOR="
#define FIELDS "||FIELDS="
#define BITS "||BITS="
#define DELIMITER ":"
#include <transactions/mti.h>
typedef struct repo
{
    int (*insert_MTI)(MTI *);
    void (*clear)(struct repo *);
}Repository;

Repository * new_Repo();

#endif