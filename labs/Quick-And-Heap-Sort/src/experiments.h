#pragma once
#include <fstream>
#include "func.h"
#include "heap_sort.h"
#include "quick_sort.h"
#include "timer.h"

enum class Filling_Method
{
	RANDOM,
	NON_DECREASE,
	NON_INCREASE
};
enum class Sorting_Method
{
	QUICK_SORT_RECURSIVE,
	QUICK_SORT_ITERATIVE,
	HEAP_SORT
};






//void f(size_t num_of_exp, size_t left_n, size_t right_n, size_t step, std::string file_name, Sorting_Method sort_method, Filling_Method fill_method)
//{
//
//	std::ofstream out;
//	bool is_open;
//	out.open(file_name);
//	out.clear();
//	is_open = out.is_open();
//	std::cout << std::boolalpha << "File " << file_name << " is open: " << is_open << std::endl;
//	if (is_open)
//	{
//		int percent = 10;
//		for (size_t length = left_n; length <= right_n; length += step)
//		{
//
//			double avg_time = 0;
//			for (size_t i = 0; i < num_of_exp; ++i)
//			{
//				avg_time += OneTimeExperiment(sort_method, fill_method, length, q, w, false, false, false);
//			}
//			avg_time /= num_of_exp;
//			out << length << ' ' << avg_time << 's' << std::endl;
//			if ((double(length) / double(right_n - left_n)) * 100 > percent)
//			{
//				std::cout << percent << "%\n";
//				percent += 10;
//			}
//		}
//	}
//	out.close();
//	std::cout << "File " << file_random_heap_sort << " is closed." << std::endl;
//}



double OneTimeExperiment(Sorting_Method sort_method, Filling_Method fill_method, size_t size, size_t q, size_t w, bool print_vec, bool check_sorting, bool print_time)
{	
	if (q > w) return double(-1);

	std::vector<uint32_t> vec;
	std::string filling_name;


	if (fill_method == Filling_Method::RANDOM)
	{
		fill_random_uint32_t(vec, size, q, w);
		filling_name = "RANDOM";
	}
	size_t q_ = q;
	size_t w_ = w;
	if (fill_method == Filling_Method::NON_DECREASE)
	{
		vec.reserve(size);
		for (size_t i = 0; i < size; ++i)
		{	
			if (q < w)
			{
				vec.push_back(q++);
			}
			else
			{
				vec.push_back(w);
			}
		}
		filling_name = "NON_DECREASE";
	}
	if (fill_method == Filling_Method::NON_INCREASE)
	{
		vec.reserve(size);
		for (size_t i = 0; i < size; ++i)
		{	
			if (q < w)
			{
				vec.push_back(w--);
			}
			else
			{
				vec.push_back(q);
			}
		}
		filling_name = "NON_INCREASE";
	}
	if (print_vec)
	{	
		std::cout << "Generated vector:\n";
		Print_stdvector(vec);
		std::cout << "\n\n";
	}




	double time;
	std::string sorting_name;
	if (sort_method == Sorting_Method::QUICK_SORT_RECURSIVE)
	{
		time = Timer(Quick_Sort<uint32_t>, vec, 0, vec.size() - 1);
		sorting_name = "QUICK_SORT_RECURSIVE";
	}
	if (sort_method == Sorting_Method::QUICK_SORT_ITERATIVE)
	{
		time = Timer(Quick_Sort_Iterative<uint32_t>, vec, 0, vec.size() - 1);
		sorting_name = "QUICK_SORT_ITERATIVE";
	}
	if (sort_method == Sorting_Method::HEAP_SORT)
	{
		time = Timer(Sort_3<uint32_t>, vec);
		sorting_name = "HEAP_SORT";
	}

	

	if (print_time)
	{
		std::cout << "Vector length: " << size << std::endl;
		std::cout << "Range of values: [" << q_ << "; " << w_ << "]" << std::endl;
		std::cout << "Sorting method: " << sorting_name << std::endl;
		std::cout << "Filling method: " << filling_name << std::endl;
		std::cout << "Sorting time: " << time << "s" << "\n\n\n";
	}


	if (print_vec)
	{
		std::cout << "Sorted vector:\n";
		Print_stdvector(vec);
		std::cout << "\n\n";
	}

	if (check_sorting)
	{
		std::cout << "Is the vector sorted?: " << std::boolalpha << is_sorted(vec) << "\n\n";
	}
	return time;
}




