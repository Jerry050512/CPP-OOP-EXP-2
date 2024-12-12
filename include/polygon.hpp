#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <iostream>
#include <vector>
#include <point.hpp>
#include <shape.hpp>

class Polygon : public Shape {
protected:
    std::vector<Point> points;
public:
    Polygon() {}
    Polygon(std::vector<Point> points) : points(points) {}
    virtual double area() const = 0;
    double perimeter() const override;
    void draw() const override;
};

#endif // POLYGON_HPP