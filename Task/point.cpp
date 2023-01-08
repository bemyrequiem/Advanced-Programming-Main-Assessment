#include <iostream>
#include <sstream>
#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(float x, float y) : x(x), y(y) {}

std::pair<float, float> Point::getPoint() const {
	return std::make_pair(x, y);
}

void Point::setPoint(float new_x, float new_y) {
	x = new_x;
	y = new_y;
}

std::string Point::toString() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}