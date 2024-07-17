#ifndef _SORTING_
#define _SORTING_

#include <vector>
#include <string_view>
#include <chrono>

using vectorOfInt = std::vector<int>;
using timePoint = std::chrono::time_point<std::chrono::steady_clock>;



//Sorting sequence of numbers written by the user
void sorting();

//Sorting user input numbers (vector of ints)
std::pair<vectorOfInt, int> sorting_input(vectorOfInt, int);

//Output results
void display_results(const vectorOfInt& sorted, const vectorOfInt& unsorted);

//Print used algorithm
void used_algorithm(int);

//Print algortihm duration
void algorithm_duration(long long int);

//Printing numbers   
void print_numbers(const vectorOfInt& numbers, std::string_view text);

//Current time point
inline timePoint time_now() 
{
    return std::chrono::steady_clock::now();
}

//Checking duration
inline long long int time_interval(timePoint end, timePoint start) 
{
    return  std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}



#endif //_SORTING_