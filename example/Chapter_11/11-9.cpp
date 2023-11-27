#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

// 定义一个结构体，用于存储员工的ID和薪资信息
struct SalaryInfo {
    unsigned id;
    double salary;
};

int main() {
    // 创建一个SalaryInfo类型的变量并初始化
    SalaryInfo employee1 = {600002, 8000};
    
    // 创建一个ofstream对象，用于写文件
    ofstream os;
    // 以二进制模式打开文件"payroll"进行写操作
    os.open("payroll", ios_base::out | ios_base::binary);
    // 将employee1的数据以二进制形式写入文件
    os.write(reinterpret_cast<char *>(&employee1), sizeof(employee1));
    // 关闭文件
    os.close();

    // 创建一个ifstream对象，用于读文件
    ifstream is;
    // 以二进制模式打开文件"payroll"进行读操作
    is.open("payroll", ios_base::in | ios_base::binary);
    // 检查文件是否成功打开
    if(is) {
        // 创建一个SalaryInfo类型的变量用于接收读取的数据
        SalaryInfo employee2;
        // 从文件中读取数据到employee2
        is.read(reinterpret_cast<char *>(&employee2), sizeof(employee2));
        // 输出读取的数据
        cout << employee2.id << " " << employee2.salary << endl;
    }
    else {
        // 如果文件打开失败，输出错误信息
        cout << "ERROR: Cannot open file 'payroll'." << endl;
    }
    // 关闭文件
    is.close();
    return 0;
}
