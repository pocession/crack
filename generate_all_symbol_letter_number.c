#include <crypt.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

//this program is a practice for generating all kinds of symbols/letters/numbers for crack

int main()
{
    char begin = ' ';
    char end = '~';
    for (char first = begin; first <= end; first++)
    {
        char c[5];
        c[0] = first;
        c[1] = '\0';
        printf("%s ", c);
    }
    printf("\n");
}