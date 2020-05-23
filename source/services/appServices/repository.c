#include "repository.h"

void convert_MTI_to_string(MTI * mti, char * data_to_record)
{
    char time_stamp[30];
    mti->get_time(time_stamp);

    strcpy(data_to_record, TIMESTAMP);
    strcat(data_to_record, time_stamp);

    strcat(data_to_record, MESSAGE);
    strcat(data_to_record, mti->message);

    strcat(data_to_record, VERSION);
    strncat(data_to_record, mti->message_version, sizeof(char));

    strcat(data_to_record, CLASS);
    strncat(data_to_record, mti->message_class, sizeof(char));

    strcat(data_to_record, FUNCTION);
    strncat(data_to_record, mti->message_function, sizeof(char));

    strcat(data_to_record, ORIGINATOR);
    strncat(data_to_record, mti->message_originator, sizeof(char));

    strcat(data_to_record, FIELDS);
    int count = -1;
    while(mti->fields[++count] != '\0')
    {
        char str[12];
        sprintf(str, "%d", mti->fields[count]);
        strcat(data_to_record, str);

        if(mti->fields[count + 1] != '\0')
        {
            strcat(data_to_record, DELIMITER);
        }
    }

    strcat(data_to_record, BITS);
    strcat(data_to_record, mti->bits);
    strcat(data_to_record, "\n");
}

int DB_insert_MTI(MTI * mti)
{
    char const* const fileName = "records.txt"; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "a");
    
    char converted[1000];
    convert_MTI_to_string(mti, converted);

    fputs(converted, file);
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