#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>

int main(int argc, string argv[])

{
    if (argc != 2) //no key prompted
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    int count1 = 0;
    for (int a = 0; a < strlen(argv[1]); a++) //checking repeated charcaters
    {
        for (int b = 0; b < strlen(argv[1]); b++)
        {
            if (b != a)
            {
                if (argv[1][a] == argv[1][b])
                {
                    count1++;
                }
            }
        }

    }
    if (count1 != 0)
    {
        printf("Key must not contain repeated characters. \n");
        return 1;
    }
    int count0 = 0;
    for (int i = 0; i < strlen(argv[1]); i++) //non digit string prompted,alphabets26
    {
        if (isalpha(argv[1][i]) != 0)
        {
            count0++;
        }

    }
    if (count0 != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    if (argc == 2 && count0 == 26)
    {
        string plain;
        plain = get_string("plaintext: ");
        int alphaU[26], cipher[26], alphaL[26];
        for (int i = 0; i < 26; i++) //uppercase in an array
        {
            alphaU[i] = 65 + i;
            //printf("%c",alpha[i]);
        }
        for (int j = 0; j < 26; j++) //lower case in an array
        {
            alphaL[j] = 97 + j;
            //printf("%c",alpha[i]);
        }
        printf("ciphertext: \n");
        for (int x = 0; x < strlen(plain); x++)
        {
            int count = 0;
            for (int y = 0; y < 26; y++)
            {

                if (plain[x] == alphaU[y] || plain[x] == alphaL[y]) //check if char is alpha
                {
                    cipher[x] = argv[1][y];
                    if (isupper(plain[x]) != 0) //if plain is upper change cipher to upper
                    {
                        printf("%c", toupper(cipher[x]));

                        count++;
                        break;
                    }
                    else
                    {
                        printf("%c", tolower(cipher[x])); //if plain is lower change cipher to lower
                        count++;
                        break;
                    }
                }



            }
            if (count == 0) //print non alphabets
            {
                printf("%c", plain[x]);
            }

        }
        printf("\n");
        return 0;

    }

    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}