#include <fstream>
using namespace std;
struct Date {
    int monday, day, year;
};

int main() {
    Date dt = {6, 10, 92};

    ofstream file;
    file.open("date.dat", ios_base::binary);
    // OR ofstream file("date.dat", ios_base::binary);

    file.write(reinterpret_cast<char *>(&dt), sizeof(dt));
    file.close();
    return 0;
}