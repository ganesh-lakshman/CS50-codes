#include "helpers.h"
#include<math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float avg = (float)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / (float)3;
            image[i][j].rgbtRed = (int)round(avg);
            image[i][j].rgbtGreen = (int)round(avg);
            image[i][j].rgbtBlue = (int)round(avg);


        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;



            if ((int)round((float)(0.393 * (float)originalRed) + (float)(0.769 * (float)originalGreen) + (float)(0.189 *
                           (float)originalBlue)) > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = (int)round((float)(0.393 * (float)originalRed) + (float)(0.769 * (float)originalGreen) + (float)(0.189 *
                                                 (float)originalBlue));

            }
            if ((int)round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue) > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = (int)round(0.349 * originalRed + 0.686 * originalGreen + 0.168 * originalBlue);

            }
            if ((int)round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue) > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = (int)round(0.272 * originalRed + 0.534 * originalGreen + 0.131 * originalBlue);
            }
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE fimage[height][width];
    for (int j = 0; j < height; j++)
    {
        for (int i = 0; i != width - i - 1, i < width - i - 1; i++)
        {
            fimage[0][0] = image[j][i];

            image[j][i] = image[j][width - i - 1];
            image[j][width - i - 1] = fimage[0][0];

        }
    }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //divide and conquer
    RGBTRIPLE fimage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            fimage[i][j] = image[i][j];
        }
    }

    /* //middle pixel
     image[1][1].rgbtRed=(int)round((float)(fimage[2][2].rgbtRed+fimage[0][0].rgbtRed+fimage[0][1].rgbtRed+fimage[0][2].rgbtRed+fimage[1][0].rgbtRed+fimage[1][1].rgbtRed+fimage[1][2].rgbtRed+fimage[2][0].rgbtRed+fimage[2][1].rgbtRed)/(float)9);
     image[1][1].rgbtGreen=(int)round((float)(fimage[2][2].rgbtGreen+fimage[0][0].rgbtGreen+fimage[0][1].rgbtGreen+fimage[0][2].rgbtGreen+fimage[1][0].rgbtGreen+fimage[1][1].rgbtGreen+fimage[1][2].rgbtGreen+fimage[2][0].rgbtGreen+fimage[2][1].rgbtGreen)/(float)9);
     image[1][1].rgbtBlue=(int)round((float)(fimage[2][2].rgbtBlue+fimage[0][0].rgbtBlue+fimage[0][1].rgbtBlue+fimage[0][2].rgbtBlue+fimage[1][0].rgbtBlue+fimage[1][1].rgbtBlue+fimage[1][2].rgbtBlue+fimage[2][0].rgbtBlue+fimage[2][1].rgbtBlue)/(float)9);
     //edge pixel
     image[0][1].rgbtRed=(int)round((float)(fimage[0][1].rgbtRed+fimage[0][0].rgbtRed+fimage[0][2].rgbtRed+fimage[1][0].rgbtRed+fimage[1][1].rgbtRed+fimage[1][2].rgbtRed)/(float)6);
     image[0][1].rgbtGreen=(int)round((float)(fimage[0][1].rgbtGreen+fimage[0][0].rgbtGreen+fimage[0][2].rgbtGreen+fimage[1][0].rgbtGreen+fimage[1][1].rgbtGreen+fimage[1][2].rgbtGreen)/(float)6);
     image[0][1].rgbtBlue=(int)round((float)(fimage[0][1].rgbtBlue+fimage[0][0].rgbtBlue+fimage[0][2].rgbtBlue+fimage[1][0].rgbtBlue+fimage[1][1].rgbtBlue+fimage[1][2].rgbtBlue)/(float)6);
     //corner pixel
     image[0][0].rgbtRed=(int)round((float)(fimage[0][0].rgbtRed+fimage[0][1].rgbtRed+fimage[1][0].rgbtRed+fimage[1][1].rgbtRed)/(float)4);
     image[0][0].rgbtGreen=(int)round((float)(fimage[0][0].rgbtGreen+fimage[0][1].rgbtGreen+fimage[1][0].rgbtGreen+fimage[1][1].rgbtGreen)/(float)4);
     image[0][0].rgbtBlue=(int)round((float)(fimage[0][0].rgbtBlue+fimage[0][1].rgbtBlue+fimage[1][0].rgbtBlue+fimage[1][1].rgbtBlue)/(float)4);*/
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0) //top left corner pixel
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i][j + 1].rgbtRed + fimage[i + 1][j].rgbtRed + fimage[i +
                                                 1][j + 1].rgbtRed) / (float)4);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i][j + 1].rgbtGreen + fimage[i + 1][j].rgbtGreen +
                                                   fimage[i + 1][j + 1].rgbtGreen) / (float)4);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i][j + 1].rgbtBlue + fimage[i + 1][j].rgbtBlue + fimage[i +
                                                  1][j + 1].rgbtBlue) / (float)4);
            }
            if (i == 0 && j == width - 1) //top right corner pixel
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i][j - 1].rgbtRed + fimage[i + 1][j - 1].rgbtRed + fimage[i +
                                                 1][j].rgbtRed) / (float)4);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i][j - 1].rgbtGreen + fimage[i + 1][j - 1].rgbtGreen +
                                                   fimage[i + 1][j].rgbtGreen) / (float)4);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i][j - 1].rgbtBlue + fimage[i + 1][j - 1].rgbtBlue +
                                                  fimage[i + 1][j].rgbtBlue) / (float)4);
            }
            if (i == height - 1 && j == 0) //bottom left corner pixel
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i - 1][j].rgbtRed + fimage[i - 1][j + 1].rgbtRed +
                                                 fimage[i][j + 1].rgbtRed) / (float)4);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i - 1][j].rgbtGreen + fimage[i - 1][j + 1].rgbtGreen +
                                                   fimage[i][j + 1].rgbtGreen) / (float)4);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i - 1][j].rgbtBlue + fimage[i - 1][j + 1].rgbtBlue +
                                                  fimage[i][j + 1].rgbtBlue) / (float)4);
            }
            if (i == height - 1 && j == width - 1) //bottom right corner pixel
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i][j - 1].rgbtRed + fimage[i - 1][j].rgbtRed + fimage[i -
                                                 1][j - 1].rgbtRed) / (float)4);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i][j - 1].rgbtGreen + fimage[i - 1][j].rgbtGreen +
                                                   fimage[i - 1][j - 1].rgbtGreen) / (float)4);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i][j - 1].rgbtBlue + fimage[i - 1][j].rgbtBlue + fimage[i -
                                                  1][j - 1].rgbtBlue) / (float)4);
            }
            if (i != 0 && i != height - 1 && j == 0) //left edge
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i - 1][j].rgbtRed + fimage[i + 1][j].rgbtRed + fimage[i -
                                                 1][j + 1].rgbtRed + fimage[i][j + 1].rgbtRed + fimage[i + 1][j + 1].rgbtRed) / (float)6);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i - 1][j].rgbtGreen + fimage[i + 1][j].rgbtGreen +
                                                   fimage[i - 1][j + 1].rgbtGreen + fimage[i][j + 1].rgbtGreen + fimage[i + 1][j + 1].rgbtGreen) / (float)6);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i - 1][j].rgbtBlue + fimage[i + 1][j].rgbtBlue + fimage[i -
                                                  1][j + 1].rgbtBlue + fimage[i][j + 1].rgbtBlue + fimage[i + 1][j + 1].rgbtBlue) / (float)6);
            }
            if (i != 0 && i != height - 1 && j == width - 1) //right edge
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i + 1][j].rgbtRed + fimage[i - 1][j].rgbtRed + fimage[i +
                                                 1][j - 1].rgbtRed + fimage[i][j - 1].rgbtRed + fimage[i - 1][j - 1].rgbtRed) / (float)6);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i + 1][j].rgbtGreen + fimage[i - 1][j].rgbtGreen +
                                                   fimage[i + 1][j - 1].rgbtGreen + fimage[i][j - 1].rgbtGreen + fimage[i - 1][j - 1].rgbtGreen) / (float)6);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i + 1][j].rgbtBlue + fimage[i - 1][j].rgbtBlue + fimage[i +
                                                  1][j - 1].rgbtBlue + fimage[i][j - 1].rgbtBlue + fimage[i - 1][j - 1].rgbtBlue) / (float)6);
            }
            if (i == 0 && j != 0 && j != width - 1) //top edge
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i][j - 1].rgbtRed + fimage[i][j + 1].rgbtRed + fimage[i +
                                                 1][j - 1].rgbtRed + fimage[i + 1][j].rgbtRed + fimage[i + 1][j + 1].rgbtRed) / (float)6);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i][j - 1].rgbtGreen + fimage[i][j + 1].rgbtGreen +
                                                   fimage[i + 1][j - 1].rgbtGreen + fimage[i + 1][j].rgbtGreen + fimage[i + 1][j + 1].rgbtGreen) / (float)6);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i][j - 1].rgbtBlue + fimage[i][j + 1].rgbtBlue + fimage[i +
                                                  1][j - 1].rgbtBlue + fimage[i + 1][j].rgbtBlue + fimage[i + 1][j + 1].rgbtBlue) / (float)6);
            }
            if (i == height - 1 && j != 0 && j != width - 1) //bottom edge
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i][j].rgbtRed + fimage[i][j - 1].rgbtRed + fimage[i][j + 1].rgbtRed + fimage[i -
                                                 1][j - 1].rgbtRed + fimage[i - 1][j].rgbtRed + fimage[i - 1][j + 1].rgbtRed) / (float)6);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i][j].rgbtGreen + fimage[i][j - 1].rgbtGreen + fimage[i][j + 1].rgbtGreen +
                                                   fimage[i - 1][j - 1].rgbtGreen + fimage[i - 1][j].rgbtGreen + fimage[i - 1][j + 1].rgbtGreen) / (float)6);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i][j].rgbtBlue + fimage[i][j - 1].rgbtBlue + fimage[i][j + 1].rgbtBlue + fimage[i -
                                                  1][j - 1].rgbtBlue + fimage[i - 1][j].rgbtBlue + fimage[i - 1][j + 1].rgbtBlue) / (float)6);
            }
            if (i != 0 && i != height - 1 && j != 0 && j != width - 1) //middle pixel
            {
                image[i][j].rgbtRed = (int)round((float)(fimage[i + 1][j + 1].rgbtRed + fimage[i - 1][j - 1].rgbtRed + fimage[i - 1][j].rgbtRed +
                                                 fimage[i - 1][j + 1].rgbtRed + fimage[i][j - 1].rgbtRed + fimage[i][j].rgbtRed + fimage[i][j + 1].rgbtRed + fimage[i + 1][j -
                                                         1].rgbtRed + fimage[i + 1][j].rgbtRed) / (float)9);
                image[i][j].rgbtGreen = (int)round((float)(fimage[i + 1][j + 1].rgbtGreen + fimage[i - 1][j - 1].rgbtGreen + fimage[i -
                                                   1][j].rgbtGreen + fimage[i - 1][j + 1].rgbtGreen + fimage[i][j - 1].rgbtGreen + fimage[i][j].rgbtGreen + fimage[i][j + 1].rgbtGreen
                                                   + fimage[i + 1][j - 1].rgbtGreen + fimage[i + 1][j].rgbtGreen) / (float)9);
                image[i][j].rgbtBlue = (int)round((float)(fimage[i + 1][j + 1].rgbtBlue + fimage[i - 1][j - 1].rgbtBlue + fimage[i - 1][j].rgbtBlue
                                                  + fimage[i - 1][j + 1].rgbtBlue + fimage[i][j - 1].rgbtBlue + fimage[i][j].rgbtBlue + fimage[i][j + 1].rgbtBlue + fimage[i + 1][j -
                                                          1].rgbtBlue + fimage[i + 1][j].rgbtBlue) / (float)9);
            }
        }
    }









    return;
}
