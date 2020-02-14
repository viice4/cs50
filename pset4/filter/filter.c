#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            double averege0 = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;
            int averege = round(averege0);
            image[i][j].rgbtBlue = averege;
            image[i][j].rgbtGreen = averege;
            image[i][j].rgbtRed = averege;
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
            int sepiaRed = round(.393 * image[i][j].rgbtRed 
            + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);
            int sepiaGreen = round(.349 * image[i][j].rgbtRed 
            + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);
            int sepiaBlue = round(.272 * image[i][j].rgbtRed 
            + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);
            
            if (sepiaRed <= 255)
            {
                image[i][j].rgbtRed = sepiaRed;
            }
            else
            {
                image[i][j].rgbtRed = 255;
            }
            if (sepiaGreen <= 255)
            {
                image[i][j].rgbtGreen = sepiaGreen;
            }
            else
            {
                image[i][j].rgbtGreen = 255;
            }
            if (sepiaBlue <= 255)
            {
                image[i][j].rgbtBlue = sepiaBlue;
            }
            else
            {
                image[i][j].rgbtBlue = 255;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < (width  - 1) / 2; j++)
        {
            int exBlue = image[i][j].rgbtBlue;
            int exGreen = image[i][j].rgbtGreen;
            int exRed = image[i][j].rgbtRed;
            image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
            image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
            image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;
            image[i][width - 1 - j].rgbtBlue = exBlue;
            image[i][width - 1 - j].rgbtGreen = exGreen;
            image[i][width - 1 - j].rgbtRed = exRed;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    image[0][0].rgbtBlue = round((image[0][0].rgbtBlue + image[0][1].rgbtBlue 
        + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 4.0);
    image[height - 1][0].rgbtBlue = round((image[height - 1][0].rgbtBlue + image[height - 1][1].rgbtBlue 
        + image[height - 2][0].rgbtBlue + image[height - 2][1].rgbtBlue) / 4.0);
    image[0][width - 1].rgbtBlue = round((image[0][width - 1].rgbtBlue + image[0][width - 2].rgbtBlue 
        + image[1][width - 1].rgbtBlue + image[1][width - 2].rgbtBlue) / 4.0);
    image[height - 1][width - 1].rgbtBlue = (image[height - 1][width - 1].rgbtBlue 
        + image[height - 1][width - 2].rgbtBlue + image[height - 2][width - 1].rgbtBlue 
        + image[height - 2][width - 2].rgbtBlue) / 4;
    
    for (int i = 1; i < height - 1; i++)
    {
        image[i][0].rgbtBlue = (image[i - 1][0].rgbtBlue + image[i - 1][1].rgbtBlue 
            + image[i][0].rgbtBlue + image[i][1].rgbtBlue + image[i + 2][0].rgbtBlue 
            + image[i + 2][1].rgbtBlue) / 6;
        image[i][0].rgbtGreen = (image[i - 1][0].rgbtGreen + image[i - 1][1].rgbtGreen 
            + image[i][0].rgbtGreen + image[i][1].rgbtGreen + image[i + 2][0].rgbtGreen 
            + image[i + 2][1].rgbtGreen) / 6;
        image[i][0].rgbtRed = (image[i - 1][0].rgbtRed + image[i - 1][1].rgbtRed 
            + image[i][0].rgbtRed + image[i][1].rgbtRed + image[i + 2][0].rgbtRed 
            + image[i + 2][1].rgbtRed) / 6;

        image[i][width - 1].rgbtBlue = (image[i - 1][width - 1].rgbtBlue + image[i - 1][width - 2].rgbtBlue 
            + image[i][width - 1].rgbtBlue + image[i][width - 2].rgbtBlue + image[i + 2][width - 1].rgbtBlue 
            + image[i + 2][width - 2].rgbtBlue) / 6;
        image[i][width - 1].rgbtGreen = (image[i - 1][width - 1].rgbtGreen + image[i - 1][width - 2].rgbtGreen 
            + image[i][width - 1].rgbtGreen + image[i][width - 2].rgbtGreen + image[i + 2][width - 1].rgbtGreen 
            + image[i + 2][width - 2].rgbtGreen) / 6;
        image[i][width - 1].rgbtRed = (image[i - 1][width - 1].rgbtRed + image[i - 1][width - 2].rgbtRed 
            + image[i][width - 1].rgbtRed + image[i][width - 2].rgbtRed + image[i + 2][width - 1].rgbtRed 
            + image[i + 2][width - 2].rgbtRed) / 6;
    }
    for (int i = 1; i < width - 1;i++)
    {
        image[0][i].rgbtBlue = (image[0][i - 1].rgbtBlue + image[0][i].rgbtBlue 
            + image[0][i + 1].rgbtBlue + image[1][i - 1].rgbtBlue + image[0][i].rgbtBlue 
            + image[0][i + 1].rgbtBlue) / 6;
        image[0][i].rgbtGreen = (image[0][i - 1].rgbtGreen + image[0][i].rgbtGreen 
            + image[0][i + 1].rgbtGreen + image[1][i - 1].rgbtGreen + image[0][i].rgbtGreen 
            + image[0][i + 1].rgbtGreen) / 6;
        image[0][i].rgbtRed = (image[0][i - 1].rgbtRed + image[0][i].rgbtRed 
            + image[0][i + 1].rgbtRed + image[1][i - 1].rgbtRed + image[0][i].rgbtRed 
            + image[0][i + 1].rgbtRed) / 6;

        image[height - 1][i].rgbtBlue = (image[height - 1][i - 1].rgbtBlue + image[height - 1][i].rgbtBlue 
            + image[height - 1][i + 1].rgbtBlue + image[height - 2][i - 1].rgbtBlue + image[height - 2][i].rgbtBlue 
            + image[height - 2][i + 1].rgbtBlue) / 6;
        image[height - 1][i].rgbtGreen = (image[height - 1][i - 1].rgbtGreen + image[height - 1][i].rgbtGreen 
            + image[height - 1][i + 1].rgbtGreen + image[height - 2][i - 1].rgbtGreen + image[height - 2][i].rgbtGreen 
            + image[height - 2][i + 1].rgbtGreen) / 6;
        image[height - 1][i].rgbtRed = (image[height - 1][i - 1].rgbtRed + image[height - 1][i].rgbtRed 
            + image[height - 1][i + 1].rgbtRed + image[height - 2][i - 1].rgbtRed + image[height - 2][i].rgbtRed 
            + image[height - 2][i + 1].rgbtRed) / 6;
    }

    for (int i = 1; i < height - 1; i++)
    {
        for (int j = 1; j < width - 1; j++)
        {
            image[i][j].rgbtBlue = (image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue + image[i][j - 1].rgbtBlue + image[i][j].rgbtBlue
                + image[i][j + 1].rgbtBlue + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue
                + image[i + 1][j + 1].rgbtBlue) / 9;
            image[i][j].rgbtGreen = (image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen + image[i][j - 1].rgbtGreen + image[i][j].rgbtGreen
                + image[i][j + 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen) / 9;
            image[i][j].rgbtRed = (image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed
                + image[i - 1][j + 1].rgbtRed + image[i][j - 1].rgbtRed + image[i][j].rgbtRed
                + image[i][j + 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed
                + image[i + 1][j + 1].rgbtRed) / 9;
        }
    }
    return;
}
