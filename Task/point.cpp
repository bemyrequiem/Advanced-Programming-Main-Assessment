#include <iostream>
#include <sstream>
#include "point.h"

Point::Point() : x(0), y(0) {}

Point::Point(int x, int y) : x(x), y(y) {}

std::pair<int, int> Point::getPoint() const {
	return std::make_pair(x, y);
}

void Point::setPoint(int new_x, int new_y) {
	x = new_x;
	y = new_y;
}

std::string Point::toString() {
	return "(" + std::to_string(x) + ", " + std::to_string(y) + ")";
}