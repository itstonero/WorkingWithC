#include <transactions/MTI.h>
#include <appServices/utilities.h>
#include <appServices/repository.h>

void Start_UI();

int main()
{ 

        //  080020200000008000000000000000013239313130303031
        //  0800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301
        //  00460800A02000000080001004000000000000000000000000013239313130303031001054455354204D455353470301
    return 0;
}







void Start_UI()
{
    Stack * transactions = new_Stack();
    Utility utility = new_UTILITY();
    Repository * repo = new_Repo();

    while(1)
    {
        printf("Press Enter to Decode MTI Message.\n");
        if((int)_getch() != KEY_ENTER)
        {
            break;
        }

        MTI * transaction = new_MTI();
        transactions->push(transactions, transaction);
        utility.get_string("Enter MTI Message ::: ", 4, 512, transaction->message);
        transaction->decode_response(transaction, (int)utility.get_number("Header Length ::: ", 0, 20));
        repo->insert_MTI(transaction);

    }
        
    transactions->clear(transactions);
    repo->clear(repo);

}

