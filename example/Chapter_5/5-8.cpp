#include <iostream>
#include <cmath>

using namespace std;

class A{
public:
    A(int i) : a(i) {}
    void print();
private:
    const int a;
    static const int b;
};

const int A::b = 10;

void A::print(){
    cout << a << ":" << b << endl;
}

int main(){
    A a1(100), a2(0);
    a1.print();
    a2.print();
    return 0;
}