#include <crypt.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    //confirm whether users enter only one string
    if (argc != 2)
    {
        printf("Please enter your password again\n");
        return 1;
    }
    string s = argv[1];
    //confirm whether there is only one single letter for the entry
    char end = s[1];
    if (end != '\0')
    {
        printf("Please enter your password again\n");
        return 1;
    }
    char key = s[0];
    //transform key to ascii number, assign a variable n
    int n = (int) key;
    for (int i = 0; i < 26; i++)
    {
        int j = i + 65;
        if (n == j)
        {
            printf("Your password %c is correct\n", key);
        }
    }
    for (int k = 32; k < 58; k++)
    {
        int m = k + 65;
        if (n == m)
        {
            printf("Your password %c is correct\n", key);
        }
    }
}