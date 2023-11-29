#include <iostream>
#include <cmath>
#include <stdexcept>

using namespace std;

// 给出三角形边长 计算三角形面积
double area(double a, double b, double c) throw(invalid_argument) {
    // 判断三角形边长是否为正
    if(a <= 0 || b <= 0 || c <= 0)
        throw invalid_argument("the side length should be positive.");
    // 判断三角形边长是否满足三角公式
    if(a + b <= c || a + c <= b || b + c <= a)
        throw invalid_argument("the side length should fit the triangle inequation");
    // 由Heron公式计算三角形面积
    double s = (a + b + c) / 2;
    return sqrt(s * (s - a) * (s - b) * (s - c));
};