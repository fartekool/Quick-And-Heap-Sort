#pragma once
#include <vector>
#include <algorithm>
#include <stack>





template <class T>
size_t median_of_three(std::vector<T>& arr, size_t p, size_t r)
{
    size_t mid = p + (r - p) / 2;

    if (arr[p] > arr[mid]) std::swap(arr[p], arr[mid]);
    if (arr[p] > arr[r])   std::swap(arr[p], arr[r]);
    if (arr[mid] > arr[r]) std::swap(arr[mid], arr[r]);

    std::swap(arr[mid], arr[r]);
    return r;
}








template <class T>
size_t Partition(std::vector<T>& arr, size_t p, size_t r)
{   
    if (r > p) {
        median_of_three(arr, p, r);
    }


    T x = arr[r];
    size_t i = p;
    for (size_t j = p; j < r; ++j)
    {
        if (arr[j] <= x)
        {
            std::swap(arr[i], arr[j]);
            ++i;
        }
    }
    std::swap(arr[i], arr[r]);
    return i;
}

template <class T>
void Quick_Sort(std::vector<T>& arr, size_t p, size_t r) // recursive version
{
    if (r == size_t(-1)) return;
    if (p < r)
    {
        size_t q = Partition(arr, p, r);
        Quick_Sort(arr, p, q - 1);
        Quick_Sort(arr, q + 1, r);
    }
}

template <class T>
void Quick_Sort_Iterative(std::vector<T>& arr, size_t p, size_t r)
{
    if (arr.size() < 2) return;

    std::stack<std::pair<size_t, size_t>> ranges;
    ranges.push({ p, r });  

    while (!ranges.empty())
    {
        size_t p_ = ranges.top().first;
        size_t r_ = ranges.top().second;
        ranges.pop();

        if (p_ < r_)
        {
            size_t q_ = Partition(arr, p_, r_);

            if (p_ < q_ && q_ != 0)
            {
                ranges.push({ p_, q_ - 1 });
            }

            if (q_ < r_)
            {
                ranges.push({ q_ + 1, r_ });
            }
        }
    }
}
