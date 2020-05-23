#include <appControllers/activities.h>

int main()
{ 
    MTI * mti = new_MTI();
    List * fields = new_List();
    mti->unload(fields);


    ListItem * temp = fields->head->next;
    while(temp->next != NULL)
    {
        puts((char *)temp->value);
        temp = temp->next;
    }

    
    free(mti);
    fields->clear(fields);
    
    /*
    ACTIVITIES_START_UI();

    080020200000008000000000000000013239313130303031
    0800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301
    00460800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301
    */
    return 0;
}

