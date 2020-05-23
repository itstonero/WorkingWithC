#include <appControllers/activities.h>

int main()
{ 
    MTI * mti = new_MTI();
    strcpy(mti->message, "0800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301");

    mti->decode_response(mti, 0);

    puts(mti->bits);
    for(int i =0; i < mti->field_len; i++)
    {
        char * value = (char *)mti->definition->retrieve(mti->definition, mti->fields[i]);
        char * key = strtok(value, ">>>");
        int amount = atoi(strtok(NULL, ">>>"));


        if(key[0] == 'n')
        {
            strncpy(value, mti->bits, amount);
            strcpy(mti->bits, &mti->bits[amount]);
        }

        if(strcmp(key, "ans") == 0)
        {
            if(amount == 0)
            {
                strncpy(value, mti->bits, 4);
                amount = atoi(value);

                strcpy(mti->bits, &mti->bits[4]); 
            }

            strncpy(value, mti->bits, amount*2);
            strcpy(mti->bits, &mti->bits[amount*2]);
            
            char payload[200];
            int pos = -1;
            strcpy(payload, "");

            while(strlen(value) > 0)
            {
                char temp[2];
                strncpy(temp, value, 2);
                strcpy(value, &value[2]);
                payload[++pos]= (char)(18 + atoi(temp));
            }
            
            strncpy(value, payload, amount);
        }
        
        printf("Payload = %s ---- Remaining = %s\n", value, mti->bits);

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

