#include "list.h"


int GL_append(struct listHead *list, void * item, int index)
{
    if (index < 0 || index >= list->size)
    {
        return -1;
    }

    ListItem *newItem = (ListItem *)calloc(1, sizeof(ListItem));
    newItem->value = item;

    ListItem *temp = list->head->next;

    int counter = -1;

    while(temp->next != 0 )
    {
        if (++counter == index)
        {
            newItem->next = temp;
            newItem->previous = temp->previous;
            temp->previous->next = newItem;
            temp->previous = newItem;
            list->size += 1;
            return 0;
        }
        temp = temp->next;
    }
    
    
    return 1;
}

int GL_add(struct listHead * list, void * value)
{
    ListItem *newItem = (ListItem *)calloc(1, sizeof(ListItem));
    newItem->value = value;

    if(newItem == NULL)
    {
        return 1;
    }

    newItem->previous = list->tail->previous;
    newItem->next = list->tail;
    list->tail->previous->next = newItem;
    list->tail->previous = newItem;
    list->size += 1;

    return 0;
}

void * GL_retrieve(struct listHead *list, int index)
{
    if(index < 0 || index >= list->size)
    {
        return NULL;
    }

    ListItem * ptr = list -> head -> next;
    
    for(int i = 0; i < list->size; i++)
    {
        if(index == i)
        {
            return ptr->value;
        }
        ptr = ptr->next;
    }
        
    return NULL;
}

int GL_update(struct listHead *list, void * item, int index)
{
    if (index < 0 || index >= list->size)
    {
        return -1;
    }


    ListItem *temp = list->head;

    for (int i = 0; i < list->size; i++)
    {
        temp = temp->next;
        if (i == index)
        {
            ListItem * tempItem = temp->value;
            temp->value = item;
            if(tempItem != NULL) free(tempItem);
            return 0;
        }
    }

    return 1;
}

int GL_remove(struct listHead *list, int index)
{
    if (index < 0 || index >= list->size)
    {
        return -1;
    }


    ListItem *temp = list->head;
    for (int i = 0; i < list->size; i++)
    {
        temp = temp->next;
        if (i == index)
        {
            temp->next->previous = temp->previous;
            temp->previous->next = temp->next;
            list->size -= 1;
            free(temp);
            return 0;
        }

    }

    return 1;
}

void GL_clear(struct listHead *list)
{
    if(list->size <= 0)
    {
        return;
    }

    ListItem *temp = list->head;

    while(temp->next !=NULL)
    {
        ListItem *to_be_freed = temp;
        temp = temp->next;
        
        if(to_be_freed->value != NULL)
        {
            free(to_be_freed->value);
        }

        free(to_be_freed);
    }

    free(temp);
    free(list);
}

int GL_attach(struct listHead* destination, struct listHead* source)
{
    ListItem * temp = source->head->next;
    while(temp->next != NULL)
    {
        GL_add(destination, temp->value);
        temp = temp->next;
    }
    return 0;
}

List * new_List()
{
    List * list = (List *)calloc(1, sizeof(List));
    ListItem *head = (ListItem *)calloc(1, sizeof(ListItem));
    ListItem *tail = (ListItem *)calloc(1, sizeof(ListItem));

    list->add = GL_add;
    list->append = GL_append;
    list->attach = GL_attach;
    list->clear = GL_clear;
    list->remove = GL_remove;
    list->retrieve = GL_retrieve;
    list->update = GL_update;

    list->head = head;
    list->tail = tail;
    list->size = 0;

    list->head->next = list->tail;
    list->tail->previous = list->head;
    list->head->previous = NULL;
    list->tail->next = NULL;

    return list;
}
