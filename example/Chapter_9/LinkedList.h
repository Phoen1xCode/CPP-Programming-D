#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

template<typename T>
class LinkedList {
public:
    LinkedList(); // 构造函数
    LinkedList(const LinkedList<T> &L); // 复制构造函数
    ~LinkedList(); // 析构函数
    LinkedList<T> &operator=(const LinkedList<T> &L); // 重载赋值运算符 

    int getSize() const; // 返回链表中元素个数
    bool isEpmty() const; // 链表是否为空

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
    Node<T> *front, *rear; //
    Node<T> *prevPtr, *currPtr; //  
    int size;
    int position;



    // 函数成员
    // 生成新结点，数据域为item，指针域为ptrNext
    Node<T> *newNode();

    //
    void freeNode(Node<T> *p);

    // 
    // 
    void copy(const LinkedList<T> &L);


};

#endif