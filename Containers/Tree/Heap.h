#ifndef _HEAP_
#define _HEAP_


#include <iostream>
#include <initializer_list>
#include <vector>


template <typename T>
class Heap
{
    std::vector<T> heap;

    int leftChild(int index)
    {
        return (index * 2) + 1;
    }

    int rightChild(int index)
    {
        return (index * 2) + 2;
    }

    int parent(int index)
    {
        return (index - 1) / 2; 
    }

    void swap(int indexOne, int indexTwo)
    {
        int temp = heap[indexOne];
        heap[indexOne] = heap[indexTwo];
        heap[indexTwo] = temp;
    }

    void sinkDown(int index) 
    {
        int maxIndex = index;
        bool run = true;

        while( run )
        {
            long long unsigned int leftIndex = leftChild(index);
            long long unsigned int rightIndex = rightChild(index);

            if( leftIndex < heap.size() && heap[leftIndex] > heap[maxIndex] )
                maxIndex = leftIndex;

            if( rightIndex < heap.size() && heap[rightIndex] > heap[maxIndex] )
                maxIndex = rightIndex;

            if( maxIndex != index ) 
            {
                swap(index, maxIndex);

                index = maxIndex;
            }
            else
            {
                run = false;
            }
        }
    }

    void heapify() 
    {
        for( int index = (heap.size() / 2) - 1; index >= 0; --index )
        {
            sinkDown(index);
        }
    }

public:

    Heap() = default;
    Heap(std::initializer_list<T> theList) 
        : heap(theList)
    {
        heapify();
    }

    Heap(const Heap& object) = default;
    Heap(Heap&& object) = default;
    Heap& operator=(const Heap& right) = default;
    Heap& operator=(Heap&& right) = default;

    auto begin()
    {
        return heap.begin();
    }

    auto end()
    {
        return heap.end();
    }

    void print()
    {
        for(auto element: heap) 
            std::cout << element << " ";

        std::cout << std::endl;
    }
    
};



#endif //_HEAP_