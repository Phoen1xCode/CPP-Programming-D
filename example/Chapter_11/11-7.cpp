// 11-7.cpp get函数应用举例
#include <iostream>
using namespace std;

int main() {
    char ch;
    while((ch = cin.get()) != EOF) // 当按下Ctrl+Z及Enter键时，程序读入的值是EOF,程序结束。
        cout.put(ch);
    return 0;
}