#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int checkKey(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("enter 1 command line arguement: ./substitution key");
        return 1;
    }

    bool validKey = checkKey(argv[1]);

    if (validKey == 1)
    {
        printf("enter a valid 26 letters key\n");
        return 1;
    }

    string plaintext = get_string("plaintext:");
    string ciphertext = encrypt(plaintext, argv[1]);

    printf("ciphertext:%s\n", ciphertext);
    return 0;
}


int checkKey(string key)
{


    if (strlen(key) == 26)
    {
        int length = strlen(key);


        for (int i = 0; i < length ; i++)
        {
            if ((!(key[i] >= 65 && key[i] <= 90) && !(key[i] >= 97 && key[i] <= 122)))  //check alphabet
            {
                return 1;
                break;
            }
        }


        for (int i = 0; i < length ; i++)
        {
            for (int j = 0 ; j < length ; j++)
            {
                if (((key[i] == key[j] - 32) || (key[i] == key[j]) || (key[i] == key[j] + 32)) && (j != i))         //check repition, case senstive
                {
                    return 1;
                    break;
                }
            }

        }

        return 0;

    }

    return 1;
}



string encrypt(string plaintext, string key)
{
    int textLength = strlen(plaintext);

    for (int i = 0; i < textLength ; i++)
    {
        if (plaintext[i] >= 97 && plaintext[i] <= 122)
        {
            int pt = plaintext[i] - 97;
            plaintext[i] = key[pt];

            if (plaintext[i] >= 65 && plaintext[i] <= 90)
            {
                plaintext[i] += 32;
            }
        }
        else if (plaintext[i] >= 65 && plaintext[i] <= 90)
        {
            int pt = plaintext[i] - 65;
            plaintext[i] = key[pt];

            if (plaintext[i] >= 97 && plaintext[i] <= 122)
            {
                plaintext[i] -= 32;
            }

        }

    }


    return plaintext;

}