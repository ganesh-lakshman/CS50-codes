#include<stdio.h>
#include<cs50.h>
#include<string.h>
int main(void)
{
    int counter = 0, digits, a[50], j = 0, k = 0, l, es = 0, os = 0, n, p, es1 = 0, x = 0, z;
    long int number;
    do
    {
        number = get_long("enter credit card number: ");
    }
    while (number < 0);

    while (number != 0)
    {
        digits = number % 10; //exracting last digit
        number = number / 10; //removing last digit
        a[j] = digits;
        j++;

    }
    p = j;



    for (n = 0; n < p / 2; n++) //check sum
    {
        if (a[2 * n + 1] > 4) // two digit or more individual digit sum
        {
            l = 2 * a[2 * n + 1];
            while (l != 0)
            {
                x = l % 10;
                k = k + x;
                l = l / 10;
            }
            es = es + k;
            k = 0;
        }


        else // even place sum
        {
            es1 = 2 * a[2 * n + 1] + es1;
        }
    }

    if (p % 2 != 0) //odd digit sum in odd place
    {
        for (z = 0; z <= p / 2; z++)
        {
            os = os + a[2 * z];
        }
    }
    else //even digit sum in odd place
        for (z = 0; z < p / 2; z++)
        {
            os = os + a[2 * z];
        }
    if ((os + es + es1) % 10 == 0) //check sum
    {
        if (p == 15 && (a[14] == 3 && (a[13] == 4 || a[13] == 7))) //americn express verification
        {
            printf("AMEX\n");
            counter = 1;
        }

        if (p == 16 && (a[15] == 5 && (a[13] <= 5))) //mastercard verification
        {
            printf("MASTERCARD\n");
            counter = 1;
        }
        if ((p == 13 && a[12] == 4) || (p == 16 && a[15] == 4)) //visa verification
        {
            printf("VISA\n");
            counter = 1;
        }
        if (counter == 0)
        {
            printf("INVALID\n");
        }

    }
    else
    {
        printf("INVALID\n");
    }
}