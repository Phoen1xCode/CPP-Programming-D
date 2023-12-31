#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

// 结构体 Student
struct Student {
    int id; // 学号
    float gpa; // 平均分
};

template <class T> // 类模板：实现对任意类型数据进行存取
class Store {
public:
    Store(); // 缺省形式（无形参）的构造函数
    T &getElem(); // 提取数据函数
    void putElem(const T &x); // 存入数据函数
private:
    T item;  // item用于存放任意类型的数据
    bool haveValue; // havevalue标记item是否已被存入内容
};

// 实现store类的各成员函数
template <class T> // 缺省构造函数的实现
Store<T>::Store() : haveValue(false) {}

template <class T>
T &Store<T>::getElem() {
    if(!haveValue) { // 如果试图提取未初始化的数据，则终止程序
        cout << "No item present!" << endl;
        exit(1); // 使程序完全退出，返回到操作系统
        // 参数可用来表示程序终止的原因，可以被操作系统接收
    }s
}

template <class T>  //存入数据函数的实现   
void Store<T>::putElem(const T &x) {
    haveValue = true; // 将haveValue置为true,表示item中以存入数值
    item = x; // 将x值存入item
}

int main() {
    Store<int>s1, s2; // 定义两个Store<int>类对象，其中数据成员item为int类型
    s1.putElem(3); // 向对象s1中存入数据（初始化对象s1）
    s2.putElem(-7); // 向对象s2中存入数据（初始化对象s2）
    cout << s1.getElem() << " " << s2.getElem() << endl; // 输出对象s1和s2的数据成员

    Student g = {1000, 23}; // 定义Student类型结构体变量的同时赋以初始值
    Store<Student>s3; // 定义Store<Student>类对象s3,其中数据成员item为Student类型
    s3.putElem(g); // 向对象s3中存入数据（初始化对象s3）
    cout << "The student id is " << s3.getElem().id << endl; //输出对象s3的数据成员
    
    Store<double>d; // 定义Store<double>类对象id,其中数据成员item为double类型
    cout << "Retrieving object d...";
    cout << d.getElem() << endl; // 输出对象d的数据成员
    // 由于d未经初始化，在执行函数d.getElement()过程中导致程序终止

    return 0;
}