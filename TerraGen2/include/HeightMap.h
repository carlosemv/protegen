/**
 * Author: Carlos Vieira
 * Date: April 27th, 2017
 * */

#ifndef _HEIGHT_MAP_H_
#define _HEIGHT_MAP_H_

#include <iostream>
#include <stdexcept>
#include <memory>
#include <random>
#include <string>
#include <fstream>

class HeightMap
{
protected:
	struct Pixel{
		unsigned char r, g, b;
	};

	enum class Terrain {
		DEEP_OCEAN = 0,
		MID_OCEAN,
		SHALLOW_OCEAN,
		SAND,
		LIGHT_VEGETATION,
		DENSE_VEGETATION,
		ROCKY,
		MOUNTAIN,
		MOUNTAIN_TOP,
		N_TERRAINS
	};

	static constexpr Pixel COLOR_MAP[(size_t)Terrain::N_TERRAINS] = {
		{0, 0, 153},
		{0, 77, 204},
		{0, 153, 255},
		{248, 248, 153},
		{45, 191, 35},
		{6, 115, 5},
		{175, 175, 175},
		{111, 111, 111},
		{248, 248, 248}
	};

	static constexpr int MAX_SIZE = 1025;
	static constexpr int HEIGHT_RANGE = 90;
	static constexpr double INIT_VAR_FACTOR = 0.75;
	static constexpr double VAR_REDUCTION_FACTOR = 0.55;

	int size;
	int heightRange;
	std::unique_ptr<int[]> map;
	std::mt19937 generator;

	int& getMapAt(int x, int y) { return map.get()[x*size+y]; }
	const int& getMapAt(int x, int y) const { return map.get()[x*size+y]; }
	int uniform(int min, int max);
	Pixel getColor(int height, int heightRange) const;

public:
	HeightMap(int _sz = MAX_SIZE, int _heightRange = HEIGHT_RANGE);
	HeightMap(HeightMap& hp) = delete;
	virtual ~HeightMap() {}
	void genWithDSA();
	void diamondSquare(int step, int variation);
	bool makePPM(std::string _filename) const;
};

#endif