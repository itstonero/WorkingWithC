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

    return 0;
}

int encode_MTI(MTI * mti)
{
    return 0;
}

char ** MTI_load()
{
    char ** fields = (char **)calloc(130, sizeof(char));

    char const* const fileName = "C:\\Users\\HP\\Documents\\Software Development\\repos\\WorkingWithC\\source\\models\\fields.txt"; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "r");
    char line[256];
    strcpy(&fields[0][0], "MTI");

    while (fgets(line, sizeof(line), file)) 
    {
        char * tokenized = strtok(line, "||");
        tokenized = strtok(NULL, "||");
    }

    fclose(file);

    return fields;
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
    mti->unload = MTI_load;
    mti->get_time = generate_timestamp;
    mti->decode_response = decode_MTI;
    mti->encode_request = encode_MTI;
    return mti;
}