#ifndef _SORTING_
#define _SORTING_
#include <vector>
#include <chrono>

//Global print function    
void print(int arr[], int size);

//Sorting sequence of numbers written by the user
void sorting();

//Sorting user input numbers (vector of ints)
int sorting_input(std::vector<int>&, int);

//Output results
void results(std::vector<int>, std::vector<int>);

//Print used algorithm
void used_algorithm(int);

//Print algortihm duration
void algorithm_duration(long long int);

//Current time point
inline std::chrono::time_point<std::chrono::system_clock> time_now() {
    return std::chrono::system_clock::now();
}

//Checking duration
inline long long int time_interval(std::chrono::time_point<std::chrono::system_clock> end, 
                                std::chrono::time_point<std::chrono::system_clock> start) {
    return  std::chrono::duration_cast<std::chrono::nanoseconds>(end - start).count();
}


#endif // _SORTING_