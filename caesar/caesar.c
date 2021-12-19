#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 1) //no key prompted
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    int count = 0;
    for (int i = 0; i < strlen(argv[1]); i++) //non digit string prompted
    {
        if (isdigit(argv[1][i]) != 0)
        {
            count++;
        }

    }


    if (argc == 2 && strlen(argv[1]) == count) //only two arguments prompted
    {

        int key = atoi(argv[1]);
        string plain;
        plain = get_string("plaintext: ");
        int n = strlen(plain);
        int cipher[n];
        printf("ciphertext: ");
        for (int i = 0; plain[i] != '\0'; i++) //encryption
        {
            int alpha = 0;
            if (plain[i] <= 90 && plain[i] >= 65) //uppercase rotation
            {
                plain[i] = plain[i] - 65;
                cipher[i] = (plain[i] + key) % 26;
                printf("%c", cipher[i] + 65);
                alpha++;
            }

            if (plain[i] <= 122 && plain[i] >= 97) //lower case rotation
            {
                plain[i] = plain[i] - 97;
                cipher[i] = (plain[i] + key) % 26;
                printf("%c", cipher[i] + 97);
                alpha++;
            }
            if (alpha == 0) //character no rotation
            {
                printf("%c", plain[i]);
            }

        }

        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}