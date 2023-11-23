#include <iostream>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    for(int i = 0; i < 4; i++) {
        cout.width(10);
        cout.fill('-'); // fill 成员函数为已经指定的域设置填充字符的值
        cout << values[i] << endl;
    }
    return 0;
}