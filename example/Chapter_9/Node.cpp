#include "Node.h"

// 类的实现部分
// 构造函数 初始化数据和指针成员
template <typename T>
Node<T>::Node(const T &data, Node<T> *next /* = 0 */) : data(data), next(next) {}

// 返回后继结点的指针
template <typename T>
Node<T> *Node<T>::nextNode() {
    return next;
}

// 返回后继结点的指针
template <typename T>
const Node<T> *Node<T>::nextNode() const {
    return next;
}

// 在当前结点之后插入一个结点p
template <typename T>
void Node<T>::insertAfter(Node<T> *p) {
    p->next = next; // p结点指针域指向当前结点的后继结点
    next = p; // 当前结点的指针域指向p
}


// 删除当前结点的后继结点，并返回其地址
template <typename T>
Node<T> *Node<T>::deleteAfter() {
    Node<T> *tempPtr = next; // 将欲删除的结点地址存储到tempPtr中
    if(next == 0) return 0; // 如果当前结点没有后置结点，则返回空指针
    next = tempPtr->next; // 使当前结点的指针域指向tempPtr的后继结点
    return tempPtr; // 返回被删除的结点的地址
}