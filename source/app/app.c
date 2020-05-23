#include <appControllers/activities.h>

int main()
{ 
    MTI * mti = new_MTI();
    strcpy(mti->message, "080020200000008000000000000000013239313130303031");

    mti->decode_response(mti, 0);

    for(int i =0; i < mti->field_len; i++)
    {
        printf("Field %d => %d\n", i+1, mti->fields[i]);
    }
    

    mti->clear(mti);
    
    /*
    ACTIVITIES_START_UI();
    080020200000008000000000000000013239313130303031
    0800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301
    00460800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301
    */
    return 0;
}

