/*          Bubble Sort 
    -------Time Complexity-------- 
    Best case - Ω(n)
    Average case - Θ(n^2)
    Worst cas - O(n^2)
    -------Space Complexity-------
    Worst case - O(1) (constant)
    -----Stable Algorithm-----
*/

#ifndef _BUBBLESORT_    
#define _BUBBLESORT_ 

class BubbleSort {
    BubbleSort () = default;
    BubbleSort (const BubbleSort& obj) = delete;
    BubbleSort& operator=(const BubbleSort& obj) = delete;
public:
    static void sort(int array[], int size) {
        int temp;
        bool swapped;
        for (int i = size - 1; i > 0; --i) {
            swapped = false;
            for (int j = 0; j < i; ++j) {
                if (array[j] > array[j + 1]) {
                    //Can use one line without temp with #include <algorithm>
                    //std::swap(array[j], array[i]);
                    temp = array[j];
                    array[j] = array[j + 1];
                    array[j + 1] = temp;
                    //adding flag for exit the loop if array is sorted
                    swapped = true;
                }
            }
            if (!swapped)
                break;
        }
    }
    ~BubbleSort () noexcept = default;
};



#endif // _BUBBLESORT_ 