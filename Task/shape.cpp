#include <iostream>
#include "point.h"
#include "shape.h"

// Default constructor that sets area and perimeter to 0 and is_circular to NULL
Shape::Shape() : area(0), perimeter(0), is_circular(NULL) {} 

// Destructor that clears the points vector
Shape::~Shape() {
	points.clear();
}

// Function that updates the shape's area, perimeter, and points
void Shape::update() {
	calculatePoints();
	calculateArea();
	calculatePerimeter();
}