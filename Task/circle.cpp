#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "circle.h"

const double pi = 3.1415927; // Initialising a const pi variable

// Default constructor initializing origin at (0,0), radius, area and perimeter to 0, and sets is_circular to true
Circle::Circle() {
	origin = (Point(0, 0));
	radius = 0;
	area = 0;
	perimeter = 0;
	is_circular = true;
	update();
}

// Initializes radius to given value, origin at (0,0), area and perimeter to 0, and sets is_circular to true
Circle::Circle(double radius) {
	origin = (Point(0, 0));
	this->radius = radius;
	area = 0;
	perimeter = 0;
	is_circular = true;
	update();
}

// Initializes radius, x and y coordinates to given values, area and perimeter to 0, and sets is_circular to true
Circle::Circle(double x, double y, double radius) {
	origin = (Point(x, y));
	this->radius = radius;
	area = 0;
	perimeter = 0;
	is_circular = true;
	update();
}

// Returns a const reference to the points vector
const std::vector<Point*>& Circle::getPoints() const {
	return points;
}

// Adds a point to the points vector
void Circle::addPoint(Point point) {
	points.push_back(new Point(point));
}

// Calculates the area of the circle using radius and pi
void Circle::calculateArea() {
	auto calculateArea = [this]() { return pi * radius * radius; };
	area = calculateArea();
}

// Calculates the perimeter of the circle using radius and pi
void Circle::calculatePerimeter() {
	perimeter = 2 * pi * radius;
}

// Clears the points vector and calculates the 2 corner points of the circle
void Circle::calculatePoints() {
	points.clear();
	double min_x = origin.getPoint().first;
	double min_y = origin.getPoint().second;
	double max_x = origin.getPoint().first + 2 * radius;
	double max_y = origin.getPoint().second + 2 * radius;

	addPoint(origin);
	Point corner2(max_x, max_y);
	addPoint(corner2);
}

// Returns a string description of the circle including origin, radius, area, perimeter and corner points
std::string Circle::toString() {
	std::stringstream description;
	description << "\n==========Circle==========\n"
		<< "Origin: " << origin.toString() << "\n"
		<< "Radius: " << radius << "\n"
		<< "Area: " << area << "\n"
		<< "Perimeter: " << perimeter << "\n";
	for (auto point : points) {
		description << (*point).toString() << " ";
	}
	return description.str();
}

// Moves the circle based on the user inputted translation
void Circle::move(double x_translation, double y_translation) {
	// Point translation(x_translation, y_translation);
	// origin = origin + translation;
	origin.setPoint(x_translation, y_translation);
	update();
}

// Scales the circle based on the user inputted multiplier
void Circle::scale(double multiplier) {
	double t_radius = radius;
	radius = t_radius * multiplier;
	update();
}

// Scales the circle based on the user inputted multipliers for both the x and y axis
void Circle::scale(double x_multiplier, double y_multiplier) {
	throw std::invalid_argument("Error: Circle type can only be scaled equally");
}

// Overload the << operator to output the circle's toString method
std::ostream& operator<<(std::ostream& out, Circle& circle) {
	out << circle.toString();
	return out;
}