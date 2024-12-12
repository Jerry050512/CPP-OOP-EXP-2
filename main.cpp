#include <iostream>
#include <graphics.h>
#include <transform.hpp>
#include <vector>
#include <shape.hpp>
#include <etriangle.hpp>
#include <parallelogram.hpp>
#include <square.hpp>
#include <rehexagon.hpp>
#include "circle.hpp"

using namespace std;

int main() {
    setcaption("Shapes Demo");
    initgraph(1000, 800);
    Point origin {0, 0};
    transform.update_origin();
    vector<Shape*> shapes;
    shapes.push_back(new ETriangle(50.0, origin));
    shapes.push_back(new Parallelogram(25, 50, 60, origin));
    shapes.push_back(new Square(50, origin));
    shapes.push_back(new Rehexagon(50, origin));
    shapes.push_back(new Circle(50, origin));
    for(auto shape : shapes) {
        shape->draw();
        cout << "Perimeter: " << shape->perimeter() << endl;
        cout << "Area: " << shape->area() << endl;
        delay(500);
        clearviewport();
    }

    getch();
    closegraph();
    return 0;
}