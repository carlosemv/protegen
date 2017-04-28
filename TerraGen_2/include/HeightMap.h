/**
 * Author: Carlos Vieira
 * Date: April 27th, 2017
 * */

#ifndef _HEIGHT_MAP_H_
#define _HEIGHT_MAP_H_

#include <iostream>
#include <stdexcept>
#include <random>
#include <string>
#include <fstream>

class HeightMap
{
protected:
	struct Pixel{
		unsigned char r, g, b;
	};
	static const int MAX_SIZE = 1025;
	static const int MAX_HEIGHT = 90;
	int size;
	int maxHeight;
	int** map;
	std::mt19937 generator;

	int uniform(int min, int max);
	Pixel getColor(int height, int maxHeight) const;

public:
	HeightMap(int _sz = MAX_SIZE, int _maxH = MAX_HEIGHT);
	virtual ~HeightMap();
	void genWithDSA();
	void diamondSquare(int step, int v);
	bool makePPM(std::string _filename) const;
};

#endif