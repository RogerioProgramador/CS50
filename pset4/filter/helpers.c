#include "helpers.h"
#include <math.h>
#include <stdlib.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
	int i;
	int j;
	double color;

	i = 0;
	j = 0;
	while (i < height)
	{
		color = ((double)(image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3);
		image[i][j].rgbtRed = round(color);
		image[i][j].rgbtGreen = round(color);
		image[i][j].rgbtBlue = round(color);
		j++;
		if (j == width)
		{
			i++;
			j = 0;
		}
	}
	return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
	int i;
	int j;
	double sepiaRed;
	double sepiaGreen;
	double sepiaBlue;

	i = 0;
	j = 0;
	while (i < height)
	{
		sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
		sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
		sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
		image[i][j].rgbtRed = (round(sepiaRed) > 255) ? 255:round(sepiaRed);
		image[i][j].rgbtGreen = (round(sepiaGreen) > 255) ? 255:round(sepiaGreen);
		image[i][j].rgbtBlue = (round(sepiaBlue) > 255) ? 255:round(sepiaBlue);
		j++;
		if (j == width)
		{
			i++;
			j = 0;
		}
	}
	return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
	int i;
	int j;
	int k;
	int l;
	RGBTRIPLE tmp;
	i = 0;
	j = 0;
	k = width - 1;
	l = width / 2;
	while (i < height)
	{
		while (l > 0)
		{
			tmp = image[i][j];
			image[i][j] = image[i][k];
			image[i][k] = tmp;
			k--;
			j++;
			l--;
		}
		i++;
		j = 0;
		k = width - 1;
		l = width / 2;
	}
	return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
	//Variables;
	int i;
	int j;
	int k;
	int l;
	int divisor;
	double avgRed;
	double avgGreen;
	double avgBlue;
	RGBTRIPLE copy[height][width];

	i = 0;
	j = 0;
	k = 0;
	l = 0;
	//Loop to give new values to the pixels
	while (k < height)
	{
		i = 0;
		j = 0;
		divisor = 0;

		avgRed = 0;
		avgGreen = 0;
		avgBlue = 0;
		while (abs(i - k) <= 1)
		{
			if (i == k && j == l)
				j++;
			else
			{
				if (abs(i - k) <= 1 && abs(j - l) <= 1 )
				{
					avgRed += image[i][j].rgbtRed;
					avgGreen += image[i][j].rgbtGreen;
					avgBlue += image[i][j].rgbtBlue;
					divisor++;
				}
				j++;
				if (abs(j - l) > 1)
				{
					i++;
					j = 0;
				}
			}

		}

		if (divisor != 0)
		{
			avgRed = round(avgRed / (double)divisor);
			avgGreen = round(avgGreen / (double)divisor);
			avgBlue = round(avgBlue / (double)divisor);
			copy[k][l].rgbtRed = avgRed;
			copy[k][l].rgbtGreen = avgGreen;
			copy[k][l].rgbtBlue = avgBlue;
		}

		l++;
		if (l == width)
		{
			k++;
			l = 0;
		}
	}
	i = 0;
	j = 0;
	//Copying into image
	while (i < height)
	{
		image[i][j] = copy[i][j];
		j++;
		if (j == width)
		{
			i++;
			j = 0;
		}
	}
	return ;
}
