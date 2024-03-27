#include "List.h"
#include <algorithm>
#include <climits>

/*================Node Struct================*/

//Default constructor
Node::Node () {
    m_value = INT_MIN;
}

//Overloaded constructor
Node::Node(int value) {
    m_value = value;
}

//Copy constructor
Node::Node(const Node& obj) {
    m_value = obj.m_value;
    if(obj.next != nullptr) {
        next = new Node(obj.next->m_value);

        //Assigning temporary pointers to traverse
        //current and argument Lists
        Node* obj_ptr = obj.next;
        Node* current_ptr_previous = this;
        Node* current_ptr = this->next;

        //Copying List 
        while(obj_ptr != nullptr) {
            if(obj_ptr->next != nullptr) 
                current_ptr->next = new Node(obj_ptr->next->m_value);
            else
                current_ptr->next = nullptr;    
            current_ptr->previous = current_ptr_previous;

            //Pointers going one forward (next)
            obj_ptr = obj_ptr->next;
            current_ptr = current_ptr->next;
            current_ptr_previous = current_ptr_previous->next;
        }
    }
}

//Copy assignment operator
Node& Node::operator=(const Node& obj) {
    if(this != &obj) {
        delete next;
        next = nullptr;

        //Calling copy constructor
        Node temp = obj;

        //Swapping objects
        std::swap(*this, temp);

        //temp is destroyed
    }
    return *this;
}

//Move constructor
Node::Node(Node&& obj) noexcept {
    m_value = obj.m_value;
    obj.m_value = INT_MIN;
    if(obj.next != nullptr) {
        next = obj.next;
        obj.next = nullptr; 
    }
}

//Move assignment operator
Node& Node::operator=(Node&& obj) noexcept {
    if(this != &obj) {
        delete next;
        next = nullptr;

        //Calling move constructor
        Node temp = std::move(obj);

        //Swapping objects
        std::swap(*this, temp);

        //temp is destroyed
    }
    return *this;
}

//Destructor
Node::~Node() noexcept {
    delete next;
}


/*================List Class================*/


int List::size() noexcept {
    return length;
}

void List::prepend(int value) {
    //==========================
}

void List::append(int value) {
    //==========================
}

bool List::insert(int index, int value) {
    //==========================
    return true;
}

bool List::set(int index, int value) {
    //==========================
    return true;
}

Node* List::get(int index) {
    //==========================
    return new Node();
}

void List::deleteFirst() {
    //==========================
}

void List::deleteLast() {
    //==========================
}

void List::deleteNode(int index) {
    //==========================
}

void List::reverse() {
    //==========================
}

//1
List::List() {
    length = 0;
}

//2
List::List(int value) {
    head = new Node(value);
    tail = head;
    length = 1;
} 

//3
List::List(const List& obj) {
    if (obj.head != nullptr) {
        head = new Node();
        *head = *obj.head;
        Node* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
        }
        tail = temp;
    }
    length = obj.length;
}

//4
List& List::operator=(const List& obj) {
    if(this != &obj) {
        delete head;
        head = nullptr;
        tail = nullptr;

        //Calling copy constructor
        List temp = obj;

        //Swapping objects
        std::swap(*this, temp);

        //temp is destroyed
    }
    return *this;
}

//5
List::List(List&& obj) noexcept {
    length = obj.length;
    head = obj.head;
    tail = obj.tail;
    obj.length = 0;
    obj.head = nullptr;
    obj.tail = nullptr;
}

//6
List& List::operator=(List&& obj) noexcept {
    if (this != &obj) {
        delete head;
        head = nullptr;
        tail = nullptr;
        length = 0;

        //Calling move constructor
        List temp = std::move(obj);

        //Swapping objects
        std::swap(*this, temp);

        //temp is destroyed
    }
    return *this;
}

//7
List::~List() noexcept {
    delete head;
}

