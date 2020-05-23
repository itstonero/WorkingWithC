#include "repository.h"
#define TIMESTAMP "TIMESTAMP="
#define VERSION "||VERSION="
#define MESSAGE "||MESSAGE="
#define FUNCTION "||FUNCTION="
#define CLASS "||CLASS="
#define ORIGINATOR "||ORIGINATOR="
#define FIELDS "||FIELDS="
#define BITS "||BITS="
#define DELIMITER ":"

void convert_MTI_to_string(MTI * mti, char * data_to_record)
{
    strcpy(data_to_record, TIMESTAMP);
    strcat(data_to_record, "2020-05-11TT12:34:45:788");

    strcat(data_to_record, MESSAGE);
    strcat(data_to_record, mti->message);

    strcat(data_to_record, VERSION);
    data_to_record[strlen(data_to_record)] = mti->message_version;

    strcat(data_to_record, CLASS);
    data_to_record[strlen(data_to_record)] = mti->message_class;

    strcat(data_to_record, FUNCTION);
    data_to_record[strlen(data_to_record)] = mti->message_function;

    strcat(data_to_record, ORIGINATOR);
    data_to_record[strlen(data_to_record)] = mti->message_originator;

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
    
}

int DB_insert_MTI(MTI * mti)
{
    char const* const fileName = "records.txt"; /* should check that argc > 1 */
    FILE* file = fopen(fileName, "a");
    
    char converted[1000];
    convert_MTI_to_string(mti, converted);

    printf(">>>>>>>> START DEMO\n");
    puts(converted);
    printf(">>>>>>>> END DEMO\n");

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