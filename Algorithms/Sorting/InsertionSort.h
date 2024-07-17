/*         Insertion Sort 
    -------Time Complexity-------- 
    Best case - Ω(n)
    Average case - Θ(n^2)
    Worst cas - O(n^2)
    -------Space Complexity-------
    Worst case - O(1) (constant)
    -----Stable Algorithm-----
*/

#ifndef _INSERTIONSORT_
#define _INSERTIONSORT_


class InsertionSort 
{
    InsertionSort() = default;
    InsertionSort(const InsertionSort& obj) = delete;
    InsertionSort& operator=(const InsertionSort& obj) = delete;

public:

    static void sort(int array[], int size) 
    {
        int temp, j;

        for( int i = 1; i < size; ++i ) 
        {
            temp = array[i];
            j = i - 1;
            
            while( j >= 0 && array[j] > temp ) 
            {
                array[j + 1] = array[j];
                array[j] = temp;
                --j;
            }
        }
    }

    ~InsertionSort() noexcept = default;
};


#endif //_INSERTIONSORT_
