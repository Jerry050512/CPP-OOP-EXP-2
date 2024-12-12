#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "point.hpp"
#include <cmath>
#include "transform.hpp"

class Circle : public Shape {
private:
    double radius;
    Point center;
public:
    Circle(double r, Point c) : radius(r), center(c) {}
    
    double perimeter() const override {
        return 2 * M_PI * radius;
    }
    
    double area() const override {
        return M_PI * radius * radius;
    }

    void draw() const override {
        transform.draw_circle(center, radius);
    }
};

#endif // CIRCLE_HPP