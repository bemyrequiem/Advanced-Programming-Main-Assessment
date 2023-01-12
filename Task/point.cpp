#include <iostream>
#include <sstream>
#include "point.h"

// Default constructor that sets x and y coordinates to 0
Point::Point() : x(0), y(0) {} 

// Constructor that sets x and y coordinates to passed in values
Point::Point(double x, double y) : x(x), y(y) {} 

// Getter for point coordinates
std::pair<double, double> Point::getPoint() const {
	return std::make_pair(x, y);
}

// Setter for point coordinates
void Point::setPoint(double new_x, double new_y) {
	x = new_x;
	y = new_y;
}

// Converts point coordinates to a string in the format (x, y)
std::string Point::toString() {
	std::stringstream description;
	description << "(" << x << ", " << y << ")";
	return description.str();
}