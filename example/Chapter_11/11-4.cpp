#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    double values[] = {1.23, 35.36, 653.7, 4358.24};
    string names[] = {"Zoot", "Jimmy", "AI", "Stan"};
    for(int i = 0; i < 4; i++)
    cout << setiosflags(ios_base::scientific)
         << setiosflags(ios_base::left)
         << setw(6) << names[i]
         << setiosflags(ios_base::left)
         << setw(10) << setprecision(1) << values[i] << endl;
    return 0;
}