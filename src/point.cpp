#include <point.hpp>
#include <cmath>

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

Point Point::operator*(const double scalar) const {
    return Point(x * scalar, y * scalar);
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::normalize() {
    double length = sqrt(x * x + y * y);
    x /= length;
    y /= length;
    return *this;
}

double Point::length() const {
    return sqrt(x * x + y * y);
}

double Point::distance(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return sqrt(dx * dx + dy * dy);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;    
}