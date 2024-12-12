#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "parallelogram.hpp"
#include "point.hpp"

class Square : public Parallelogram {
public:
    Square(double side, Point base) : Parallelogram(side, side, 90, base) {}
};

#endif  // SQUARE_HPP