#include <transactions/MTI.h>
#include <appServices/utilities.h>
#include <appServices/repository.h>

int main()
{ 

    Stack * transactions = new_Stack();
    Utility utility = new_UTILITY();
    Repository * repo = new_Repo();

    while(1)
    {
        MTI * transaction = new_MTI();
        transactions->push(transactions, transaction);
        utility.get_string("Enter MTI Message ::: ", 4, 512, transaction->message);
        transaction->decode_response(transaction, (int)utility.get_number("Header Length ::: ", 0, 20));
        repo->insert_MTI(transaction);

        printf("Press ESC to cancel\n");
        if((int)_getch() == KEY_ESC)
        {
            break;
        }
    }
        
    transactions->clear(transactions);
    repo->clear(repo);
    return 0;
}

