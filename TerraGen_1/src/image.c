#include "image.h"

void makeImage(int height, int length, int map[length], char * filename)
{
	Pixel image[height][length];

	int i, j;
	Pixel p;
	for (i = 0; i < height; ++i)
	{
		for (j = 0; j < length; ++j)
		{
			if (i >= (height-map[j])) {
				// Mountain
				setColor(&p, PURPLE);
			}
			else {
				// Sky
				setColor(&p, LIGHT_BLUE);
			}
			image[i][j] = p;
		}
	}

	printImage(height, length, image, filename);
}

void printImage(int height, int length, Pixel image[height][length], char * filename)
{
	FILE *fp;

	fp = fopen(filename, "w");
	fprintf(fp, "P3\n");
	fprintf(fp, "%i %i\n", length, height);
	fprintf(fp, "255\n");

	int i, j;
	for (i = 0; i < height; ++i)
	{
		for (j = 0; j < length; ++j)
		{
			fprintf(fp, "%hhu ", image[i][j].r);
			fprintf(fp, "%hhu ", image[i][j].g);
			fprintf(fp, "%hhu\n", image[i][j].b);
		}
	}

	fclose(fp);
}

void setColor(Pixel *p, Color c)
{
	switch (c)
	{
		case WHITE:
			(*p).r = 255; (*p).g = 255; (*p).b = 255;
			break;
		case YELLOW:
			(*p).r = 255; (*p).g = 255; (*p).b = 0;
			break;
		case GREEN:
			(*p).r = 0; (*p).g = 210; (*p).b = 0;
			break;
		case LIGHT_BLUE:
			(*p).r = 130; (*p).g = 130; (*p).b = 240;
			break;
		case MID_BLUE:
			(*p).r = 15; (*p).g = 15; (*p).b = 100;
			break;
		case DARK_BLUE:
			(*p).r = 0; (*p).g = 0; (*p).b = 50;
			break;
		case PURPLE:
			(*p).r = 80; (*p).g = 0; (*p).b = 160;
			break;
		case RED:
			(*p).r = 130; (*p).g = 20; (*p).b = 20;
			break;
		default:
			(*p).r = 0; (*p).g = 0; (*p).b = 0;
	}
}