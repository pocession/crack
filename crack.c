#include <crypt.h>
#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>

//The program is based on: https://github.com/matthiasludwig/cs50-pset2/blob/master/crack.c (with very little modification)
//This program is an answer for problem set 1 in cs50 2018x
//Salt is set as 50 by default, key is set as 4-letter string
//hash1 = crypt(salt1, key1); hash2 = crypt(salt2, key2); Since all salts are set as 50, key1 = key2 if hash1 = hash2
//The program is used for generating all possible keys and passing to the crypt() for cracking the key
//I did not use any recurse function for this program, but will try in another version


int check(int n);

int main(int argc, string argv[])
{
    //confirm whehter users enter a string for hash
    if (argc != 2)
    {
        printf("Please enter your password again\n");
        return 1;
    }
    string hash = argv[1];
    char *salt = "50";
    char initial = ' ';
    char end = '~';
    int result;

    //Now we are starting to try
    printf("Now we are trying. Don't turn off your laptop! It may take seconds, minutes, or even days!\n");

    //We are creating a big for loop, to generate all possible keys (1- to 4-letter)
    //Generating 1-letter key
    for (char first = initial; first <= end; first++)
    {
        char c[5];
        c[0] = first;
        c[1] = '\0';
        result = strcmp(crypt(c, salt), hash);
        if (result == 0)
        {
            printf("Password: %s found!\n", c);
            return 0;
        }

        //Generating 2-letter key
        for (char second = initial; second <= end; second++)
        {
            //Generating 2-letter key
            c[0] = first;
            c[1] = second;
            c[2] = '\0';
            if (result == 0)
            {
                printf("Password: %s found!\n", c);
                return 0;
            }

            //Generating 3-letter keys
            for (char third = initial; third <= end; third++)
            {
                c[0] = first;
                c[1] = second;
                c[2] = third;
                c[3] = '\0';
                if (result == 0)
                {
                    printf("Password: %s found!\n", c);
                    return 0;
                }

                //Generating 4-letter key
                for (char fourth = initial; fourth <= end; fourth++)
                {
                    c[0] = first;
                    c[1] = second;
                    c[2] = third;
                    c[3] = fourth;
                    c[4] = '\0';
                    if (result == 0)
                    {
                        printf("Password: %s found!\n", c);
                        return 0;
                    }
                }
            }
        }
    }
    printf("\n");
}
