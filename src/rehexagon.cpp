#include "rehexagon.hpp"
#include "point.hpp"
#include <cmath>

Rehexagon::Rehexagon(double side, Point center) : side_length(side), center(center) {
    Point point = center + Point{side*std::cos(240*M_PI/180), side*std::sin(240*M_PI/180)};
    points.push_back(point);
    for(int deg = 0; deg < 360; deg += 60) {
        point = point + Point{side*std::cos(deg*M_PI/180), side*std::sin(deg*M_PI/180)};
        points.push_back(point);
    }
}

double Rehexagon::area() const {
    return 3 * side_length * side_length * std::sqrt(3) / 2;
}