#include "helpers.h"
#include <math.h>
#include <stdio.h>

int minValue(int lhs, int rhs);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            float red = pixel.rgbtRed;
            float green = pixel.rgbtGreen;
            float blue = pixel.rgbtBlue;
            float average = (red + green + blue) / 3.f;
            int roundedAverage = round(average);
            image[i][j].rgbtRed = roundedAverage;
            image[i][j].rgbtGreen = roundedAverage;
            image[i][j].rgbtBlue = roundedAverage;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = image[i][j];
            float red = pixel.rgbtRed;
            float green = pixel.rgbtGreen;
            float blue = pixel.rgbtBlue;

            image[i][j].rgbtRed = minValue(round(.393 * red + .769 * green + .189 * blue), 255);
            image[i][j].rgbtGreen = minValue(round(.349 * red + .686 * green + .168 * blue), 255);
            image[i][j].rgbtBlue = minValue(round(.272 * red + .534 * green + .131 * blue), 255);
        }
    }
}

int minValue(int lhs, int rhs)
{
    if (lhs > rhs)
    {
        return rhs;
    }
    else
    {
        return lhs;
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        // it is fine for us to assume that for odd numbers we will have smaller value
        int half_width = width / 2;

        for (int j = 0; j < half_width; j++)
        {
            RGBTRIPLE lhs_pixel = image[i][j];
            image[i][j] = image[i][width - 1 - j];
            image[i][width - 1 - j] = lhs_pixel;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE pixel = copy[i][j];
            int red = 0;
            int green = 0;
            int blue = 0;
            int number_of_counted_pixels = 0;

            for (int k = 0; k < 3; k++)
            {
                int adjastent_i = i - 1 + k;
                if ((adjastent_i < 0) || (adjastent_i >= height))
                {
                    continue;
                }

                for (int l = 0; l < 3; l++)
                {
                    int adjastent_j = j - 1 + l;
                    if ((adjastent_j < 0) || (adjastent_j >= width))
                    {
                        continue;
                    }

                    RGBTRIPLE adjastent_pixel = copy[adjastent_i][adjastent_j];
                    red += adjastent_pixel.rgbtRed;
                    green += adjastent_pixel.rgbtGreen;
                    blue += adjastent_pixel.rgbtBlue;
                    number_of_counted_pixels++;
                }
            }

            float average_red = (float) red / number_of_counted_pixels;
            float average_green = (float) green / number_of_counted_pixels;
            float average_blue = (float) blue / number_of_counted_pixels;

            image[i][j].rgbtRed = round(average_red);
            image[i][j].rgbtGreen = round(average_green);
            image[i][j].rgbtBlue = round(average_blue);
        }
    }
}
