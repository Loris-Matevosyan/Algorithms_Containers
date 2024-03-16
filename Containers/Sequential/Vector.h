/*--------Header Only Library--------*/
#ifndef _VECTOR_
#define _VECTOR_
#include <iostream>
#include <utility>
#include <exception>

template <typename T>
class Vector{
    T* m_data;
    int m_size;
    int m_capacity;
    static constexpr int default_capacity{5};
public:
    //Output operator 
    template <typename U>
    friend std::ostream& operator<<(std::ostream& os, const Vector<U>& obj);

    //Overloaded [] operator (doesn't checking bounds)
    T operator[](int index);

    //at function (checking bounds)
    T at(int index);

    //Checking size
    int size() noexcept;

    //Checking capacity
    int capacity() noexcept;

    //Reset Vector
    void clear();

    //Pointer to the first element 
    T* begin();

    //Pointer to the element after the last
    T* end();

    //Utility for recursion to store data
    template <typename ... Args>
    void store_data(T t, Args&& ... args);

    //Default constructor (1)
    Vector();

    //Overloaded constructor (2)
    template <typename ... Args>
    explicit Vector(Args&& ... args);

    //Copy constructor (3)
    Vector(const Vector<T>& obj);

    //Copy assingment operator (4)
    Vector<T>& operator=(const Vector<T>& obj);

    //Move constrctor (5)
    Vector(Vector<T>&& obj) noexcept;

    //Move assingment constrctor (6)
    Vector<T>& operator=(Vector<T>&& obj) noexcept;

    //Destructor (7)
    ~Vector() noexcept;
};


template <typename U>
std::ostream& operator<<(std::ostream& os, const Vector<U>& obj) {
        for(int i = 0; i < obj.m_size; ++i)
            os << obj.m_data[i] << " ";
        return os;
}

template <typename T>
T Vector<T>::operator[](int index) {
        if (index > m_size || index < 0) 
            return T{};
        return m_data[index];
}

template <typename T>
T Vector<T>::at(int index) {
        try {
            if (index > m_size || index < 0) 
                throw std::out_of_range("index is out of range");
        } catch (const std::exception& e) {
            std::cout << index << " " << e.what() << std::endl;
            return T{};
        }
        return m_data[index];
}

template <typename T>
int Vector<T>::size() noexcept {
        return m_size;
}

template <typename T>
int Vector<T>::capacity() noexcept {
        return m_capacity;
}

template <typename T>
void Vector<T>::clear() {
        delete[] m_data;
        m_capacity = default_capacity;
        m_data = new T[m_capacity];
        m_size = 0;
}

template <typename T>
T* Vector<T>::begin() {
    if (m_size == 0)
        return nullptr;
    return &m_data[0];
}

template <typename T>
T* Vector<T>::end() {
    if (m_size == 0)
        return nullptr;
    return &m_data[m_size];
}

template <typename T>
template <typename ... Args>
void Vector<T>::store_data(T t, Args&& ... args) {
        int index = m_size - sizeof...(args) - 1;
        m_data[index] = t;
        if constexpr (sizeof...(args) > 0)
            return store_data(std::forward<Args>(args)...);
}

//1
template <typename T>
Vector<T>::Vector() {
        //Assinging members
        m_capacity = default_capacity;
        m_data = new T[m_capacity];
        m_size = 0;
        std::cout << "Default constructor" << std::endl;
}

//2
template <typename T>
template <typename ... Args>
Vector<T>::Vector(Args&& ... args)  {
        //Assinging members
        m_size = sizeof...(args);
        m_capacity = m_size;
        m_data = new T[m_capacity];

        store_data(std::forward<T>(args)...);
        //Coping m_data
        // for(int i = 0; i < m_size; ++i) 
        //     m_data[i] = str[i];
        
        std::cout << "Overloaded constructor" << std::endl;
}

//3
template <typename T>
Vector<T>::Vector(const Vector<T>& obj) {
        m_size = obj.m_size;
        m_capacity = obj.m_capacity;
        m_data = new T[m_capacity];

        for(int i = 0; i < m_size; ++i) 
            m_data[i] = obj.m_data[i];

        std::cout << "Copy constructor" << std::endl;
}

//4
template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& obj) {
        if (this != &obj) {
            delete[] m_data;
            m_capacity = obj.m_capacity;
            m_size = obj.m_size;
            m_data = new T[m_capacity];
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
template <typename T>
Vector<T>::Vector(Vector<T>&& obj) noexcept {
        m_capacity = obj.m_capacity;
        m_size = obj.m_size;
        m_data = obj.m_data;
        obj.m_data = nullptr;
        obj.m_capacity = 0;
        obj.m_size = 0;
        std::cout << "Move constructor" << std::endl;
}

//6
template <typename T>
Vector<T>& Vector<T>::operator=(Vector<T>&& obj) noexcept {
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
template <typename T>
Vector<T>::~Vector() noexcept {
    delete[] m_data;
    std::cout << "Destructor" << std::endl;
}


#endif //_VECTOR_