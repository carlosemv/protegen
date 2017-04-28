#include "terrain.h"

void terrainGen()
{
	srand( (unsigned)time(NULL) );

	int heights[MAP_LENGTH];
	MDA(MAP_HEIGHT/2, MAP_HEIGHT, MAP_LENGTH, heights);
	makeImage(MAP_HEIGHT, MAP_LENGTH, heights, "i1.ppm");
	MDA(MAP_HEIGHT/2, MAP_HEIGHT, MAP_LENGTH, heights);
	makeImage(MAP_HEIGHT, MAP_LENGTH, heights, "i2.ppm");
	MDA(MAP_HEIGHT/2, MAP_HEIGHT, MAP_LENGTH, heights);
	makeImage(MAP_HEIGHT, MAP_LENGTH, heights, "i3.ppm");
}