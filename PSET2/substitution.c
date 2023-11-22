#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cipher(string text, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (strlen(argv[1]) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    int argvLength = strlen(argv[1]);
    for (int i = 0; i < argvLength; i++)
    {
        char iChar = argv[1][i];
        if (!isalpha(iChar))
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }

        for (int j = 0; j < argvLength; j++)
        {
            char jChar = argv[1][j];
            if (toupper(iChar) == toupper(jChar) && i != j)
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }
    }

    string key = argv[1];
    string text = get_string("plaintext:  ");
    return cipher(text, key);
}

int cipher(string text, string key)
{
    int value;
    char co;
    int textLength = strlen(text);

    printf("ciphertext: ");

    for (int i = 0; i < textLength; i++)
    {
        char x = text[i];
        if (isalpha(x) && isupper(x))
        {
            value = x - 65;
            co = toupper(key[value]);
        }
        else if (isalpha(x) && islower(x))
        {
            value = x - 97;
            co = tolower(key[value]);
        }
        else
        {
            co = x;
        }
        printf("%c", co);
    }
    printf("\n");
    return 0;
}