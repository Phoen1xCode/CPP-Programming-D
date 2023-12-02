#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include <stdexcept>

template<typename T>
class LinkedList {
public:
    LinkedList(); // 构造函数
    LinkedList(const LinkedList<T> &L); // 复制构造函数
    ~LinkedList(); // 析构函数
    LinkedList<T> &operator=(const LinkedList<T> &L); // 重载赋值运算符 

    int getSize() const; // 返回链表中元素个数
    bool isEmpty() const; // 链表是否为空

    void reset(int pos = 0); // 初始化游标的位置
    void next(); // 使游标移动到下一个结点
    bool endOfList() const; // 游标是否到了链尾
    int currentPosition() const; // 返回游标当前的位置

    void insertFront(const T &item); // 在表头插入结点
    void insertRear(const T &item); // 在表尾插入结点
    void insertAt(const T &item); // 在当前结点之前插入结点
    void insertAfter(const T &item); // 在当前结点之后插入结点

    T deleteFront(); // 删除头结点
    void deleteCurrent(); // 删除当前结点
    T &data(); // 返回对当前结点成员数据的引用
    const T &data() const; // 返回对当前结点成员数据的常引用

    // 清空链表 释放所有结点的内存空间 被析构函数 && operator= 调用
    void clear(); 

private:
    // 数据成员
    Node<T> *front, *rear; // 表头和表尾指针
    Node<T> *prevPtr, *currPtr; // 记录表当前遍历位置的指针 由插入和删除操作更新
    int size; // 表中的元素个数
    int position; // 当前元素在表中的位置序号 由函数 reset() 使用



    // 函数成员
    // 生成新结点，数据域为item，指针域为ptrNext
    Node<T> *newNode(const T &item, Node<T>* ptrNext = nullptr); 

    // 释放结点
    void freeNode(Node<T> *p);

    // 将链表L复制到当前表（假设当前表为空）
    // 被复制构造函数 operator= 调用
    void copy(const LinkedList<T> &L);


};

// 链表类的具体实现

// Constructor
template<typename T>
LinkedList<T>::LinkedList() : front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(0) {}

// Copy constructor
template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &L) : front(nullptr), rear(nullptr), prevPtr(nullptr), currPtr(nullptr), size(0), position(0) {
    copy(L);
}

// Destructor
template<typename T>
LinkedList<T>::~LinkedList() {
    clear();
}

// Overloaded assignment operator
template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &L) {
    if (this != &L) {
        clear();
        copy(L);
    }
    return *this;
}

// Get size of the list
template<typename T>
int LinkedList<T>::getSize() const {
    return size;
}

// Check if the list is empty
template<typename T>
bool LinkedList<T>::isEmpty() const {
    return size == 0;
}

// Reset the position of the cursor
template<typename T>
void LinkedList<T>::reset(int pos) {
    position = pos;
    prevPtr = nullptr;
    currPtr = front;
    for (int i = 0; i < pos; ++i) {
        prevPtr = currPtr;
        currPtr = currPtr->next;
    }
}

// Move the cursor to the next node
template<typename T>
void LinkedList<T>::next() {
    if (currPtr != nullptr) {
        prevPtr = currPtr;
        currPtr = currPtr->next;
        position++;
    }
}

// Check if the cursor is at the end of the list
template<typename T>
bool LinkedList<T>::endOfList() const {
    return currPtr == nullptr;
}

// Get the current position of the cursor
template<typename T>
int LinkedList<T>::currentPosition() const {
    return position;
}

// Insert a node at the front of the list
template<typename T>
void LinkedList<T>::insertFront(const T &item) {
    Node<T> *new_node = newNode(item, front);
    front = new_node;
    if (rear == nullptr) {
        rear = front;
    }
    size++;
}

// Insert a node at the rear of the list
template<typename T>
void LinkedList<T>::insertRear(const T &item) {
    Node<T> *new_node = newNode(item);
    if (rear != nullptr) {
        rear->insertAfter(new_node);
    } else {
        front = new_node;
    }
    rear = new_node;
    size++;
}

// Insert a node before the current node
template<typename T>
void LinkedList<T>::insertAt(const T &item) {
    if (position == 0 || currPtr == front) {
        insertFront(item);
    } else {
        Node<T> *newNode = new Node<T>(item, currPtr);
        prevPtr->next = newNode;
        size++;
    }
}

// Insert a node after the current node
template<typename T>
void LinkedList<T>::insertAfter(const T &item) {
    if (currPtr == nullptr) {
        insertRear(item);
    } else {
        Node<T> *newNode = new Node<T>(item, currPtr->next);
        currPtr->next = newNode;
        if (currPtr == rear) {
            rear = newNode;
        }
        size++;
    }
}

// Delete the front node
template<typename T>
T LinkedList<T>::deleteFront() {
    if (front == nullptr) {
        throw std::out_of_range("Empty list");
    }
    Node<T> *temp = front;
    T data = temp->data;
    front = front->nextNode();
    if (front == nullptr) {
        rear = nullptr;
    }
    freeNode(temp);
    size--;
    if (position > 0) {
        position--;
    }
    return data;
}

// Delete the current node
template<typename T>
void LinkedList<T>::deleteCurrent() {
    if (currPtr == nullptr) {
        throw std::out_of_range("No current node");
    }
    if (currPtr == front) {
        deleteFront();
    } else {
        prevPtr->next = currPtr->next;
        if (currPtr == rear) {
            rear = prevPtr;
        }
        delete currPtr;
        currPtr = prevPtr->next;
        size--;
    }
}

// Get data of the current node
template<typename T>
T &LinkedList<T>::data() {
    if (currPtr == nullptr) {
        throw std::out_of_range("No current node");
    }
    return currPtr->data;
}

// Get data of the current node (const version)
template<typename T>
const T &LinkedList<T>::data() const {
    if (currPtr == nullptr) {
        throw std::out_of_range("No current node");
    }
    return currPtr->data;
}

// Clear the list
template<typename T>
void LinkedList<T>::clear() {
    while (front != nullptr) {
        Node<T> *temp = front;
        front = front->nextNode();
        freeNode(temp);
    }
    rear = prevPtr = currPtr = nullptr;
    size = 0;
    position = 0;
}

// Create a new node
template<typename T>
Node<T> *LinkedList<T>::newNode(const T &item, Node<T> *ptrNext) {
    return new Node<T>(item, ptrNext);
}

// Free a node
template<typename T>
void LinkedList<T>::freeNode(Node<T> *p) {
    delete p;
}

// Copy a list
template<typename T>
void LinkedList<T>::copy(const LinkedList<T> &L) {
    Node<T> *current = L.front;
    while (current != nullptr) {
        insertRear(current->data);
        current = current->nextNode();
    }
}

#endif