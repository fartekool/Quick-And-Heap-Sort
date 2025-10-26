#pragma once
#include <chrono>
#include "quick_sort.h"
#include "func.h"
template <class Func, class... Args>
double Timer(Func function, Args&&... args)
{
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    function(std::forward<Args>(args)...);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    auto time = end - start;
    return std::chrono::duration_cast<std::chrono::duration<double>>(time).count();
}


double AvgTimeQuickSortRec(size_t size_of_vector, size_t count_of_exp)
{   
    std::vector<uint32_t> dummy_vec;
    fill_random_uint32_t(dummy_vec, size_of_vector);
    Timer(Quick_Sort<uint32_t>, dummy_vec, 0, dummy_vec.size() - 1);


    double avg_time = 0;
    for (size_t i = 0; i < count_of_exp; ++i)
    {
        std::vector<uint32_t> vec;
        fill_random_uint32_t(vec, size_of_vector);
        //Print_stdvector(vec);
        double time = Timer(Quick_Sort<uint32_t>, vec, 0, vec.size() - 1);
        std::cout << (i+1) << ". " << time << std::endl;
        avg_time += time;
    }
    return avg_time / double(count_of_exp);

}

double AvgTimeQuickSortIter(size_t size_of_vector, size_t count_of_exp)
{

    std::vector<uint32_t> dummy_vec;
    fill_random_uint32_t(dummy_vec, size_of_vector);
    Timer(Quick_Sort<uint32_t>, dummy_vec, 0, dummy_vec.size() - 1);


    double avg_time = 0;
    for (size_t i = 0; i < count_of_exp; ++i)
    {
        std::vector<uint32_t> vec;
        fill_random_uint32_t(vec, size_of_vector);
        //Print_stdvector(vec);
        double time = Timer(Quick_Sort_Iterative<uint32_t>, vec, 0, vec.size() - 1);
        std::cout << (i + 1) << ". " << time << std::endl;
        avg_time += time;
    }
    return avg_time / double(count_of_exp);

}