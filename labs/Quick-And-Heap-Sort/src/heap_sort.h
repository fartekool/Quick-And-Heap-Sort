#pragma once
#include <vector>
#include <algorithm>

template <class T>
class TreeHeap
{
    std::vector<T>& _data;
    size_t _heap_size;


    void siftUp(size_t i)
    {

        while (true)
        {
            if (i == 0) break;
            size_t parent_index = (i - 1) / 3;
            if (_data[parent_index] < _data[i])
            {
                std::swap(_data[parent_index], _data[i]);
                i = parent_index;
            }
            else
            {
                break;
            }
        }

    }
    void siftDown(size_t i)
    {

        while (true)
        {
            size_t c1 = 3 * i + 1;
            size_t c2 = 3 * i + 2;
            size_t c3 = 3 * i + 3;

            size_t biggest = i;

            if (c1 < _heap_size && _data[c1] > _data[biggest])
            {
                biggest = c1;
            }

            if (c2 < _heap_size && _data[c2] > _data[biggest])
            {
                biggest = c2;
            }

            if (c3 < _heap_size && _data[c3] > _data[biggest])
            {
                biggest = c3;
            }

            if (biggest != i)
            {
                std::swap(_data[i], _data[biggest]);

                i = biggest;
            }
            else
            {
                break;
            }
        }
    }

    void do_heap()
    {
        if (_heap_size < 2) return;

        for (size_t i = (_heap_size - 1) - 1 / 3; ; --i) // ÂÎÇÌÎÍÆÍÀ ÎØÈÁÊÀ, ÍÀÄÎ ÏÐÎÂÅÐÈÒÜ
        {
            siftDown(i);
            if (i == 0) break;
        }
    }
public:
    TreeHeap() : _heap_size(0) {}
    TreeHeap(std::vector<T>& data) : _data(data), _heap_size(data.size())
    {
        do_heap();
    }

    void extractAndSort()
    {
        if (_heap_size == 0) return;
        std::swap(_data[0], _data[_heap_size - 1]);
        --_heap_size;
        if (_heap_size > 1)
            siftDown(0);
    }
    /*friend std::ostream& operator<<(std::ostream& os, const TreeHeap& tree)
    {
        for (auto i : tree._data)
            os << i << ' ';
        return os;
    }*/

};

template <class T>
void Sort_3(std::vector<T>& arr)
{
    TreeHeap<T> heap(arr);
    //std::cout << "heap is built" << std::endl;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        heap.extractAndSort();
    }
}




