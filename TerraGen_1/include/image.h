#ifndef __IMAGE_H__
#define __IMAGE_H__

#include <stdio.h> // printf

typedef struct {
	unsigned char r;
	unsigned char g;
	unsigned char b;
} Pixel;

typedef enum {
	WHITE,
	YELLOW,
	GREEN,
	LIGHT_BLUE,
	MID_BLUE,
	DARK_BLUE,
	PURPLE,
	RED,
	BLACK
} Color;

void makeImage(int height, int length, int map[length], char * filename);
void printImage(int height, int length, Pixel image[height][length], char * filename);
void setColor(Pixel *p, Color c);

#endif
