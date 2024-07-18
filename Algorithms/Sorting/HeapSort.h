/*          Heap Sort 
    -------Time Complexity-------- 
    Best case - Ω(nlogn)
    Average case - Θ(nlogn)
    Worst cas - O(nlogn)
    -------Space Complexity-------
    Best case - O(1) 
    Average case - O(1) 
    Worst case - O(1) 
    -----Nonstable Algorithm-----
*/

#ifndef _HEAPSORT_
#define _HEAPSORT_


class HeapSort
{
    HeapSort() = default;
    HeapSort(const HeapSort& obj) = delete;
    HeapSort& operator=(const HeapSort& obj) = delete;

    static int leftChild(int index)
    {
        return (index * 2) + 1;
    }

    static int rightChild(int index)
    {
        return (index * 2) + 2;
    }

    static void swap(int& numberOne, int& numberTwo)
    {
        int temp = numberOne;
        numberOne = numberTwo;
        numberTwo = temp;
    }
    
    static void heapify(int array[], int size, int index) 
    {
        int maxIndex = index;
        int leftIndex = leftChild(index);
        int rightIndex = rightChild(index);

        if( leftIndex < size && array[leftIndex] > array[maxIndex] )
            maxIndex = leftIndex;

        if( rightIndex < size && array[rightIndex] > array[maxIndex] )
            maxIndex = rightIndex;

        if( maxIndex != index ) 
        {
            swap(array[index], array[maxIndex]);

            heapify(array, size, maxIndex);
        }
    }

public:

    static void sort(int array[], int size) 
    {
        for( int i = size / 2 - 1; i >= 0; --i )
        {
            heapify(array, size, i);
        }

        for( int i = size - 1; i >= 0; --i ) 
        {
            swap(array[0], array[i]);

            heapify(array, i, 0);
        }
    }
};



#endif //_HEAPSORT_