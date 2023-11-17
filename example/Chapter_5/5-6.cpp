#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.141592635897;


class Point
{
public:
    Point() = default;
    Point(int x = 0, int y = 0) : x(x), y(y) { count++; }
    Point(Point &p)
    {
        x = p.x;
        y = p.y;
        count++;
    }
    ~Point() { count--; }
    int getX() { return x; }
    int getY() { return y; }

    static void showCount()
    {
        cout << "Object count = " << count << endl;
    }
    friend float dist(Point &p1, Point &p2); // Friend function declaration

private:
    int x, y;
    static int count;
    constexpr static int origin = 0;
};

int Point::count = 0;
constexpr static int origin = 0;

float dist(Point &p1, Point &p2) // Friend function implementation
{
    double x = p1.x - p2.x;
    double y = p1.y - p2.y;
    return static_cast<float>(sqrt(x * x + y * y));
}

int main()
{
    Point myp1(1,1), myp2(4,5);
    cout << "The distance is : " << dist(myp1, myp2) << endl;

    return 0;
}