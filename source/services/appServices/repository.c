#include "repository.h"

int DB_insert_MTI(MTI * mti)
{
    return 0;
}

void DB_clear(Repository * repo)
{
    if(repo != NULL)
    {
        free(repo);
    }
}

Repository * new_Repo()
{
    Repository * repo = (Repository *)calloc(1, sizeof(Repository));
    repo->insert_MTI = DB_insert_MTI;
    repo->clear = DB_clear;
    return repo;
}