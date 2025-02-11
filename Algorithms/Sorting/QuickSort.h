/*          Quick Sort 
    -------Time Complexity-------- 
    Best case - Ω(nlogn)
    Average case - Θ(nlogn)
    Worst case - O(n^2)
    -------Space Complexity-------
    Best case - O(logn) 
    Average case - O(logn) 
    Worst case - O(n) 
    -----Nonstable Algorithm-----
*/

#ifndef _QUICKSORT_ 
#define _QUICKSORT_


class QuickSort 
{
    QuickSort() = delete;
    QuickSort(const QuickSort& obj) = delete;
    QuickSort& operator=(const QuickSort& obj) = delete;

    // Swapping function
    static void swap(int array[], int firstIndex, int secondIndex) 
    {
        int temp = array[firstIndex];
        array[firstIndex] = array[secondIndex];
        array[secondIndex] = temp;
    }

    // Pivot - sorting and returning pivot index
    static int pivot(int array[], int pivotIndex, int endIndex)
    {
        int swapIndex = pivotIndex;

        for ( int i = pivotIndex + 1; i <= endIndex; ++i ) 
        {
            if( array[i] < array[pivotIndex] ) 
            {
                swapIndex++;
                swap(array, swapIndex, i);
            }
        }

        swap (array, pivotIndex, swapIndex);

        return swapIndex;
    }

    // Quick sorting
    static void quickSort(int array[], int leftIndex, int rightIndex) 
    {
        if (leftIndex >= rightIndex)
            return;

        int pivotIndex = pivot(array, leftIndex, rightIndex);

        quickSort(array, leftIndex, pivotIndex - 1);
        quickSort(array, pivotIndex + 1, rightIndex);
    }

public:

    static void sort(int array[], int size) 
    {
        quickSort(array, 0, size - 1);
    }

    ~QuickSort() noexcept  = default;
};

#endif //_QUICKSORT_