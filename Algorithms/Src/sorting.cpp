#include "Includes.h"
#include <iostream>
#include <utility>



void sorting() 
{
    vectorOfInt unsorted_numbers;
    vectorOfInt sorted_numbers;

    bool continue_sorting{true};
    [[maybe_unused]] int sorting_choice;
    [[maybe_unused]] long long int alg_duration;

    while(continue_sorting) {

        auto [unsorted_numbers, sorting_choice] = user_input();
        auto [sorted_numbers, alg_duration] = sorting_input(unsorted_numbers, sorting_choice);

        display_results(sorted_numbers, unsorted_numbers);
        used_algorithm(sorting_choice);

        algorithm_duration(alg_duration);
        continue_sorting = repeat();
    }

    std::cout << "Thank you for enjoying basic algorithms" << std::endl;
}


std::pair<vectorOfInt, int> sorting_input(vectorOfInt numbers_for_sorting, int sorting_choice) 
{
    timePoint start;
    timePoint end;  

    switch(sorting_choice) 
    {
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
        case 6: 
            start = time_now();
            HeapSort::sort(numbers_for_sorting.data(), numbers_for_sorting.size());
            end = time_now();
            break;
        default:
            break;
    }

    return std::make_pair(numbers_for_sorting, time_interval(end, start));
}


void print_numbers(const vectorOfInt& numbers, std::string_view text) 
{
    std::cout << text;
    for(const auto& el: numbers)
        std::cout << el << " ";
    std::cout << std::endl;
}


void display_results(const vectorOfInt& sorted, const vectorOfInt& unsorted) 
{
    print_numbers(unsorted, "Numbers before sorting: ");
    print_numbers(sorted, "Numbers after sorting: ");
}


void used_algorithm(int sorting_choice) 
{
    switch(sorting_choice) 
    {
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
        case 6: 
            std::cout << "Heap sorting algorithm have been used" << std::endl;
            break;
        default:
            break;
    }
}


void algorithm_duration(long long int duration) 
{
    std::cout << "Sorting time: " << duration << " nanoseconds" << std::endl;
}

