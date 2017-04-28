#include "heights.h"

void MDA(int d, int height, int length, int map[length])
{
	MDAParameters p;
	p.d = d;
	p.minH = height/4;
	p.maxH = 3*(height/4);

	map[0] = rand_interval(p.minH, p.maxH);
	map[length-1] = rand_interval(p.minH, p.maxH);

	MDASetHeight(p, 0, length-1, length, map);
}

void MDASetHeight(MDAParameters p, int l, int r, int length, int map[length])
{
	int m = l + ((r - l) / 2);
	map[m] = (map[l] + map[r]) / 2;

	int altered = map[m];
	do {
		altered = map[m] + (rand_interval(0, 2 * p.d) - p.d);
	} while (altered < p.minH || altered > p.maxH);
	map[m] = altered;

	p.d /= 2;

	if (m != (l+1)) {
		MDASetHeight(p, l, m, length, map);
	}
	if (m != (r-1)) {
		MDASetHeight(p, m, r, length, map);
	}

}

unsigned int rand_interval(unsigned int min, unsigned int max)
{
    int r;
    unsigned int range = 1 + max - min;
    unsigned int buckets = RAND_MAX / range;
    unsigned int limit = buckets * range;

    do {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}