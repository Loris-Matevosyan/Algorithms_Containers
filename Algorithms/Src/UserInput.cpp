#include "UserInput.h"
#include <algorithm>
#include <string>



std::pair<vectorOfInt, int> user_input() 
{
    int sorting_choice = algorithm_choice();
    clear_istream();

    return std::make_pair(numbers_to_sort(), sorting_choice);
}


int algorithm_choice() 
{
    int sorting_choice;
    char choice;
    bool wrong_input{true};
    
    do 
    {
        std::cout << "Please choose which sorting algorithm do you want to use\n" <<
                 "1. Bubble Sort\n" << "2. Selection Sort\n" << "3. Insertion Sort\n" << 
                 "4. Quick Sort\n" << "5. Merge Sort" << std::endl;
        std::cin  >> choice;

        if (isdigit(choice)) 
        {
            sorting_choice = choice - 48;

            if (sorting_choice > 0 && sorting_choice < 6) 
            {
                wrong_input = false;
            }
            else 
            {
                wrong_user_input();
            }
        } 
        else 
        {
            wrong_user_input();
        }  
    } 
    while(wrong_input); 
    
    return sorting_choice;
}


vectorOfInt numbers_to_sort() 
{
    bool wrong_input{true};
    std::string input;

    do 
    {
        std::cout << "Please enter numbers for sorting: ";
        std::getline(std::cin, input);

        auto it =std::find_if( input.begin(), input.end(), [](char ch) { return ( !isdigit(ch) && !isspace(ch) ); } );

        if (it != input.end() || input.empty()) 
        {
            std::cout << "Wrong input, please enter numbers only" << std::endl;
        }
        else
        { 
            wrong_input = false;
        }
    } 
    while(wrong_input);

    input.erase( std::remove_if( input.begin(), input.end(), 
                                    [](char ch) { return isspace(ch); } ), input.end() );

    vectorOfInt numbers_for_sorting;
    std::transform(input.begin(), input.end(), back_inserter(numbers_for_sorting), 
                    [](char ch) { return ch - 48;});

    return numbers_for_sorting;
}


bool repeat() 
{
    char choice;
    bool loop{true};

    std::cout << "\nWish to repeat? Y/N" << "\nAnswer: ";

    do 
    {
        std::cin.get(choice);
        if (toupper(choice) == 'Y') 
        {
            clear_istream();
            loop = false;
        }
        else if (toupper(choice) == 'N') 
        {
            clear_istream();
            return false;
        }
        else 
        {
            std::cout << "Wrong answer. Please try again (Y/N): ";
            clear_istream();
        }
    } 
    while (loop);
    
    return true;
}
