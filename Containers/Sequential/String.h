#ifndef _STRING_
#define _STRING_
#include <iostream>
#include <string>


class String{
    char* m_data;
    int m_size;
    int m_capacity;
    static constexpr int default_capacity{5};
public:
    //Output operator 
    friend std::ostream& operator<<(std::ostream& os, const String& obj);

    //Overloaded [] operator (doesn't checking bounds)
    char operator[](int index);

    //at function (checking bounds)
    char at(int index);

    //Checking size
    int size() noexcept;

    //Checking capacity
    int capacity() noexcept;

    //Reset String
    void clear();

    //Pointer to the first element 
    char* begin();

    //Pointer to the element after the last
    char* end();

    //Default constructor (1)
    String();

    //Overloaded constructor (2)
    String(const std::string& str);

    //Copy constructor (3)
    String(const String& obj);

    //Copy assingment operator (4)
    String& operator=(const String& obj);

    //Move constrctor (5)
    String(String&& obj) noexcept;

    //Move assingment constrctor (6)
    String& operator=(String&& obj) noexcept;

    //Destructor (7)
    ~String() noexcept;
};



#endif //_STRING_