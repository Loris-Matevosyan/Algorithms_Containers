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

    check_List_constructors_and_operators();
    List_add_element();
    List_set_and_get_element();
    List_delete_element();
    List_reverse();

}


/*--------------String--------------*/


void check_String_constructor() {
    std::cout << "\n\n=============STRING=============\n" << std::endl;
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
    std::cout << "\n\n=============VECTOR=============\n" << std::endl;
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


void check_List_constructors_and_operators() {
    std::cout << "\n\n=============LIST=============\n" << std::endl;
    std::cout << "\n-----Lists Constructors and Operators-----" << std::endl;
    List list;
    std::cout << "\n--Called Default Constructor--" << std::endl;
    List list1(1);
    List list2(2);
    std::cout << "--Called Overloaded Constructor--" << std::endl;
    List list3 = list1;
    std::cout << "--Called Copy Constructor--" << std::endl;
    list2 = list3;
    std::cout << "--Called Copy Assignment Operator--" << std::endl;
    List list4 = std::move(list3);
    std::cout << "--Called Move Constructor--" << std::endl;
    list2 = std::move(list1);
    std::cout << "--Called Move Assignment Operator--" << std::endl;
}

void List_add_element() {
    std::cout << "\n-----Adding Node to List-----\n" << std::endl;
    List list(2);
    std::cout << "Created list with value 2" << std::endl;
    std::cout << "list contains (call to print() member function): ";
    list.print();
    list.append(3);
    std::cout << "\nAfter appending value 3 to list, list contains: ";
    list.print();
    list.prepend(1);
    std::cout << "\nAfter prepending value 1 to list, list contains: ";
    list.print();
    list.insert(2, 4);
    std::cout << "\nAfter inserting value 4 to list at index 2 list contains: ";
    list.print();
    std::cout << "\nlist size is (call to size() member function): " << list.size();
    std::cout << std::endl;
}

void List_set_and_get_element() {
    std::cout << "\n-----Setting and Getting Node from List-----\n" << std::endl;
    List list = creatingList();
    list.set(3, 10);
    std::cout << "\nAfter adding value 10 to list at index 3, list constains: ";
    list.print();
    Node* node = list.get(2);
    std::cout << "\nGetting Node at index 2, which value is: " << node->m_value << std::endl;
}

void List_delete_element() {
    std::cout << "\n-----Deleting Node from List-----\n" << std::endl;
    List list = creatingList();
    list.deleteFirst();
    std::cout << "\nAfter deleting first Node, list contains: ";
    list.print();
    list.deleteLast();
    std::cout << "\nAfter deleting last Node, list contains: ";
    list.print();
    list.deleteNode(1);
    std::cout << "\nAfter deleting Node at index 1, list contains: ";
    list.print();
    std::cout << std::endl;
}

void List_reverse() {
    std::cout << "\n-----Reverse List-----\n" << std::endl;
    List list = creatingList();
    list.reverse();
    std::cout << "\nAfter reversing list, list contains: ";
    list.print();
    std::cout << std::endl;
}

List creatingList() {
    List list(1);
    list.append(2);
    list.append(3);
    list.append(4);
    list.append(5);
    std::cout << "Created list with value 1 and appended values 2, 3, 4, 5" << std::endl;
    std::cout << "list contains (call to print() member function): ";
    list.print();
    return list;
}