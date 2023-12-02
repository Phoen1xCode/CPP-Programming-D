#include "queue.h"
#include <iostream>

int main() {
    Queue<int> queue;

    for (int i = 1; i <= 5; ++i) {
        queue.enqueue(i);
    }

    std::cout << "Dequeued elements from the queue:" << std::endl;
    while (!queue.isEmpty()) {
        std::cout << queue.dequeue() << " ";
    }
    std::cout << std::endl;

    return 0;
}
