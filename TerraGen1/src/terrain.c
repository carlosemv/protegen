#include "terrain.h"

void terrainGen()
{
	srand((unsigned)time(NULL));

	int heights[MAP_LENGTH];
	defaultMDA(MAP_HEIGHT, MAP_LENGTH, heights);
	makeImage(MAP_HEIGHT, MAP_LENGTH, heights, "images/img1.ppm");
}