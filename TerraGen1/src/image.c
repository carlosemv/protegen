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
				// Terrain
				p = color_map[PURPLE];
			}
			else {
				// Sky
				p = color_map[LIGHT_BLUE];
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