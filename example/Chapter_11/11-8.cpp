// 11-8.cpp 为输入流指定一个终止字符
// 本程序连续读入一串字符，知道遇到字符't'时停止，字符最多不超过99个
#include <iostream>
#include <string>
using namespace std;
int main() {
    string line;
    cout << "Type a line terminated by 't' " << endl;
    getline(cin, line, 't');
    cout << line << endl;
    return 0;
}