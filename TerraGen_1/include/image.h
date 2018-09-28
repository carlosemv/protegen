#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdio.h> // fprintf

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef enum {
	WHITE = 0,
	YELLOW,
	GREEN,
	LIGHT_BLUE,
	MID_BLUE,
	DARK_BLUE,
	PURPLE,
	RED,
	BLACK,
	N_COLORS
} Color;

static const Pixel color_map[N_COLORS] = {
	{255, 255, 255},
	{255, 255, 0},
	{0, 210, 0},
	{130, 130, 240},
	{15, 15, 100},
	{0, 0, 50},
	{80, 0, 160},
	{130, 20, 20},
	{0, 0, 0}
};

void makeImage(int height, int length, int map[length], char * filename);
void printImage(int height, int length, Pixel image[height][length], char * filename);

#endif
