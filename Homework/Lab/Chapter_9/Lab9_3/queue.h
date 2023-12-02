#ifndef QUEUE_H
#define QUEUE_H

#include "LinkedList.h"

template<typename T>
class Queue {
private:
    LinkedList<T> list;

public:
    Queue() = default;

    void enqueue(const T& item) {
        list.insertRear(item);
    }

    T dequeue() {
        if (list.isEpmty()) {
            throw std::out_of_range("Queue is empty");
        }
        return list.deleteFront();
    }

    T& front() {
        if (list.isEpmty()) {
            throw std::out_of_range("Queue is empty");
        }
        list.reset();
        return list.data();
    }

    bool isEmpty() const {
        return list.isEpmty();
    }

    int size() const {
        return list.getSize();
    }
};

#endif // QUEUE_H
