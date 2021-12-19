#include<stdio.h>
#include<math.h>
#include<cs50.h>
int main(void)
{
    float dollars;
    int c1 = 0, c5 = 0, c10 = 0, c25 = 0, TC = 0;
    do
    {
        dollars = get_float("enter the change: ");
    }
    while (dollars < 0);

    int cents = round(dollars * 100);
    while (cents >= 25)//counting 25 cents
    {
        c25++;
        cents = cents - 25;
    }
    while (cents < 25 && cents >= 10)//counting10 cents
    {
        c10++;
        cents = cents - 10;
    }
    while (cents < 10 && cents >= 5)//counting 5 cents
    {
        c5++;
        cents = cents - 5;
    }
    while (cents < 5 && cents >= 1)//counting cents
    {
        c1++;
        cents = cents - 1;
    }
    printf("%i", c25 + c10 + c5 + c1);//adding number of coins
}