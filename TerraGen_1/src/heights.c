#include "heights.h"

void MDA(MDAParameters params, unsigned length, int map[length])
{
	map[0] = rand_interval(params.min_height, params.max_height);
	map[length-1] = rand_interval(params.min_height, params.max_height);

	MDASetHeight(params, 0, length-1, length, map);
}

void defaultMDA(unsigned height, unsigned length, int map[length])
{
	MDAParameters params;
	params.max_displacement = height/2;
	params.min_height = height/4;
	params.max_height = 3 * (height/4);

	MDA(params, length, map);
}

void MDASetHeight(MDAParameters params, unsigned l, unsigned r,
	unsigned length, int map[length])
{
	int mid = l + ((r - l) / 2);
	map[mid] = (map[l] + map[r]) / 2;

	int displaced, displacement;
	do {
		displacement = rand_interval(0, 2 * params.max_displacement) - params.max_displacement;
		displaced = map[mid] + displacement;
	} while (displaced < params.min_height || displaced > params.max_height);
	map[mid] = displaced;

	params.max_displacement /= 2;

	if (mid != (l+1)) {
		MDASetHeight(params, l, mid, length, map);
	}
	if (mid != (r-1)) {
		MDASetHeight(params, mid, r, length, map);
	}
}

unsigned rand_interval(unsigned min, unsigned max)
{
    int r;
    unsigned range = 1 + max - min;
    unsigned buckets = RAND_MAX / range;
    unsigned limit = buckets * range;

    do {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}