#include "LinkedList.h"
#include "Node.h"

template<typename T>
LinkedList<T>::LinkedList() {
    front = rear = prevPtr = currPtr = nullptr; // 初始化指针为空
    size = position = 0; // 初始化链表大小和位置为0
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &L) {
    copy(L); // 复制链表L的内容
}

template<typename T>
LinkedList<T>::~LinkedList() {
    clear(); // 清空链表
}

template<typename T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &L) {
    if (this != &L) { // 避免自我赋值
        clear(); // 清空当前链表
        copy(L); // 复制链表L的内容
    }
    return *this; // 返回当前链表的引用
}

template<typename T>
int LinkedList<T>::getSize() const {
    return size; // 返回链表的大小
}

template<typename T>
bool LinkedList<T>::isEpmty() const {
    return size == 0; // 判断链表是否为空
}

template<typename T>
void LinkedList<T>::reset(int pos) {
    if (pos >= 0 && pos <= size) { // 判断位置是否合法
        position = pos; // 设置当前位置
        if (position == 0) { // 如果位置为0，当前指针指向头节点
            currPtr = front;
            prevPtr = nullptr;
        } else { // 否则根据位置找到对应的节点
            currPtr = front->next;
            prevPtr = front;
            for (int i = 1; i < position; i++) {
                prevPtr = currPtr;
                currPtr = currPtr->next;
            }
        }
    }
}

template<typename T>
void LinkedList<T>::next() {
    if (currPtr != nullptr) { // 如果当前指针不为空
        prevPtr = currPtr; // 更新前一个指针为当前指针
        currPtr = currPtr->next; // 更新当前指针为下一个节点
        position++; // 更新位置
    }
}

template<typename T>
bool LinkedList<T>::endOfList() const {
    return currPtr == nullptr; // 判断是否到达链表末尾
}

template<typename T>
int LinkedList<T>::currentPosition() const {
    return position; // 返回当前位置
}

template<typename T>
void LinkedList<T>::insertFront(const T &item) {
    Node<T> *newNode = new Node<T>(item, front); // 创建新节点，将其插入到头部
    if (front == nullptr) { // 如果链表为空
        front = rear = newNode; // 头尾指针都指向新节点
    } else {
        front = newNode; // 否则将头指针指向新节点
    }
    size++; // 更新链表大小
}

template<typename T>
void LinkedList<T>::insertRear(const T &item) {
    Node<T> *newNode = new Node<T>(item, nullptr); // 创建新节点，将其插入到尾部
    if (rear == nullptr) { // 如果链表为空
        front = rear = newNode; // 头尾指针都指向新节点
    } else {
        rear->next = newNode; // 否则将尾节点的下一个指针指向新节点
        rear = newNode; // 更新尾指针为新节点
    }
    size++; // 更新链表大小
}

template<typename T>
void LinkedList<T>::insertAt(const T &item) {
    Node<T> *newNode = new Node<T>(item, currPtr); // 创建新节点，将其插入到当前节点之前
    if (prevPtr == nullptr) { // 如果前一个指针为空
        front = newNode; // 将头指针指向新节点
    } else {
        prevPtr->next = newNode; // 否则将前一个节点的下一个指针指向新节点
    }
    currPtr = newNode; // 更新当前指针为新节点
    size++; // 更新链表大小
}

template<typename T>
void LinkedList<T>::insertAfter(const T &item) {
    Node<T> *newNode = new Node<T>(item, currPtr->next); // 创建新节点，将其插入到当前节点之后
    currPtr->next = newNode; // 将当前节点的下一个指针指向新节点
    if (rear == currPtr) { // 如果当前节点是尾节点
        rear = newNode; // 更新尾指针为新节点
    }
    size++; // 更新链表大小
}

template<typename T>
T LinkedList<T>::deleteFront() {
    if (front == nullptr) { // 如果链表为空
        throw "LinkedList is empty."; // 抛出异常
    }
    T data = front->data; // 获取头节点的数据
    Node<T> *temp = front; // 临时指针指向头节点
    front = front->next; // 更新头指针为下一个节点
    delete temp; // 删除头节点
    size--; // 更新链表大小
    if (front == nullptr) { // 如果链表为空
        rear = nullptr; // 更新尾指针为空
    }
    return data; // 返回头节点的数据
}

template<typename T>
void LinkedList<T>::deleteCurrent() {
    if (currPtr == nullptr) { // 如果当前指针为空
        throw "No current node."; // 抛出异常
    }
    if (prevPtr == nullptr) { // 如果前一个指针为空
        front = currPtr->next; // 更新头指针为当前节点的下一个节点
    } else {
        prevPtr->next = currPtr->next; // 否则将前一个节点的下一个指针指向当前节点的下一个节点
    }
    if (rear == currPtr) { // 如果当前节点是尾节点
        rear = prevPtr; // 更新尾指针为前一个节点
    }
    delete currPtr; // 删除当前节点
    currPtr = prevPtr->next; // 更新当前指针为前一个节点的下一个节点
    size--; // 更新链表大小
}

template<typename T>
T &LinkedList<T>::data() {
    if (currPtr == nullptr) { // 如果当前指针为空
        throw "No current node."; // 抛出异常
    }
    return currPtr->data; // 返回当前节点的数据
}

template<typename T>
const T &LinkedList<T>::data() const {
    if (currPtr == nullptr) { // 如果当前指针为空
        throw "No current node."; // 抛出异常
    }
    return currPtr->data; // 返回当前节点的数据
}

template<typename T>
void LinkedList<T>::clear() {
    while (front != nullptr) { // 循环删除链表中的所有节点
        Node<T> *temp = front; // 临时指针指向头节点
        front = front->next; // 更新头指针为下一个节点
        delete temp; // 删除头节点
    }
    rear = prevPtr = currPtr = nullptr; // 将指针置为空
    size = position = 0; // 将大小和位置置为0
}

template<typename T>
Node<T> *LinkedList<T>::newNode() {
    Node<T> *newNode = new Node<T>(); // 创建新节点
    if (newNode == nullptr) { // 如果内存分配失败
        throw "Memory allocation failed."; // 抛出异常
    }
    return newNode; // 返回新节点指针
}

template<typename T>
void LinkedList<T>::freeNode(Node<T> *p) {
    delete p; // 删除节点
}

template<typename T>
void LinkedList<T>::copy(const LinkedList<T> &L) {
    front = rear = prevPtr = currPtr = nullptr; // 将指针置为空
    size = position = 0; // 将大小和位置置为0
    Node<T> *p = L.front; // 临时指针指向链表L的头节点
    while (p != nullptr) { // 循环复制链表L的节点
        insertRear(p->data); // 将节点数据插入到当前链表的尾部
        p = p->next; // 更新临时指针为下一个节点
    }
}
