#include "utilities.h"

void getStringFromUser(char * message, int minLength, int maxLength, char * to_return)
{
    int len;

    do
    {
        char received[2000];

        printf(message);
        fflush(stdin);
        scanf("%s", received);
        fflush(stdin);
        len = strlen(received);
        if( len >= minLength && len <= maxLength)
        {
            strcpy(to_return, received);
            break;
        }
        
        if(len < minLength || len > maxLength)
        {
            printf("\tERROR:: Character Length Must Be Greater Than %d and Less Than %d\n", minLength, maxLength + 1);
        }

    } while (len < minLength || len > maxLength);
}

void getPasswordFromUser(char * message, int minLength, int maxLength, char * to_return)
{
    int pos;
    int len;

    do
    {
        pos = -1;
        char password[2000];

        printf(message);
        while(1)
        {
            int key_pressed = _getch();
            if(key_pressed == KEY_ESC || key_pressed == KEY_ENTER)
            {
                break;
            }

            if(key_pressed == KEY_SPACE || key_pressed == KEY_TAB || key_pressed == KEY_ARROWS)
            {
                continue;
            }

            if(key_pressed == KEY_BACKSPACE)
            {
                if(pos == -1) continue;

                printf("\b \b");
                password[pos] = '\0';
                --pos;
                continue;
            }

            printf("*");
            password[++pos] = (char)key_pressed;
        }
        printf("\n");

        
        len = pos + 1;
        if( len >= minLength && len <= maxLength)
        {
            strncpy(to_return, password, len);
            break;
        }
        
        printf("\tERROR:: Password Length Must Be Greater Than %d and Less Than %d\n", minLength, maxLength + 1);


    } while (len < minLength || len > maxLength);

}

double getNumberFromUser(char * message, int lowerLimit, int upperLimit)
{
    double to_return = lowerLimit -1;

    do
    {
        double received = to_return;
        char numbers[100];
        numbers[0] = '0';

        int pos = -1;

        printf(message);
        while(1)
        {
            int key_pressed = _getch();
            if(key_pressed == KEY_ESC || key_pressed == KEY_ENTER)
            {
                received = (double) atof(&numbers[0]);
                break;
            }

            if(key_pressed == KEY_BACKSPACE)
            {
                if(pos == -1) continue;

                printf("\b \b");
                numbers[pos] = '\0';
                --pos;
                continue;
            }

            if(key_pressed == KEY_FULLSTOP)
            {
                numbers[++pos] = (char)key_pressed;
                printf("%c", numbers[pos]);
                continue;
            }

            if(key_pressed < KEY_NUM_MIN || key_pressed > KEY_NUM_MAX)
            {
                continue;
            }


            numbers[++pos] = (char)key_pressed;
            printf("%c", numbers[pos]);
        }
        printf("\n");

        if(received >= lowerLimit && received <= upperLimit)
        {
            to_return = received;
            break;
        }
        
        printf("\tERROR:: Number Must Be Greater Than %d and Less Than %d\n", lowerLimit - 1, upperLimit + 1);

        received = to_return;
    } while (to_return < lowerLimit);

    return to_return;
}

Utility new_UTILITY()
{
    Utility manager;

    manager.get_string = getStringFromUser;
    manager.get_password = getPasswordFromUser;
    manager.get_number = getNumberFromUser;

    return manager;
}