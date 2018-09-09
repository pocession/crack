#include <crypt.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

//This program is a practice of "recurse"
//The main function is for verifying users' entries and also print out the result
//The check function is for verifying whether users' entries are letter-only string

int check(int n);

int main(int argc, string argv[])
{
    //confirm whehter users enter a string with length up to 4 letters
    if (argc != 2)
    {
        printf("Please enter your password again\n");
        return 1;
    }
    string s = argv[1];
    char end = s[4];

    //call check function
    if (end != '\0')
    {
        printf("Please enter your password again-2\n");
        return 1;
    }
    for (int i = 0; i < 4; i++)
    {
        //check whether every entry is a letter
        char key = s[i];
        int key_ascii = (int) key;
        int result = check(key_ascii);
        if (result  == 0)
        //print out each letter
        printf("Damn it! Your guess: %c is correct!\n", key);
        if (result  == 1)
        //print out each letter
        printf("Ha! Your guess: %c is uncorrect!\n", key);
    }
}


//check function, it is a function to verify whether users' enteries are letter-only string (case sensitive)
int check(num)
{
    for (int k = 0; k < 26; k++)
    {
        int j = k + 65;
        if (num == j)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    for (int l = 32; l < 58; l++)
    {
        int m = l + 65;
        if (num == m)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
    return 1;
}