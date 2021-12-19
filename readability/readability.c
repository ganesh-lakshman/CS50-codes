#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<math.h>

int main(void)
{
    string text;
    int letters = 0, word = 0, sentence = 0;
    float l, s, index;
    text = get_string("Text: ");//propting for a text
    for (int i = 0; text[i] != '\0'; i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')) //letters
        {
            letters++;
        }
        if (text[i] == ' ') //wrds
        {
            word++;
        }
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') //sentences
        {
            sentence++;
        }
    }
    // printf("%i letter(s) \n%i word(s) \n%i sentence(s) ",letters,word+1,sentence);
    //l = ((letters) /  word) * 100;
    l = (((float)letters / (float)(word + 1))) * 100; //  printf("%.2f\n",l);
    s = ((float)sentence / (float)(word + 1)) * 100;
    //   printf("%.2f",s);
    index = 0.0588 * l - 0.296 * s - 15.8;
    //  printf("%.2f",round(index)  );
    int ind = (int)round(index);
    if (ind > 16)
    {
        printf("Grade 16+\n");
    }
    if (ind < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (ind >= 1 && ind <= 16)
    {
        printf("Grade %i\n", ind);
    }
}