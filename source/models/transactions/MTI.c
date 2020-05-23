#include "MTI.h"
#define HEX_KEYS 16

int get_number(char hex_char)
{
    int value = (int)hex_char - 48;
    if(value > 9)
    {
        return value - 7;
    }

    return value;
}

char * populate_fields(MTI * mti, char * bitMaps)
{
    char * has_secondary = mti->keys[get_number(bitMaps[0])];

    int total_length = (has_secondary[0] == '1') ? HEX_KEYS * 2 : HEX_KEYS;

    int count = -1;

    for(int i = 0; i < total_length; i++)
    {
        int next = -1;
        char * bin =  mti->keys[get_number(bitMaps[i])];

        while(bin[++next] != '\0')
        {
            if(bin[next] == '1' && i + next > 0)
            {
                mti->fields[++count] =  ((i * 4) + (next + 1));
                mti->field_len += 1;
            }
        }
    }

    return &bitMaps[total_length];
}

int decode_MTI(MTI * mti, int offset)
{
    mti->message_version[0] = mti->message[offset];
    mti->message_class[0] = mti->message[offset + 1];
    mti->message_function[0] = mti->message[offset + 2];
    mti->message_originator[0] = mti->message[offset + 3];

    char * bits = populate_fields(mti, &mti->message[offset + 4]);
    strcpy(&mti->bits[0], bits);

    printf("[[ %s ]]\n", mti->message);
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
            /*
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
            */
        }
        
        printf("\tField = %d ---- Payload = %s\n", mti->fields[i], value);
    }

    return 0;
}

int encode_MTI(MTI * mti)
{
    return 0;
}

int MTI_load(List * fields)
{
    char * save_to = (char *)calloc(20, sizeof(char));
    fields->add(fields, save_to);
    strcpy(save_to, "MTI INDEXING");

    FILE* file = fopen(FIELD_INDEXING_PATH, "r");

    char line[256];

    while (fgets(line, sizeof(line), file)) 
    {
        char * tokenized = strtok(line, FIELDS_DELIMITEER);
        tokenized = strtok(NULL, FIELDS_DELIMITEER);
        save_to = (char *)calloc(20, sizeof(char));
        fields->add(fields, save_to);
        strcpy(save_to, tokenized);
    }

    fclose(file);

    return 0;
}

void MTI_clear(MTI * mti)
{
    if(mti->definition != NULL)
    {
        free(mti->definition);
    }

    if(mti != NULL) free(mti);
}

MTI * new_MTI()
{

    MTI * mti = (MTI *)calloc(1, sizeof(MTI));
    char * keys[HEX_KEYS] = {
                    "0000","0001","0010","0011",
                    "0100","0101","0110","0111",
                    "1000","1001", "1010", "1011", 
                    "1100", "1101", "1110", "1111"
                };
    
    for(int i = 0; i < HEX_KEYS; i++)
    {
        mti->keys[i] = keys[i];
    }
    mti->definition = new_List();
    mti->field_len = 0;
    MTI_load(mti->definition);
    mti->clear = MTI_clear;
    mti->get_time = generate_timestamp;
    mti->decode_response = decode_MTI;
    mti->encode_request = encode_MTI;
    return mti;
}