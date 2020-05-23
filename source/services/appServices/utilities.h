#ifndef APP_UTILITIES
#define APP_UTILITIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

#define KEY_ENTER 13
#define KEY_BACKSPACE 8
#define KEY_ESC 27
#define KEY_SPACE 32
#define KEY_TAB 9
#define KEY_ARROWS 0
#define KEY_NUM_MIN 48
#define KEY_NUM_MAX 57
#define KEY_FULLSTOP 46
typedef struct utils
{
void (*get_string)(char*, int, int, char *);
void (*get_password)(char*, int, int, char *);
double (*get_number)(char*, int, int);

}Utility;

Utility new_UTILITY();
#endif