#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>

class Point {
private:
    double x;
    double y;

public:
    Point(double x=0, double y=0) : x(x), y(y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
    Point normalize();
    double distance(const Point& other) const;
    double length() const;

    Point operator-(const Point& other) const;
    Point operator+(const Point& other) const;
    Point operator*(const double scalar) const;
    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

using Vector2D = Point;

#endif // POINT_HPP