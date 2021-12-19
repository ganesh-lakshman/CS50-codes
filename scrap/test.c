/*#include<stdio.h>
#include<cs50.h>
int fact(int x);
int main(void)
{
    int n=get_int("number: ");
    printf("%i",fact(n));
}
int fact(int x)
{
    int y;
    if(x==1)
    return 1;
    else{
      y = x*fact(x-1);
    }
     return y;
}
else if (preferennce[i][0]==j&&candidates[j].eliminated == true)
            {
                int l=preference[i][1];
                candidates[l].votes++;
               int k=0
                while(candidates[j].eliminated == true)
                {
                    int l=preference[i][k+1];
                candidates[l].votes++;
                k++;
                }*/
#include<stdio.h>
#include<string.h>
#include<cs50.h>
#include<stdlib.h>
#include<ctype.h>
int main(void)
{
    char *s="ganesh";
    char *t=malloc(strlen(s)+1);
    //strcpy(t, s);
    for(int i=0,n=strlen(s);i<n;i++)
    {
        t[i]=s[i];
    }
    t[0]=toupper(t[0]);
    printf("%i\n",s[6]);
    printf("%i\n",t[6]);
}