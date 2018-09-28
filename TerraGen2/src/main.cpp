#include <iostream>
#include <chrono>
#include "HeightMap.h"

int main()
{
	auto start = std::chrono::steady_clock::now();
	auto m = HeightMap();
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;

	std::cout << "Construction: \n";
	std::cout << std::chrono::duration <double, std::milli> (diff).count();
	std::cout << " milliseconds\n" << std::endl;

	/*****************************/

	start = std::chrono::steady_clock::now();
	m.genWithDSA();
	end = std::chrono::steady_clock::now();
	diff = end - start;

	std::cout << "Generation: \n";
	std::cout << std::chrono::duration <double, std::milli> (diff).count();
	std::cout << " milliseconds\n" << std::endl;

	/*****************************/

	start = std::chrono::steady_clock::now();
	m.makePPM("terrain/i1.ppm");
	end = std::chrono::steady_clock::now();
	diff = end - start;

	std::cout << "Making file: \n";
	std::cout << std::chrono::duration <double, std::milli> (diff).count();
	std::cout << " milliseconds\n" << std::endl;

	return EXIT_SUCCESS;
}