#include <transactions/MTI.h>
#include <appServices/utilities.h>
#include <appServices/repository.h>

int main()
{ 

    Stack * transactions = new_Stack();
    printf("Created Stack Successfully....\n");

    MTI * transact1 = new_MTI();
    printf("Created MTI template Successfully....\n");

    transactions->push(transactions, transact1);
    printf("Enqueued MTI Successfully....\n");

    strcpy(transact1->message, "080020200000008000000000000000013239313130303031");
    printf("Copied Message Into Template Successfully...\n");
    
    transact1->decode_response(transact1, 0);
    printf("Decoded Message Successfully...\n");
    
    /*
    char ** defined = transact1->unload();


    transact1 = new_MTI();
    strcpy(transact1->message, "0800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301");
    transact1->decode_response(transact1, 0);
    transactions->push(transactions, transact1);

    transact1 = new_MTI();
    strcpy(transact1->message, "00460800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301");
    transact1->decode_response(transact1, 4);
    transactions->push(transactions, transact1);

    void * temp = transactions->pop(transactions);
    
    while(temp != NULL)
    {
        MTI transact = *(MTI*)temp;
            printf("\n======================================================================================\n");
            printf("MTI ==> %s\n", transact.message);
            printf("Version => %c\n", transact.message_version);
            printf("Class => %c\n", transact.message_class);
            printf("Function => %c\n", transact.message_function);
            printf("Originator => %c\n", transact.message_originator);
            int count = -1;
            while(transact.fields[++count] != '\0')
            {
                printf("Field %d => %d\n", count + 1, transact.fields[count]);
            }
            printf("Bits => %s", transact.bits);
            printf("\n======================================================================================\n");

        temp = transactions->pop(transactions);
    }

    printf("Assigned New Definition...\n");
    char userName[90];
    char passWord[90];
    double age;

    Utility utility = new_UTILITY();

    utility.get_string("Enter UserName ::: ", 3, 6, userName);
    printf("%s \n", userName);
    printf("=============================================\n");
    utility.get_password("Enter Password ::: ", 3, 6, passWord);
    printf("%s \n", passWord);
    printf("=============================================\n");
    age = utility.get_number("Enter Age ::: ", 3, 6);
    printf("%d \n", (int)age);

    */
    
    Repository * repo = new_Repo();
    printf("Created Repository Template Successfully..\n");
    
    repo->insert_MTI(transact1);
    printf("Inserted MTI into Repository Successfully..\n");
    
    transactions->clear(transactions);
    printf("Cleared Stack Successfully..\n");

    repo->clear(repo);
    printf("Cleared Repository Successfully..\n");
    return 0;
}

