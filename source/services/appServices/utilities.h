#ifndef APP_UTILITIES
#define APP_UTILITIES
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

typedef struct utils
{
void (*get_string)(char*, int, int, char *);
void (*get_password)(char*, int, int, char *);
double (*get_number)(char*, int, int);

}Utility;

Utility new_UTILITY();
#endif