#include "List.h"
#include <iostream>
#include <algorithm>
#include <climits>


/*================Node Struct================*/


//Default constructor
Node::Node () 
{
    m_value = INT_MIN;
}


//Overloaded constructor
Node::Node(int value) 
{
    m_value = value;
}


//Copy constructor
Node::Node(const Node& obj) 
{
    m_value = obj.m_value;

    if(obj.next != nullptr) {
        next = new Node(obj.next->m_value);

        //Assigning temporary pointers to traverse
        //current and argument Lists
        Node* obj_ptr = obj.next;
        Node* current_ptr_previous = this;
        Node* current_ptr = this->next;

        //Copying Nodes 
        while(obj_ptr != nullptr) 
        {
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
Node& Node::operator=(const Node& obj) 
{
    if(this != &obj) 
    {
        delete next;
        next = nullptr;
        m_value = obj.m_value;

        if(obj.next != nullptr) 
        {
            next = new Node(obj.next->m_value);

            //Assigning temporary pointers to traverse
            //current and argument Lists
            Node* obj_ptr = obj.next;
            Node* current_ptr_previous = this;
            Node* current_ptr = this->next;

            //Copying Nodes 
            while(obj_ptr != nullptr) 
            {
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
    return *this;
}


//Move constructor
Node::Node(Node&& obj) noexcept 
{
    m_value = obj.m_value;
    obj.m_value = INT_MIN;

    if(obj.next != nullptr)
    {
        next = obj.next;
        obj.next = nullptr; 
    }
}


//Move assignment operator
Node& Node::operator=(Node&& obj) noexcept 
{
    if(this != &obj) 
    {
        delete next;
        next = obj.next;
        m_value = obj.m_value;

        obj.next = nullptr;
        obj.m_value = INT_MIN;

        if (obj.previous != nullptr) 
        {
            Node* temp = obj.previous;

            delete temp->next;
            temp->next = nullptr;
        }
    }
    return *this;
}


//Destructor
Node::~Node() noexcept 
{
    if (next != nullptr)
        delete next;
}



/*================List Class================*/


int List::size() noexcept 
{
    return length;
}


void List::prepend(int value) 
{
    Node* new_node = new Node(value);

    if (length == 0) 
    {
        head = new_node;
        tail = head;
    } 
    else 
    {
        new_node->next = head;
        head->previous = new_node;
        head = new_node;
    }

    ++length;
}


void List::append(int value) 
{
    Node* new_node = new Node(value);

    if (length == 0) 
    {
        head = new_node;
        tail = head;
    } 
    else 
    {
        new_node->previous = tail;
        tail->next = new_node;
        tail = new_node;
    }

    ++length;    
}


bool List::insert(int index, int value) 
{
    if (index < 0 || index > length) return false;
    
    if (index == 0) 
    {
        prepend(value);
    } 
    else if (index == length) 
    {
        append(value);
    } 
    else 
    {
        Node* new_node = new Node(value);
        Node* prev_node = get(index - 1);
        Node* next_node = prev_node->next;

        prev_node->next = new_node;
        new_node->previous = prev_node;
        next_node->previous = new_node;
        new_node->next = next_node;

        ++length;
    }

    return true;
}


bool List::set(int index, int value) 
{
    Node* temp = get(index);

    if (temp != nullptr) 
    {
        temp->m_value = value;
        return true;
    }

    return false;
}


Node* List::get(int index) 
{
    if (index < 0 || index >= length) return nullptr;

    Node* temp = head;

    if (index < length/2) 
    {
        for(int i = 0; i < index; ++i)
            temp = temp->next;
    } 
    else 
    {
        temp = tail;
        
        for(int i = length - 1; i > index; --i)
            temp = temp->previous;
    }

    return temp;
}


void List::deleteFirst() {

    if (length == 0) return;
    Node* temp_node = head;

    if (length == 1) 
    {
        head = nullptr;
        tail = nullptr;
    }
    else 
    {
        head = head->next;
        head->previous = nullptr;
        temp_node->next = nullptr;
    }

    delete temp_node;
    --length;
}


void List::deleteLast() 
{
    if (length == 0) return;

    Node* temp_node = tail;

    if (length == 1)
    {
        head = nullptr;
        tail = nullptr;
    } 
    else 
    {
        tail = tail->previous;
        tail->next = nullptr;

        // ↓↓↓ Not necessary, but for completeness, because 
        // ↓↓↓ Nodes are being deleted forward sequentially, not backward
        temp_node->previous = nullptr;
    }

    delete temp_node;
    --length;
}


void List::deleteNode(int index) 
{
    if (index < 0 || index >= length) return;

    if (index == 0) return deleteFirst();

    if (index == length - 1) return deleteLast();

    Node* temp_node = get(index);

    temp_node->next->previous = temp_node->previous;
    temp_node->previous->next = temp_node->next;
    temp_node->next = nullptr;
    temp_node->previous = nullptr;
    
    delete temp_node;
    --length;
}


void List::reverse() 
{
    if (length < 2) return;

    Node* previous_node = nullptr;
    Node* current_node = head;

    head = tail;
    tail = current_node;

    while (current_node != nullptr) 
    {
        previous_node = current_node->previous;
        current_node->previous = current_node->next;
        current_node->next = previous_node;
        current_node = current_node->previous;
    }
}


void List::print() 
{
    Node* temp = head;

    while (temp != nullptr) 
    {
        std::cout << temp->m_value << " ";
        temp = temp->next;
    }
}


//1
List::List() 
{
    length = 0;
}


//2
List::List(int value) 
{
    head = new Node(value);
    tail = head;
    length = 1;
} 


//3
List::List(const List& obj) 
{
    if (obj.head != nullptr) 
    {
        Node* new_node = new Node(*obj.head);
        head = new_node;
        Node* temp = head;
        
        while(temp->next != nullptr) 
        {
            temp = temp->next;
        }

        tail = temp;
    }

    length = obj.length;
}


//4
List& List::operator=(const List& obj) 
{
    if(this != &obj) 
    {
        delete head;
        head = nullptr;
        tail = nullptr;

        if (obj.head != nullptr) 
        {
            Node* new_node = new Node(*obj.head);
            head = new_node;
            Node* temp = head;

            while(temp->next != nullptr) 
            {
                temp = temp->next;
            }

            tail = temp;
        }

        length = obj.length;
    }

    return *this;
}


//5
List::List(List&& obj) noexcept 
{
    length = obj.length;
    head = obj.head;
    tail = obj.tail;

    obj.length = 0;
    obj.head = nullptr;
    obj.tail = nullptr;
}


//6
List& List::operator=(List&& obj) noexcept 
{
    if (this != &obj) 
    {
        delete head;

        head = obj.head;
        tail = obj.tail;
        length = obj.length;

        obj.head = nullptr;
        obj.tail = nullptr;
        obj.length = 0;
    }

    return *this;
}


//7
List::~List() noexcept 
{
    // Deleting one Node will delete all of them sequentially
    // No need to delete tail pointer
    if (head != nullptr)
        delete head;
}

