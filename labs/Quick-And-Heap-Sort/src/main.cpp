#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cmath>
#include <limits>
#include "heap_sort.h"
#include "quick_sort.h"
#include "timer.h"
#include "func.h"
#include "experiments.h"


template <class T>
T GetValidatedInput(const std::string& prompt, T min_val, T max_val)
{
	T value;
	while (true)
	{
		std::cout << prompt;

		if (std::cin >> value)
		{
			if (value >= min_val && value <= max_val)
			{
				return value;
			}
			else
			{
				std::cout << "Incorrect input! Value must be between " << min_val << " and " << max_val << std::endl;
			}
		}
		else
		{
			std::cout << "Incorrect input! Please enter a valid number" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}




class Interface
{

	static void Welcome()
	{	
		std::cout << "This program implements quicksort and heapsort." << std::endl;
	}

	static char SelectMode()
	{	
		std::cout << "Select the mode in which you want to work: U(user), E(experiments):" << std::endl;
		while(true)
		{	
			std::cout << "Mode: ";
			char mode;
			std::cin >> mode;
			if (mode != 'U' && mode != 'E')
			{
				std::cout << "Incorrect input!" << std::endl;
			}
			else
			{	
				return mode;
				break;
			}
		}

	}
	static void ExpMode()
	{	
		std::cout << "Select the experiment:" << std::endl;
		std::cout << "(1) q = 1; w = 10^9; n = 1, ... , 10^6 + 1 with step = 10^4" <<std::endl;
		std::cout << "(2) q = 1; w = 1, ... , 100 with step 1; n = 10^6" << std::endl;
		char experiment;
		while (true)
		{
			std::cout << "Experiment: ";
			std::cin >> experiment;
			if (experiment != '1' && experiment != '2')
			{
				std::cout << "Incorrect input!" << std::endl;
			}
			else
			{
				break;
			}
		}
		if (experiment == '1')
		{
			Experiment1(1, 1, 1'000'000 + 1, 10'000,
		"../../data/file_random_heap_sort1.txt", "../../data/file_random_quick_sort1.txt",
		"../../data/file_non_decrease_heap_sort1.txt", "../../data/file_non_decrease_quick_sort1.txt",
		"../../data/file_non_increase_heap_sort1.txt", "../../data/file_non_increase_quick_sort1.txt");
		}
		if (experiment == '2')
		{
			Experiment2(1, 1, 100, 1,
		"../../data/file_random_heap_sort2.txt", "../../data/file_random_quick_sort2.txt",
		"../../data/file_non_decrease_heap_sort2.txt", "../../data/file_non_decrease_quick_sort2.txt",
		"../../data/file_non_increase_heap_sort2.txt", "../../data/file_non_increase_quick_sort2.txt");
		}
	}
	static void UserMode()
	{
		std::cout << "Select the sorting you want: Q(quicksort), H(heapsort), B(both):" << std::endl;
		char sorting;
		while (true)
		{
			std::cout << "Sorting: ";
			std::cin >> sorting;
			if (sorting != 'Q' && sorting != 'H' && sorting != 'B')
			{
				std::cout << "Incorrect input!" << std::endl;
			}
			else
			{
				break;
			}
		}



		std::cout << "Select the array size: (1 <= n <= 1\'000\'000\'000)" << std::endl;
		const size_t MAX_SIZE = 1000000000ULL;
		size_t n = GetValidatedInput<size_t>("n = ", 1, MAX_SIZE);


		std::cout << "Select the lower bound of the array element values: (0 <= q <= 1\'000\'000\'000)" << std::endl;
		const uint32_t MAX_VALUE = 1000000000U;
		uint32_t q = GetValidatedInput<uint32_t>("q = ", 0, MAX_VALUE);


		std::cout << "Select the upper bound of the array element values: (q <= w <= 1\'000\'000\'000)" << std::endl;
		uint32_t w = GetValidatedInput<uint32_t>("w = ", q, MAX_VALUE);



		std::cout << "Select the array filling method: 1(Random), 2(Non-Decrease), 3(Non-Increase)" << std::endl;
		int filling;
		Filling_Method filling_method;
		while (true)
		{	
			std::cout << "Filling: ";
			std::cin >> filling;
			if (filling != 1 && filling != 2 && filling != 3)
			{
				std::cout << "Incorrect input!" << std::endl;
			}
			else
			{	
				if (filling == 1)
					filling_method = Filling_Method::RANDOM;
				else if (filling == 2)
					filling_method = Filling_Method::NON_DECREASE;
				else if (filling == 3)
					filling_method = Filling_Method::NON_INCREASE;
				break;
			}
		}


		bool print;
		std::cout << "Do you want to see unsorted and sorted arrays (not recommended for n >= 100\'000): (1/0)" << std::endl;
		std::cin >> print;

		system("cls");

		
		if (sorting == 'Q' || sorting == 'B')
		{	
			std::cout << "-------------------------------------------------------------------------" << std::endl;
			OneTimeExperiment(Sorting_Method::QUICK_SORT_ITERATIVE, filling_method, n, q, w, print, true, true);
			std::cout << "-------------------------------------------------------------------------" << std::endl;
		}
		if (sorting == 'H' || sorting == 'B')
		{	
			std::cout << "-------------------------------------------------------------------------" << std::endl;
			OneTimeExperiment(Sorting_Method::HEAP_SORT, filling_method, n, q, w, print, true, true);
			std::cout << "-------------------------------------------------------------------------" << std::endl;
		}
	}

	


public:
	static void Run()
	{
		Welcome();
		char selected_mode = SelectMode();
		if (selected_mode == 'U')
			UserMode();
		if (selected_mode == 'E')
			ExpMode();
	}
};









int main()
{	
	Interface::Run();


	/*size_t n = 100'000'000;

	double avg_time_rec = AvgTimeQuickSortRec(n, 10);

	info_about_sorting("Quick sort rec", n, avg_time_rec);


	double avg_time_iter = AvgTimeQuickSortIter(n, 10);

	info_about_sorting("Quick sort iter", n, avg_time_iter);*/
	/*std::vector<uint32_t>*/


	//double time = OneTimeExperiment(Sorting_Method::QUICK_SORT_ITERATIVE, Filling_Method::NON_DECREASE, 100'000, 0, 1'000'000'000, false ,true, true);

	

	/*std::ifstream in("file_random_heap_sort.txt");
	std::string line;

	char sep = ' ';

	if (in.is_open())
	{
		while (std::getline(in, line))
		{
			std::string str_n;
			std::string str_time;
			str_n = line.substr(0, line.find(' '));
			str_time = line.substr(line.find(' ') + 1);
			int n = std::stoi(str_n);
			double time = std::stod(str_time);

			double relation = double(n) * std::log(n) / time;
			std::cout << relation << std::endl;

		}
	}
	in.close();*/
}