#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "square.h"

// Default constructor initializing origin at (0,0), side length, area and perimeter to 0, and sets is_circular to false
Square::Square() {
	origin = (Point(0, 0));
	side = 0;
	area = 0;
	perimeter = 0;
	is_circular = false;
	update();
}

// Initializes side length to given value, origin at (0,0), area and perimeter to 0, and sets is_circular to false
Square::Square(double side) {
	origin = (Point(0, 0));
	this->side = side;
	area = 0;
	perimeter = 0;
	is_circular = false;
	update();
}

// Initializes side length, x and y coordinates to given values, area and perimeter to 0, and sets is_circular to false
Square::Square(double x, double y, double side) {
	origin = (Point(x, y));
	this->side = side;
	area = 0;
	perimeter = 0;
	is_circular = false;
	update();
}

// Returns a const reference to the points vector
const std::vector<Point*>& Square::getPoints() const {
	return points;
}

// Adds a point to the points vector
void Square::addPoint(Point point) {
	points.push_back(new Point(point));
}

// Calculates the area of the square using side length
void Square::calculateArea() {
	auto calculateArea = [this]() { return side * side; };
	area = calculateArea();
}

// Calculates the perimeter of the square using side length
void Square::calculatePerimeter() {
	perimeter = side * 4;
}

// Clears the points vector and calculates the 4 corner points of the square
void Square::calculatePoints() {
	points.clear();
	double min_x = origin.getPoint().first;
	double min_y = origin.getPoint().second;
	double max_x = origin.getPoint().first + side;
	double max_y = origin.getPoint().second + side;

	addPoint(origin);
	Point corner2(max_x, min_y);
	addPoint(corner2);
	Point corner3(max_x, max_y);
	addPoint(corner3);
	Point corner4(min_x, max_y);
	addPoint(corner4);
}

// Returns a string description of the square including origin, side length, area, perimeter and corner points
std::string Square::toString() {
	std::stringstream description;
	description << "\n==========Square==========\n"
		<< "Origin: " << origin.toString() << "\n"
		<< "Side: " << side << "\n"
		<< "Area: " << area << "\n"
		<< "Perimeter: " << perimeter << "\n";
	for (auto point : points) {
		description << (*point).toString() << " ";
	}
	return description.str();
}

// Moves the square based on the user inputted translation
void Square::move(double x_translation, double y_translation) {
	// Point translation(x_translation, y_translation);
	// origin = origin + translation;
	origin.setPoint(x_translation, y_translation);
	update();
}

// Scales the square based on the user inputted multiplier
void Square::scale(double multiplier) {
	double t_side = side;
	side = t_side * multiplier;
	update();
}

// Scales the square based on the user inputted multipliers for both the x and y axis
void Square::scale(double x_multiplier, double y_multiplier) {
	throw std::invalid_argument("Error: Square type can only be scaled equally");
}

// Overload the << operator to output the square's toString method
std::ostream& operator<<(std::ostream& out, Square& square) {
	out << square.toString();
	return out;
}