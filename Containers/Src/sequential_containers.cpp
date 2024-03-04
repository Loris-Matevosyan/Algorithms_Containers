#include "sequential_containers.h"


void check_Strings() {
    
    check_constructor();
    check_copy();
    check_move();
    check_indexes();
    check_attributes();
    String_range_for_loop();

}

void check_constructor() {
    std::cout << "\n-----Default constructor and overloaded constructor-----" << std::endl;
    String str1;
    String str2{"Hi friend"};
}
    
void check_copy() {
    std::cout << "\n-----Copy constructor and copy assignment operator-----" << std::endl;
    String str1;
    String str2{"Hi friend"};
    String str3 = str2;
    str1 = str2;
}
    
void check_move() {
    std::cout << "\n-----Move constructor and move assignment operator-----" << std::endl;
    String str1;
    String str2{"Hi friend"};
    String str3(std::move(str2));
    str1 = std::move(str3);
}
    
void check_indexes() {
    std::cout << "\n-----[] operator and at() function-----" << std::endl;
    String str{"Hi friend"};
    std::cout << "str at index 5 with at() is -> " << str.at(5) << std::endl;
    std::cout << "str at index 15 with at() is -> " << str.at(15);
    std::cout << "str at index -5 with at() is -> " << str.at(-5);
    std::cout << "str at index 7 with [] is -> " << str[7] << std::endl;
    std::cout << "str at index 17 with [] is -> " << str[17] << std::endl;
    std::cout << "str at index -7 with [] is -> " << str[-7] << std::endl;
}
    
void check_attributes() {
    std::cout << "\n-----size(), capacity() and clear() functions-----" << std::endl;
    String str{"Hi friend"};
    std::cout << "str size is " << str.size() << std::endl;
    std::cout << "str capacity is " << str.capacity() << std::endl;
    str.clear();
    std::cout << "after clearing str size is " <<str.size() << std::endl;
    std::cout << "after clearing str capacity is " << str.capacity() << std::endl;
}


void String_range_for_loop() {
    std::cout << "\n-----Range for loop-----" << std::endl;
    String str{"Hi friend"};
    for(auto ch: str)  
        std::cout << ch << "";
    // Or classic for loop ↓↓↓
    // for(auto it = str.begin(); it != str.end(); ++it)
    //     std::cout << *it << "";
    std::cout << std::endl;
}