#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "polygon.hpp"
#include "point.hpp"

class Parallelogram : public Polygon {
private:
    double a, b, degree;
    Point base;
public:
    Parallelogram(double a, double b, double degree, Point base);
    double area() const override;
};

#endif // PARALLELOGRAM_HPP