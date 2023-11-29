/*
#include <iostream>
using namespace std;

int divide(int x, int y) {
    if(y == 0)
        throw x;
    return x / y;
}

int main() {
    try {
        cout << "5 / 2 = " << divide(5, 2) << endl;
        cout << "8 / 0 = " << divide(8, 0) << endl;
        cout << "7 / 1 = " << divide(7, 1) << endl;
    } catch(int e) {
        cout << e << " is divided bt zero!" << endl;
    }
    cout << "That is ok." << endl;
    return 0;
}
*/

#include <iostream>
using namespace std;

void divide(int x, int y) {
    if (y == 0) {
        throw x; // Throw an exception if y is 0
    } else {
        cout << x << " / " << y << " = " << x / y << endl;
    }
}

int main() {
    try {
        divide(5, 2); // This will print the result of 5/2
        divide(8, 0); // This will throw an exception
        // The following line will not be executed because of the exception

        
        divide(7, 1); // This line is not needed for the desired output
    } catch (int x) {
        cout << x << " is divided by zero!" << endl;
    }
    cout << "That is ok." << endl;
    return 0;
}
