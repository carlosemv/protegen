#include "HeightMap.h"

HeightMap::HeightMap(int _sz, int _maxH) :
	size(_sz),
	maxHeight(_maxH),
	map(nullptr)
{
	if (_sz <= 0)
		throw std::invalid_argument("[HeightMap()]: Invalid size\n");
	if (_maxH <= 0)
		throw std::invalid_argument("[HeightMap()]: Invalid maximum height\n");


	map = new int* [_sz];
	map[0] = new int [_sz * _sz];
	for (auto i = 1; i < _sz; ++i)
		map[i] = map[0] + i * _sz;

	std::random_device rd;
	generator.seed(rd());
}

HeightMap::~HeightMap()
{
	delete [] map[0];
	delete [] map;
}

int HeightMap::uniform(int min, int max)
{
	std::uniform_int_distribution<> unif(min, max);
	return unif(generator);
}

void HeightMap::genWithDSA()
{
	map[0][0] = uniform(-maxHeight/2, maxHeight/2);
	map[0][size-1] = uniform(-maxHeight/2, maxHeight/2);
	map[size-1][0] = uniform(-maxHeight/2, maxHeight/2);
	map[size-1][size-1] = uniform(-maxHeight/2, maxHeight/2);

	diamondSquare(size-1, maxHeight*0.75);
}

void HeightMap::diamondSquare(int step, int v)
{
	if (step <= 1)
		return;
	int hstep = step/2;

	// diamonds
	int a, b, c, d;
	for(int i = hstep; i < size-1; i += step)
	{
		for(int j = hstep; j < size-1; j += step)
		{
			a = map[i-hstep][j-hstep];
			b = map[i-hstep][j+hstep];
			c = map[i+hstep][j-hstep];
			d = map[i+hstep][j+hstep];

			map[i][j] = ((a+b+c+d)/4) + uniform(-v, v);
		}
	}

	//squares
	int offset = 0;
	for (int i = 0; i < size; i += hstep)
	{
		offset = (offset == 0) ? hstep : 0;
		for (int j = offset; j < size; j += step)
		{
			a = (i != 0) ? map[i-hstep][j] : 0;
			b = (j != 0) ? map[i][j-hstep] : 0;
			c = (j != size-1) ? map[i][j+hstep] : 0;
			d = (i != size-1) ? map[i+hstep][j] : 0;

			if (i==0||j==0||i==size-1||j==size-1)
				map[i][j] = ((a+b+c+d)/3) + uniform(-v, v);
			else
				map[i][j] = ((a+b+c+d)/4) + uniform(-v, v);
		}
	}


	diamondSquare(hstep, v*0.55);
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

	for (auto i = 0; i < size; ++i)
	{
		for (auto j = 0; j < size; ++j) {
			Pixel p = getColor(map[i][j], maxHeight);
			out << (int)p.r << " "
				<< (int)p.g << " "
				<< (int)p.b << "\n";		 
		}
	}

	out.close();
	return true;
}

HeightMap::Pixel HeightMap::getColor(int height, int maxHeight) const
{
	Pixel p;
	int pieceSz = (maxHeight*2) / 9;
	if(height < pieceSz-maxHeight) {
		p.r = 0; p.g = 0; p.b = 153; // deep ocean
	}
	else if (height < (2*pieceSz)-maxHeight) {
		p.r = 0; p.g = 77; p.b = 204; // mid ocean
	}
	else if (height < (3*pieceSz)-maxHeight) {
		p.r = 0; p.g = 153; p.b = 255; // shallow ocean
	}
	else if (height < (4*pieceSz)-maxHeight) {
		p.r = 248; p.g = 248; p.b = 153; // sand
	}
	else if (height < (5*pieceSz)-maxHeight) {
		p.r = 45; p.g = 191; p.b = 35; // light vegetation
	}
	else if (height < (6*pieceSz)-maxHeight) {
		p.r = 6; p.g = 115; p.b = 5; // dense vegetation
	}
	else if (height < (7*pieceSz)-maxHeight) {
		p.r = 175; p.g = 175; p.b = 175; // rocky
	}
	else if (height < (8*pieceSz)-maxHeight) {
		p.r = 111; p.g = 111; p.b = 111; // mountain
	}
	else {
		p.r = 248; p.g = 248; p.b = 248; // mountain top
	}

	return p;
}