void Experiment1(size_t num_of_exp, size_t left_n, size_t right_n, size_t step, 
	std::string file_random_heap_sort, std::string file_random_quick_sort, 
	std::string file_non_decrease_heap_sort, std::string file_non_decrease_quick_sort,
	std::string file_non_increase_heap_sort, std::string file_non_increase_quick_sort)
{	
	uint32_t q = 1;
	uint32_t w = 1'000'000'000;
	std::ofstream out;
	bool is_open;



	// 1. Random Heap Sort
	out.open(file_random_heap_sort);
	out.clear();
	is_open = out.is_open();
	std::cout << std::boolalpha << "File " <<  file_random_heap_sort << " is open: " << is_open << std::endl;
	if (is_open)
	{
		int percent = 10;
		for (size_t length = left_n; length <= right_n; length += step)
		{

			double avg_time = 0;
			for (size_t i = 0; i < num_of_exp; ++i)
			{
				avg_time += OneTimeExperiment(Sorting_Method::HEAP_SORT, Filling_Method::RANDOM, length, q, w, false, false, false);
			}
			avg_time /= num_of_exp;
			out << length << ' ' << avg_time << std::endl;
			if ((double(length) / double(right_n - left_n)) * 100 > percent)
			{
				std::cout << percent << "%\n";
				percent += 10;
			}
		}
	}
	out.close();
	std::cout << "File " << file_random_heap_sort << " is closed." << std::endl;





	// 2. Random Quick Sort
	out.open(file_random_quick_sort);
	out.clear();
	is_open = out.is_open();
	std::cout << std::boolalpha << "File " << file_random_quick_sort << " is open: " << is_open << std::endl;
	if (is_open)
	{
		int percent = 10;
		for (size_t length = left_n; length <= right_n; length += step)
		{

			double avg_time = 0;
			for (size_t i = 0; i < num_of_exp; ++i)
			{
				avg_time += OneTimeExperiment(Sorting_Method::QUICK_SORT_ITERATIVE, Filling_Method::RANDOM, length, q, w, false, false, false);
			}
			avg_time /= num_of_exp;
			out << length << ' ' << avg_time << std::endl;
			if ((double(length) / double(right_n - left_n)) * 100 > percent)
			{
				std::cout << percent << "%\n";
				percent += 10;
			}
		}
	}
	out.close();
	std::cout << "File " << file_random_quick_sort << " is closed." << std::endl;


	// 3. Non-Decrease Heap Sort
	out.open(file_non_decrease_heap_sort);
	out.clear();
	is_open = out.is_open();
	std::cout << std::boolalpha << "File " << file_non_decrease_heap_sort << " is open: " << is_open << std::endl;
	if (is_open)
	{
		int percent = 10;
		for (size_t length = left_n; length <= right_n; length += step)
		{

			double avg_time = 0;
			for (size_t i = 0; i < num_of_exp; ++i)
			{
				avg_time += OneTimeExperiment(Sorting_Method::HEAP_SORT, Filling_Method::NON_DECREASE, length, q, w, false, false, false);
			}
			avg_time /= num_of_exp;
			out << length << ' ' << avg_time << std::endl;
			if ((double(length) / double(right_n - left_n)) * 100 > percent)
			{
				std::cout << percent << "%\n";
				percent += 10;
			}
		}
	}
	out.close();
	std::cout << "File " << file_non_decrease_heap_sort << " is closed." << std::endl;




	// 4. Non-Decrease Quick Sort
	out.open(file_non_decrease_quick_sort);
	out.clear();
	is_open = out.is_open();
	std::cout << std::boolalpha << "File " << file_non_decrease_quick_sort << " is open: " << is_open << std::endl;
	if (is_open)
	{
		int percent = 10;
		for (size_t length = left_n; length <= right_n; length += step)
		{

			double avg_time = 0;
			for (size_t i = 0; i < num_of_exp; ++i)
			{
				avg_time += OneTimeExperiment(Sorting_Method::QUICK_SORT_ITERATIVE, Filling_Method::NON_DECREASE, length, q, w, false, false, false);
			}
			avg_time /= num_of_exp;
			out << length << ' ' << avg_time << std::endl;
			if ((double(length) / double(right_n - left_n)) * 100 > percent)
			{
				std::cout << percent << "%\n";
				percent += 10;
			}
		}
	}
	out.close();
	std::cout << "File " << file_non_decrease_quick_sort << " is closed." << std::endl;



	// 5. Non-Increase Heap Sort
	out.open(file_non_increase_heap_sort);
	out.clear();
	is_open = out.is_open();
	std::cout << std::boolalpha << "File " << file_non_increase_heap_sort << " is open: " << is_open << std::endl;
	if (is_open)
	{
		int percent = 10;	
		for (size_t length = left_n; length <= right_n; length += step)
		{

			double avg_time = 0;
			for (size_t i = 0; i < num_of_exp; ++i)
			{
				avg_time += OneTimeExperiment(Sorting_Method::HEAP_SORT, Filling_Method::NON_INCREASE, length, q, w, false, false, false);
			}
			avg_time /= num_of_exp;
			out << length << ' ' << avg_time << std::endl;
			if ((double(length) / double(right_n - left_n)) * 100 > percent)
			{
				std::cout << percent << "%\n";
				percent += 10;
			}
		}
	}
	out.close();
	std::cout << "File " << file_non_increase_heap_sort << " is closed." << std::endl;





	// 6. Non-Increase Quick Sort
	out.open(file_non_increase_quick_sort);
	out.clear();
	is_open = out.is_open();
	std::cout << std::boolalpha << "File " << file_non_increase_quick_sort << " is open: " << is_open << std::endl;
	if (is_open)
	{
		int percent = 10;
		for (size_t length = left_n; length <= right_n; length += step)
		{

			double avg_time = 0;
			for (size_t i = 0; i < num_of_exp; ++i)
			{
				avg_time += OneTimeExperiment(Sorting_Method::QUICK_SORT_ITERATIVE, Filling_Method::NON_INCREASE, length, q, w, false, false, false);
			}
			avg_time /= num_of_exp;
			out << length << ' ' << avg_time << std::endl;
			if ((double(length) / double(right_n - left_n)) * 100 > percent)
			{
				std::cout << percent << "%\n";
				percent += 10;
			}
		}
	}
	out.close();
	std::cout << "File " << file_non_increase_quick_sort << " is closed." << std::endl;
}
