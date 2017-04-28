#ifndef __HEIGHTS_H__
#define __HEIGHTS_H__

#include <stdlib.h> // Rand
#include <time.h> // time

typedef struct {
	int d;
	int minH;
	int maxH;
} MDAParameters;

void MDA(int d, int height, int length, int map[length]);

void MDASetHeight(MDAParameters p, int l, int r, int length, int map[length]);

unsigned int rand_interval(unsigned int min, unsigned int max);

#endif
