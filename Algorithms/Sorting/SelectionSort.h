/*          Selection Sort 
    -------Time Complexity-------- 
    Best case - Ω(n^2)
    Average case - Θ(n^2)
    Worst cas - O(n^2)
    -------Space Complexity-------
    Worst case - O(1) (constant)
    -----Nonstable Algorithm-----
*/

#ifndef _SELECTIONSORT_
#define _SELECTIONSORT_


class SelectionSort 
{
    SelectionSort() = default;
    SelectionSort(const SelectionSort& obj) = delete;
    SelectionSort& operator=(const SelectionSort& obj) = delete;

public:

    static void sort(int array[], int size) 
    {
        int minIndex, temp;

        for( int i = 0; i < size; ++i ) 
        {
            minIndex = i;

            for( int j = i + 1; j < size; ++j ) 
            {
                if( array[minIndex] > array[j] ) 
                {
                    minIndex = j;
                }
            }
            
            if( i != minIndex ) 
            {
                //Can use one line without temp with #include <algorithm>
                //std::swap(array[i], array[minIndex]);
                temp = array[i];
                array[i] = array[minIndex];
                array[minIndex] = temp;
            }
        }
    } 

    ~SelectionSort() noexcept = delete;
};




#endif //_SELECTIONSORT_