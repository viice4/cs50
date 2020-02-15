#include <stdio.h>
#include <math.h>
#include <stdlib.h>
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
    if ((width % 2) == 0)
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < width / 2; j++)
            {
                int ecgBlue = image[i][j].rgbtBlue;
                int ecgGreen = image[i][j].rgbtGreen;
                int ecgRed = image[i][j].rgbtRed;

                image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
                image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
                image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;

                image[i][width - 1 - j].rgbtBlue = ecgBlue;
                image[i][width - 1 - j].rgbtGreen = ecgGreen;
                image[i][width - 1 - j].rgbtRed = ecgRed;
            }
        }
    }
    else
    {
        for (int i = 0; i < height; i++)
        {
            for (int j = 0; j < (width - 1) / 2; j++)
            {
                int ecgBlue = image[i][j].rgbtBlue;
                int ecgGreen = image[i][j].rgbtGreen;
                int ecgRed = image[i][j].rgbtRed;

                image[i][j].rgbtBlue = image[i][width - 1 - j].rgbtBlue;
                image[i][j].rgbtGreen = image[i][width - 1 - j].rgbtGreen;
                image[i][j].rgbtRed = image[i][width - 1 - j].rgbtRed;

                image[i][width - 1 - j].rgbtBlue = ecgBlue;
                image[i][width - 1 - j].rgbtGreen = ecgGreen;
                image[i][width - 1 - j].rgbtRed = ecgRed;
            }
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int image_cp[height][width][3];
    
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int count = 0;

            for (int h = -1; h < 2; h++)
            {
                for (int w = -1; w < 2; w++)
                {
                    if ((i + h) != -1 && (i + h) != height && (j + w) != -1 && (j + w) != width)
                    {
                        image_cp[i][j][0] += image[i + h][j + w].rgbtBlue;
                        image_cp[i][j][1] += image[i + h][j + w].rgbtGreen;
                        image_cp[i][j][2] += image[i + h][j + w].rgbtRed;
                        count++;
                    }
                }
            }

            image_cp[i][j][0] = (int)(round((float)(image_cp[i][j][0]) / count)) ;
            image_cp[i][j][1] = (int)(round((float)(image_cp[i][j][1]) / count));
            image_cp[i][j][2] = (int)(round((float)(image_cp[i][j][2]) / count));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = image_cp[i][j][0];
            image[i][j].rgbtGreen = image_cp[i][j][1];
            image[i][j].rgbtGreen = image_cp[i][j][2];
        }
    }
    return;
}
