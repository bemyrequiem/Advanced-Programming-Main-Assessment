#include <iostream>
#include "point.h"
#include "shape.h"

Shape::Shape() : area(0), perimeter(0), is_circular(NULL) {}

Shape::~Shape() {
	points.clear();
}

void Shape::update() {
	calculateArea();
	calculatePerimeter();
	calculatePoints();
}