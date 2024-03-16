#ifndef _SEQUENTIAL_CONTAINERS_
#define _SEQUENTIAL_CONTAINERS_
#include "String.h"
#include "Vector.h"


/*===========FOR String===========*/


//Checking default and overloaded constructors
void check_String_constructor();

//Checking copy constructor and copy assignment
void check_String_copy();

//Checking move constructor and move assignment
void check_String_move();

//Checking [] operator and at() function
void check_String_indexes();

//Checking data members with size() and capacity() functions
void check_String_attributes();

//Range based for loop
void String_range_for_loop();


/*------ MAIN FUNCTION FOR STRING------*/
void check_Strings();



/*===========FOR Vector===========*/


//Checking default and overloaded constructors
void check_Vector_constructor();

//Checking copy constructor and copy assignment
void check_Vector_copy();

//Checking move constructor and move assignment
void check_Vector_move();

//Checking [] operator and at() function
void check_Vector_indexes();

//Checking data members with size() and capacity() functions
void check_Vector_attributes();

//Range based for loop
void Vector_range_for_loop();


/*------ MAIN FUNCTION FOR VECTOR------*/
void check_Vectors();



#endif //_SEQUENTIAL_CONTAINERS_