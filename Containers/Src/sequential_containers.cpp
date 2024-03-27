#include "sequential_containers.h"


void check_Strings() {
    
    check_String_constructor();
    check_String_copy();
    check_String_move();
    check_String_indexes();
    check_String_attributes();
    String_range_for_loop();

}


void check_Vectors() {
    
    check_Vector_constructor();
    check_Vector_copy();
    check_Vector_move();
    check_Vector_indexes();
    check_Vector_attributes();
    Vector_range_for_loop();

}


void check_Lists() {

    test_List();
}


/*--------------String--------------*/


void check_String_constructor() {
    std::cout << "\n-----String Default constructor and overloaded constructor-----" << std::endl;
    String str1;
    String str2{"Hi friend"};
}
    
void check_String_copy() {
    std::cout << "\n-----String Copy constructor and copy assignment operator-----" << std::endl;
    String str1;
    String str2{"Hi friend"};
    String str3 = str2;
    str1 = str2;
}
    
void check_String_move() {
    std::cout << "\n-----String Move constructor and move assignment operator-----" << std::endl;
    String str1;
    String str2{"Hi friend"};
    String str3(std::move(str2));
    str1 = std::move(str3);
}
    
void check_String_indexes() {
    std::cout << "\n-----String [] operator and at() function-----" << std::endl;
    String str{"Hi friend"};
    std::cout << "str at index 5 with at() is -> " << str.at(5) << std::endl;
    std::cout << "str at index 15 with at() is -> " << str.at(15);
    std::cout << "str at index -5 with at() is -> " << str.at(-5);
    std::cout << "str at index 7 with [] is -> " << str[7] << std::endl;
    std::cout << "str at index 17 with [] is -> " << str[17] << std::endl;
    std::cout << "str at index -7 with [] is -> " << str[-7] << std::endl;
}
    
void check_String_attributes() {
    std::cout << "\n-----String size(), capacity() and clear() functions-----" << std::endl;
    String str{"Hi friend"};
    std::cout << "str size is " << str.size() << std::endl;
    std::cout << "str capacity is " << str.capacity() << std::endl;
    str.clear();
    std::cout << "after clearing str size is " << str.size() << std::endl;
    std::cout << "after clearing str capacity is " << str.capacity() << std::endl;
}


void String_range_for_loop() {
    std::cout << "\n-----String Range for loop-----" << std::endl;
    String str{"Hi friend"};
    for(auto ch: str)  
        std::cout << ch << "";
    // Or classic for loop ↓↓↓
    // for(auto it = str.begin(); it != str.end(); ++it)
    //     std::cout << *it << "";
    std::cout << std::endl;
}


/*--------------Vector--------------*/


void check_Vector_constructor() {
    std::cout << "\n-----Vector Default constructor and overloaded constructor-----" << std::endl;
    Vector<std::string>  vec1;
    Vector<std::string>  vec2{"Hi friend", "My dear friend", "Bye bye"};
    Vector<int>  vec3{1, 2, 3, 4};
    std::cout << "vec2 contains " << vec2 << std::endl;
    std::cout << "vec3 contains " << vec3 << std::endl;
}
    
void check_Vector_copy() {
    std::cout << "\n-----Vector Copy constructor and copy assignment operator-----" << std::endl;
    Vector<std::string> vec1;
    Vector<std::string> vec2{"Hi friend", "how are you?", "bye bye"};
    Vector<std::string> vec3 = vec2;
    vec1 = vec2;
}
    
void check_Vector_move() {
    std::cout << "\n-----Vector Move constructor and move assignment operator-----" << std::endl;
    Vector<std::string> vec1;
    Vector<std::string> vec2{"Hi friend", "how are you?", "bye bye"};
    Vector<std::string> vec3(std::move(vec2));
    vec1 = std::move(vec3);
}
    
void check_Vector_indexes() {
    std::cout << "\n-----Vector [] operator and at() function-----" << std::endl;
    Vector<std::string> vec{"Hi friend", "how are you?", "bye bye"};
    std::cout << "vec at index 1 with at() is -> " << vec.at(1) << std::endl;
    std::cout << "vec at index 10 with at() is -> " << vec.at(10);
    std::cout << "vec at index -1 with at() is -> " << vec.at(-1);
    std::cout << "vec at index 2 with [] is -> " << vec[2] << std::endl;
    std::cout << "vec at index 20 with [] is -> " << vec[20] << std::endl;
    std::cout << "vec at index -2 with [] is -> " << vec[-2] << std::endl;
}
    
void check_Vector_attributes() {
    std::cout << "\n-----Vector size(), capacity() and clear() functions-----" << std::endl;
    Vector<std::string> vec{"Hi friend", "how are you?", "bye bye"};
    std::cout << "vec size is " << vec.size() << std::endl;
    std::cout << "vec capacity is " << vec.capacity() << std::endl;
    vec.clear();
    std::cout << "after clearing vec size is " << vec.size() << std::endl;
    std::cout << "after clearing vec capacity is " << vec.capacity() << std::endl;
}


void Vector_range_for_loop() {
    std::cout << "\n-----Vector Range for loop-----" << std::endl;
    Vector<std::string> vec{"Hi friend", "how are you?", "bye bye"};
    for(auto el: vec)  
        std::cout << el << " ";
    // Or classic for loop ↓↓↓
    // for(auto it = str.begin(); it != str.end(); ++it)
    //     std::cout << *it << "";
    std::cout << std::endl;
}


/*--------------List--------------*/


void test_List() {

    std::cout << "\n------Node Example------" << std::endl;

    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);
    Node* node5 = new Node(5);
    Node* node6 = new Node(6);

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Node* temp = node1;
    std::cout << "Print Nodes values: ";
    for(int i = 0; i < 6; ++i) {
        std::cout << temp->m_value << " ";
        temp = temp->next;
    }

    delete node1;
}