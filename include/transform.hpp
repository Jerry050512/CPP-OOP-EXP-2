#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <iostream>
#include <point.hpp>
#include <graphics.h>

class Transform {
private:
    Point origin;
    int left, right, top, bottom, unit_length;
public:
    Transform(int unit_length=10) : unit_length(unit_length), origin(left + (right - left) / 2, top + (bottom - top) / 2) {
        
    }

    void update_origin();
    void set_origin(Point origin);
    void set_unit_length(int unit_length);
    Point transform(Point p);
    void draw_line(Point p1, Point p2, double dl=1.0);
    void draw_arc(Point center, double radius, double start_angle, double end_angle, double dtheta=0.1);
    void draw_circle(Point center, double radius, double dtheta=0.1);
};

extern Transform transform;

#endif // TRANSFORM_HPP