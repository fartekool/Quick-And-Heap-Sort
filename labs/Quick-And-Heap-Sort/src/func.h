#pragma once
#include <string>
#include <fstream>
#include <random>






template <class T>
void Print_stdvector(const std::vector<T>& vec)
{
	std::cout << "{";
	if (vec.size() != 0)
		std::cout << vec[0];

	for (size_t i = 1; i < vec.size(); ++i)
		std::cout << ", " << vec[i];

	std::cout << "};";
	std::cout << '\n';
}
template <class T>
bool is_sorted(const std::vector<T>& arr)
{
	for (size_t i = 1; i < arr.size(); ++i)
	{
		if (arr[i - 1] > arr[i]) return false;
	}
	return true;
}

void fill_random_uint32_t(std::vector<uint32_t>& arr, size_t count, uint32_t left_border = 0, uint32_t right_border = UINT32_MAX)
{
	arr.clear();
	arr.reserve(count);
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> distrib(left_border, right_border);


	for (size_t i = 0; i < count; ++i)
		arr.push_back(distrib(gen));
}


void info_about_sorting(std::string name_of_sorting, size_t count, double time)
{
	std::cout << "Time of " << name_of_sorting << " sorting of " << count << " elements: " << time << "s" << std::endl;
}




