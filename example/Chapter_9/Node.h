// Node.h
#ifndef NODE_H
#define NODE_H

// 类模板的定义
template <typename T>
class Node {
public:
    T data; // 数据域

    Node(const T &data, Node<T> *next = 0); // 构造函数
    void insertAfter(Node<T> *p); // 在本结点之后插入一个同类结点p
    Node<T> *deleteAfter(); // 删除本结点的后继节点，并返回其地址
    Node<T> *nextNode(); // 获取后继结点的地址
    const Node<T> *nextNode() const; // 获取后继结点的地址
private:
    Node<T> *next; // 指向后继节点的指针
};


#endif