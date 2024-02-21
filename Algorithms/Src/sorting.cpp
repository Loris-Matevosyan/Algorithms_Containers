#include "sorting.h"
#include "user_input.h"
#include "BubbleSort.h"
#include "SelectionSort.h"
#include "InsertionSort.h"
#include "QuickSort.h"
#include "MergeSort.h"
#include <iostream>
#include <utility>


void print(int arr[], int size) {
    for(int i = 0; i < size; ++i) 
        std::cout << arr[i] << " ";
    std::cout << std::endl;
}

void sorting() {
    bool continue_sorting{true};
    std::vector<int> numbers_for_sorting;
    //[[maybe_unused]] is C++17 feature
    [[maybe_unused]] int sorting_choice;
    std::pair<std::vector<int>, int> input_package;
    //[[maybe_unused]] is C++17 feature
    [[maybe_unused]] long long int alg_duration;
    while(continue_sorting) {
        /* Could be done easier and more efficient with structured binding (requires C++17)
        without previous initialization of vector and int 
        with only ↓↓↓ statement (CAUTION: current project will use pair further)*/
        //auto[numbers_for_sorting, sorting_choice] = userInput;
        input_package = userInput();
        numbers_for_sorting = input_package.first;
        sorting_choice = input_package.second;
        alg_duration = sorting_input(numbers_for_sorting, sorting_choice);
        results(numbers_for_sorting, input_package.first);
        used_algorithm(sorting_choice);
        algorithm_duration(alg_duration);
        continue_sorting = repeat();
    }
    std::cout << "Thank you for enjoying basic algorithms" << std::endl;
}

int sorting_input(std::vector<int>& numbers_for_sorting, int sorting_choice) {
    std::chrono::time_point<std::chrono::system_clock> start;
    std::chrono::time_point<std::chrono::system_clock> end;  
    switch(sorting_choice) {
        case 1: 
            start = time_now();
            BubbleSort::sort(numbers_for_sorting.data(), numbers_for_sorting.size());
            end = time_now();
            break;
        case 2: 
            start = time_now();
            SelectionSort::sort(numbers_for_sorting.data(), numbers_for_sorting.size());
            end = time_now();
            break;
        case 3: 
            start = time_now();
            InsertionSort::sort(numbers_for_sorting.data(), numbers_for_sorting.size());
            end = time_now();
            break;
        case 4: 
            start = time_now();
            QuickSort::sort(numbers_for_sorting.data(), numbers_for_sorting.size());
            end = time_now();
            break;
        case 5: 
            start = time_now();
            MergeSort::sort(numbers_for_sorting.data(), numbers_for_sorting.size());
            end = time_now();
            break;
        default:
            break;
    }
    return time_interval(end, start);
}

void results(std::vector<int> sorted, std::vector<int> unsorted) {
    std::cout << "Numbers before sorting: ";
    for(auto el: unsorted)
        std::cout << el << " ";
    std::cout << std::endl;
    std::cout << "Numbers after sorting: ";
    for(auto el: sorted)
        std::cout << el << " ";
    std::cout << std::endl;
}

void used_algorithm(int sorting_choice) {
    switch(sorting_choice) {
        case 1: 
            std::cout << "Bubble sorting algorithm have been used" << std::endl;
            break;
        case 2: 
            std::cout << "Selection sorting algorithm have been used" << std::endl;
            break;
        case 3: 
            std::cout << "Insertion sorting algorithm have been used" << std::endl;
            break;
        case 4: 
            std::cout << "Quick sorting algorithm have been used" << std::endl;
            break;
        case 5: 
            std::cout << "Merge sorting algorithm have been used" << std::endl;
            break;
        default:
            break;
    }
}

void algorithm_duration(long long int duration) {
    std::cout << "Sorting time: " << duration << " nanoseconds" << std::endl;
}
