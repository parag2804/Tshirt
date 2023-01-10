#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

#include "readline.h"

//read_line function to read the org name and tshirt size string
int read_line(char str[], int n)
{
    int ch, i=0;
    while (isspace(ch = getchar()))
        ;

    str[i++] = ch;
    while ((ch = getchar()) != '\n')
    {
     	if (i < n)
        str[i++] = ch;
    }
    str[i] = '\0';
    return i;
}

