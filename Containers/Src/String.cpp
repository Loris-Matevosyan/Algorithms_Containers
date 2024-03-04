#include "String.h"
#include <exception>

std::ostream& operator<<(std::ostream& os, const String& obj) {
        for(int i = 0; i < obj.m_size; ++i)
            os << obj.m_data[i];
        return os;
}

char String::operator[](int index) {
        if (index > m_size || index < 0) 
            return '\0';
        return m_data[index];
}

int String::size() noexcept {
        return m_size;
}

int String::capacity() noexcept {
        return m_capacity;
}

void String::clear() {
        delete m_data;
        m_capacity = default_capacity;
        m_data = new char[m_capacity];
        m_size = 0;
}

char String::at(int index) {
        try {
            if (index > m_size || index < 0) 
                throw std::out_of_range("index is out of range");
        } catch (const std::exception& e) {
            std::cout << index << " " << e.what() << std::endl;
            return '\0';
        }
        return m_data[index];
}

char* String::begin() {
    if (m_size == 0)
        return nullptr;
    return &m_data[0];
}

char* String::end() {
    if (m_size == 0)
        return nullptr;
    return &m_data[m_size];
}

//1
String::String() {
        //Assinging members
        m_capacity = default_capacity;
        m_data = new char[m_capacity];
        m_size = 0;
        std::cout << "Default constructor" << std::endl;
}

//2
String::String(const std::string& str) {
        //Assinging members
        m_size = str.size();
        m_capacity = m_size;
        m_data = new char[m_capacity];

        //Coping m_data
        for(int i = 0; i < m_size; ++i) 
            m_data[i] = str[i];
        
        std::cout << "Overloaded constructor" << std::endl;
}

//3
String::String(const String& obj) {
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        m_data = new char[m_capacity];

        for(int i = 0; i < m_size; ++i) 
            m_data[i] = obj.m_data[i];

        std::cout << "Copy constructor" << std::endl;
}

//4
String& String::operator=(const String& obj) {
        if (this != &obj) {
            delete[] m_data;
            m_capacity = obj.m_capacity;
            m_size = obj.m_size;
            m_data = new char[m_capacity];
            for(int i = 0; i < m_size; ++i) {
                m_data[i] = obj.m_data[i];
            }
        }
        std::cout << "Copy assignment operator" << std::endl;
        return *this;
        //Or alternatively could use "Copy and Swap" idiom
        //must include <algorithm>, after that ↓↓↓
        //Sting temp = obj;
        //std::swap(temp, *this);
        //return *this;
}

//5
String::String(String&& obj) noexcept {
        m_capacity = obj.m_capacity;
        m_size = obj.m_size;
        m_data = obj.m_data;
        obj.m_data = nullptr;
        obj.m_capacity = 0;
        obj.m_size = 0;
        std::cout << "Move constructor" << std::endl;
}

//6
String& String::operator=(String&& obj) noexcept {
        if (this != &obj) {
            delete[] m_data;
            m_capacity = obj.m_capacity;
            m_size = obj.m_size;
            m_data = obj.m_data;
            obj.m_data = nullptr;
            obj.m_capacity = 0;
            obj.m_size = 0;
        }
        std::cout << "Move assignment operator" << std::endl;
        return *this;
        //Or alternatively could use "Copy and Swap" idiom
        //must include <algorithm>, after that ↓↓↓
        //Sting temp(std::move(obj));
        //std::swap(temp, *this);
        //return *this;
}

//7
String::~String () noexcept {
    delete[] m_data;
    std::cout << "Destructor" << std::endl;
}
