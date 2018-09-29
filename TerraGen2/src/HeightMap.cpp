#include "HeightMap.h"

HeightMap::HeightMap(int _sz, int _heightRange) :
	size(_sz),
	heightRange(_heightRange),
	map(nullptr)
{
	if (_sz <= 0)
		throw std::invalid_argument("[HeightMap()]: Invalid size\n");
	if (_heightRange <= 0)
		throw std::invalid_argument("[HeightMap()]: Invalid maximum height\n");

	map = std::make_unique<int[]>(_sz * _sz);

	std::random_device rd;
	generator.seed(rd());
}

int HeightMap::uniform(int min, int max)
{
	std::uniform_int_distribution<> unif(min, max);
	return unif(generator);
}

void HeightMap::genWithDSA()
{
	getMapAt(0, 0) = uniform(-heightRange/2, heightRange/2);
	getMapAt(0, size-1) = uniform(-heightRange/2, heightRange/2);
	getMapAt(size-1, 0) = uniform(-heightRange/2, heightRange/2);
	getMapAt(size-1, size-1) = uniform(-heightRange/2, heightRange/2);

	diamondSquare(size-1, heightRange * INIT_VAR_FACTOR);
}

void HeightMap::diamondSquare(int step, int variation)
{
	if (step <= 1)
		return;
	int hstep = step/2;

	// diamonds
	int a, b, c, d;
	for (unsigned i = hstep; i < size-1; i += step)
	{
		for (unsigned j = hstep; j < size-1; j += step)
		{
			a = getMapAt(i-hstep, j-hstep);
			b = getMapAt(i-hstep, j+hstep);
			c = getMapAt(i+hstep, j-hstep);
			d = getMapAt(i+hstep, j+hstep);

			getMapAt(i, j) = ((a+b+c+d)/4) + 
				uniform(-variation, variation);
		}
	}

	//squares
	int offset = 0;
	for (unsigned i = 0; i < size; i += hstep)
	{
		// flip between hstep and 0 offset for each line
		offset = (offset == 0) ? hstep : 0;
		for (unsigned j = offset; j < size; j += step)
		{
			a = (i != 0) ? getMapAt(i-hstep, j) : 0;
			b = (j != 0) ? getMapAt(i, j-hstep) : 0;
			c = (j != size-1) ? getMapAt(i, j+hstep) : 0;
			d = (i != size-1) ? getMapAt(i+hstep, j) : 0;

			if (i == 0 || j == 0 || i == size-1 || j == size-1) {
				getMapAt(i, j) = ((a+b+c+d)/3) + 
					uniform(-variation, variation);
			}
			else {
				getMapAt(i, j) = ((a+b+c+d)/4) + 
					uniform(-variation, variation);
			}
		}
	}

	diamondSquare(hstep, variation * VAR_REDUCTION_FACTOR);
}

bool HeightMap::makePPM(std::string _filename) const
{
	std::string extension(".ppm");
	if ( !(extension.size() <= _filename.size()) ||
		!std::equal(extension.rbegin(), extension.rend(), _filename.rbegin()) )
	{
		_filename += ".ppm";
	}

	std::ofstream out(_filename.c_str());
	if (!out.is_open())
	{
		std::cerr << std::endl
			<< "[HeightMap::makePPM()]: output file cannot be created."
			<< std::endl;
		return false;
	}

	out << "P3\n";
	out << size << " " << size << std::endl;
	out << "255\n";

	auto map_ptr = map.get();
	for (unsigned i = 0; i < size; ++i)
	{
		for (unsigned j = 0; j < size; ++j) {
			Pixel p = getColor(*map_ptr++, heightRange);
			out << (unsigned)p.r << " "
				<< (unsigned)p.g << " "
				<< (unsigned)p.b << "\n";		 
		}
	}

	out.close();
	return true;
}

HeightMap::Pixel HeightMap::getColor(int height, int heightRange)
{
	int n_terrains = (int)Terrain::N_TERRAINS;
	int terrainSize = heightRange / n_terrains;

	int terrain = (height + (heightRange/2)) / terrainSize;
	if (terrain < 0)
		terrain = 0;
	else if (terrain >= n_terrains)
		terrain = n_terrains - 1;

	return COLOR_MAP[terrain];
}