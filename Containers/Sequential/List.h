#ifndef _LIST_
#define _LIST_


/*====================Node Struct====================*/


struct Node{

    /*  Data members (attributes)  */

    Node* next{nullptr};
    Node* previous{nullptr};
    int m_value;

    /*  Special member functions  */

    //Default constructor
    Node();

    //Overloaded constructor
    explicit Node(int value);

    //Copy constructor
    Node(const Node& obj);

    //Copy assignment operator
    Node& operator=(const Node& obj);
    
    //Move constructor
    Node(Node&& obj) noexcept;

    //Move assignment operator
    Node& operator=(Node&& obj) noexcept;

    //Destructor
    ~Node() noexcept;
};


/*====================List Class====================*/


class List{

    Node* head{nullptr};
    Node* tail{nullptr};
    int length;

public:

    //Checking size
    int size() noexcept;

    //Prepand Node
    void prepend(int value);

    //Append Node
    void append(int value);

    //Inserting Node
    bool insert(int index, int value);

    //Set Node
    bool set(int index, int value);

    //Get Node
    Node* get(int index);

    //Delete first Node
    void deleteFirst();

    //Delete last Node
    void deleteLast();

    //Delete Node
    void deleteNode(int index);

    //Reverse List
    void reverse();

    //Print List
    void print();

    //Default constructor (1)
    List();

    //Overloaded constructor (2)
    List(int value);

    //Copy constructor (3)
    List(const List& obj);

    //Copy assignment operator (4)
    List& operator=(const List& obj);

    //Move constructor (5)
    List(List&& obj) noexcept;

    //Move assignment operator (6)
    List& operator=(List&& obj) noexcept; 

    //Destructor (7)
    ~List() noexcept;
};


#endif //_LIST_