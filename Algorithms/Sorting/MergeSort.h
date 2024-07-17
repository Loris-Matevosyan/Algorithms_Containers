/*          Merge Sort 
    -------Time Complexity-------- 
    Best case - Ω(nlogn)
    Average case - Θ(nlogn)
    Worst cas - O(nlogn)
    -------Space Complexity-------
    Best case - O(n) 
    Average case - O(n) 
    Worst case - O(n) 
    -----Stable Algorithm-----
*/

#ifndef _MERGESORT_
#define _MERGESORT_


class MergeSort 
{
    MergeSort() = default;
    MergeSort(const MergeSort& obj) = delete;
    MergeSort& operator=(const MergeSort& obj) = delete;

    static void merge(int array[], int leftIndex, int midIndex, int rightIndex) 
    {
        int leftArraySize = midIndex - leftIndex + 1;
        int rightArraySize = rightIndex - midIndex; 
        int leftArray[leftArraySize];
        int rightArray[rightArraySize];

        for( int i = 0; i < leftArraySize; ++i ) 
        {
            leftArray[i] = array[leftIndex + i];
        }
        
        for( int j = 0; j < rightArraySize; ++j ) 
        {
            rightArray[j] = array[midIndex + 1 + j];
        }

        int i = 0;
        int j = 0;
        int index = leftIndex;

        while( i < leftArraySize && j < rightArraySize ) 
        {
            if( leftArray[i] <= rightArray[j] ) 
            {
                array[index] = leftArray[i];
                ++index;
                ++i;
            } 
            else 
            {
                array[index] = rightArray[j];
                ++index;
                ++j;
            }
        }

        while( i < leftArraySize ) 
        {
            array[index] = leftArray[i];
            ++index;
            ++i;
        }

        while( j < rightArraySize ) 
        {
            array[index] = rightArray[j];
            ++index;
            ++j;
        }
    }

    static void mergeSort(int array[], int leftIndex, int rightIndex) 
    {
        if( leftIndex >= rightIndex )
            return;

        int midIndex = leftIndex + (rightIndex - leftIndex) / 2;

        mergeSort(array, leftIndex, midIndex);
        mergeSort(array, midIndex + 1, rightIndex);
        merge(array, leftIndex, midIndex, rightIndex);
    }

public:

    static void sort(int array[], int size) {
        mergeSort(array, 0, size - 1);
    }
};

#endif //_MERGESORT_