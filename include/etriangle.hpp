#ifndef ETRIANGLE_HPP
#define ETRIANGLE_HPP

#include <polygon.hpp>
#include <point.hpp>

class ETriangle : public Polygon {
private:
    Point p1, p2, p3;
    double a;
    Point center;
public:
    ETriangle(double a, Point center);

    double area() const override;
};

#endif // ETRIANGLE_HPP