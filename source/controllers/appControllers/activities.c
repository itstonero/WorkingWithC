#include "activities.h"

void ACTIVITIES_START_UI()
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