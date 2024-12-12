#include <etriangle.hpp>
#include <cmath>
#include <vector>
#include <iostream>
#include <point.hpp>

ETriangle::ETriangle(double a, Point center) : a(a), center(center) {
    double radius = a / std::sqrt(3);
    Point p1 = center + Point{0, radius};
    Point p2 = center + Point{-a/2, -radius/2};
    Point p3 = center + Point{a/2, -radius/2};
    points = {p1, p2, p3};
}

double ETriangle::area() const {
    return a * a * std::sqrt(3) / 4;
}