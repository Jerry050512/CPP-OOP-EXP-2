#ifndef REHEXAGON_HPP
#define REHEXAGON_HPP

#include "polygon.hpp"
#include "point.hpp"

class Rehexagon : public Polygon {
private:
    double side_length;
    Point center;
public:
    Rehexagon(double side_length, Point center);

    double area() const override;
};

#endif // REHEXAGON_HPP