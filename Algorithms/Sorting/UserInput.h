#ifndef _USER_INPUT_
#define _USER_INPUT_

#include <iostream>
#include <utility>
#include <limits>
#include <vector>

using vectorOfInt = std::vector<int>;



//Starting point for user input
std::pair<vectorOfInt, int> user_input();

//User choosing which algorithm to use
int algorithm_choice();

//Suggest user to enter random numbers for sorting
vectorOfInt numbers_to_sort();

//Clear input stream
inline void clear_istream() 
{
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

//Wrong input
inline void wrong_user_input() 
{
    std::cout << "Wrong input, please try again\n";
    clear_istream();
}

//Wish to repeat?
bool repeat();



#endif  //_USER_INPUT_