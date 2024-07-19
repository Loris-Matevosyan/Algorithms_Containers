#include <trees.h>



void check_Heaps() {
    
    check_Heap_constructor();
    check_Heap_copy();
    check_Heap_move();
    Heap_range_for_loop();

}



/*--------------Heap--------------*/


void check_Heap_constructor() 
{
    std::cout << "\n\n=============Heap=============\n" << std::endl;
    std::cout << "\n-----Heap Default constructor and overloaded constructor-----\n" << std::endl;

    Heap<int>  heapOne;
    Heap<int>  heapTwo{2, 5, 8, 11, 14};

    std::cout << "heapTwo contains: ";
    heapTwo.print();
}
    

void check_Heap_copy() 
{
    std::cout << "\n-----Heap Copy constructor and copy assignment operator-----\n" << std::endl;

    Heap<int> heapOne;
    Heap<int> heapTwo{1, 2, 3, 4, 5, 6};

    Heap<int> heapThree = heapTwo;
    heapOne = heapTwo;

    std::cout << "heapThree after copy constructing: ";
    heapThree.print();

    std::cout << "heapOne after copy assigning: ";
    heapOne.print();

}
    

void check_Heap_move() 
{
    std::cout << "\n-----Heap Move constructor and move assignment operator-----\n" << std::endl;
    
    Heap<int> heapOne;
    Heap<int> heapTwo{1, 2, 3, 4, 5, 6};
    Heap<int> heapThree(std::move(heapTwo));

    std::cout << "heapThree after move constructing: ";
    heapThree.print();

    heapOne = std::move(heapThree);

    std::cout << "heapOne after move assigning: ";
    heapOne.print();
}


void Heap_range_for_loop() 
{
    std::cout << "\n-----Heap Range for loop-----\n" << std::endl;

    Heap<int> heap{1, 2, 3, 4, 5, 6};

    for(auto el: heap)  
        std::cout << el << " ";

    // Or classic for loop ↓↓↓
    // for(auto it = heap.begin(); it != heap.end(); ++it)
    //     std::cout << *it << " ";
    
    std::cout << std::endl;
}

