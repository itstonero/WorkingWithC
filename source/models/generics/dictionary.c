#include "dictionary.h"

void GD_clear(Dictionary * dictionary)
{
    free(dictionary->tables);
    free(dictionary);
}

int GD_add(Dictionary * dictionary, void * key, void * value)
{
    Dict newValue;

    dictionary->tables[++dictionary->size] = newValue;

    return 0;
}

void * GD_retrieve(Dictionary * dictionary, void * key)
{
    for(int i = 0; i < dictionary->size; i++)
    {

    }
}
Dictionary * new_Dictionary()
{
    Dictionary * dict = (Dictionary *)calloc(1, sizeof(Dictionary));
    dict->capacity =  10;
    dict->tables = (Dict *)calloc(dict->capacity, sizeof(Dict));
    dict->clear = GD_clear;
    dict->size = 0;
    return dict;
}
