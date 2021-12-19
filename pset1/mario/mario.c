#include<cs50.h>
#include<stdio.h>

int main(void)
{
    int i, j, k, l;
    do//propmting user for positive integer
    {

        l = get_int("Height: ");

    }

    while (l < 1 || l > 8);

    for (i = 0; i < l; i++)//iteration statements

    {

        for (j = l; j > i + 1; j--)//iteration statements
        {

            printf(" ");

        }
        for (k = l - i; k <= l; k++)//iteration statements
        {
            printf("#");
        }
        printf("  ");
        for (k = l - i; k <= l; k++)//iteration statements
        {
            printf("#");
        }
        printf("\n");


    }

}