#include "parallelogram.hpp"
#include <cmath>

Parallelogram::Parallelogram(double a, double b, double degree, Point base) : a(a), b(b), degree(degree), base(base) {
    Point p1 = base;
    Point p2 = base + Point{b, 0};
    Point p3 = base + Point{a * std::cos(degree * M_PI / 180), a * std::sin(degree * M_PI / 180)};
    Point p4 = p3 + Point{b, 0};
    points = {p1, p2, p4, p3};
}

double Parallelogram::area() const {
    return a * b * std::sin(degree * M_PI / 180);
}