#include <iostream>
#include <deque>

int main() {
    std::deque<int> A; // 声明整型双向队列A
    std::deque<int> B; // 声明整型双向队列B

    // 向A中插入5个元素
    for (int i = 1; i <= 5; ++i) {
        A.push_back(i);
    }

    // 向B中插入5个元素
    for (int i = 6; i <= 10; ++i) {
        B.push_back(i);
    }

    // 将B中的元素加入A的尾部
    A.insert(A.end(), B.begin(), B.end());

    // 打印A中的元素
    for (int elem : A) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    return 0;
}
