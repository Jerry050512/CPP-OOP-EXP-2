#include <graphics.h>
#include <polygon.hpp>
#include <transform.hpp>

double Polygon::perimeter() const {
    double perimeter = 0;
    for (int i = 0; i < points.size() - 1; i++) {
        perimeter += points[i].distance(points[i + 1]);
    }
    perimeter += points[points.size() - 1].distance(points[0]);
    return perimeter;
}

void Polygon::draw() const {
    for (int i = 0; i < points.size() - 1; i++) {
        transform.draw_line(points[i], points[i + 1]);
    }
    transform.draw_line(points[points.size() - 1], points[0]);
}