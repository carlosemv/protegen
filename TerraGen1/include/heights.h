#ifndef __HEIGHTS_H__
#define __HEIGHTS_H__

#include <stdlib.h> // rand
#include <time.h> // time

typedef struct {
	/* Initial maximum height displacement
	 * for each point, either up or down */
	int max_displacement;
	// Minimum height for each point
	int min_height;
	// Maximum height for each point
	int max_height;
} MDAParameters;

// Apply midpoint displacement algorithm to fill 1d height array 'map'
void MDA(MDAParameters params, unsigned length, int map[length]);

/* MDA with 'default' parameters: heights in final map
 * will be between 1/4 of height and 3/4 of height; 
 * and max_displacement will be half of height. */
void defaultMDA(unsigned height, unsigned length, int map[length]);

// Auxiliary recursive function for MDA
void MDASetHeight(MDAParameters params, unsigned l, unsigned r,
	unsigned length, int map[length]);

// Utilitary function for random number uniformly sampled from [min, max]
unsigned rand_interval(unsigned min, unsigned max);

#endif
