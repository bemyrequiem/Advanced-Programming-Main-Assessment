#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "rectangle.h"

// Default constructor initializing origin at (0,0), width, height, area and perimeter to 0, and sets is_circular to false
Rectangle::Rectangle() {
	origin = (Point(0, 0));
	width = 0;
	height = 0;
	area = 0;
	perimeter = 0;
	is_circular = false;
	update();
}

// Initializes width and height to given values, origin at (0,0), area and perimeter to 0, and sets is_circular to false
Rectangle::Rectangle(double width, double height) {
	origin = (Point(0, 0));
	this->width = width;
	this->height = height;
	area = 0;
	perimeter = 0;
	is_circular = false;
	update();
}

// Initializes width, height, x and y coordinates to given values, area and perimeter to 0, and sets is_circular to false
Rectangle::Rectangle(double x, double y, double width, double height) {
	origin = (Point(x, y));
	this->width = width;
	this->height = height;
	area = 0;
	perimeter = 0;
	is_circular = false;
	update();
}

// Returns a const reference to the points vector
const std::vector<Point*>& Rectangle::getPoints() const {
	return points;
}

// Adds a point to the points vector
void Rectangle::addPoint(Point point) {
	points.push_back(new Point(point));
}

// Calculates the area of the rectangle using width and height
void Rectangle::calculateArea() {
	auto calculateArea = [this]() { return width * height; };
	area = calculateArea();
}

// Calculates the perimeter of the rectangle using width and height
void Rectangle::calculatePerimeter() {
	perimeter = width * 2 + height * 2;
}

// Clears the points vector and calculates the 4 corner points of the rectangle
void Rectangle::calculatePoints() {
	points.clear();
	double min_x = origin.getPoint().first;
	double min_y = origin.getPoint().second;
	double max_x = origin.getPoint().first + width;
	double max_y = origin.getPoint().second + height;

	addPoint(origin);
	Point corner2(max_x, min_y);
	addPoint(corner2);
	Point corner3(max_x, max_y);
	addPoint(corner3);
	Point corner4(min_x, max_y);
	addPoint(corner4);
}

// Returns a string description of the rectangle including origin, width, height, area, perimeter and corner points
std::string Rectangle::toString() {
	std::stringstream description;
	description << "\n==========Rectangle==========\n"
		<< "Origin: " << origin.toString() << "\n"
		<< "Width: " << width << "\n"
		<< "Height: " << height << "\n"
		<< "Area: " << area << "\n"
		<< "Perimeter: " << perimeter << "\n";
	for (auto point : points) {
		description << (*point).toString() << " ";
	}
	return description.str();
}

// Moves the rectangle based on the user inputted translation
void Rectangle::move(double x_translation, double y_translation) {
	// Point translation(x_translation, y_translation);
	// origin = origin + translation;
	origin.setPoint(x_translation, y_translation);
	update();
}

// Scales the rectangle based on the user inputted multiplier
void Rectangle::scale(double multiplier) {
	double t_width = width;
	double t_height = height;
	width = t_width * multiplier;
	height = t_height * multiplier;
	update();
}

// Scales the rectangle based on the user inputted multipliers for both the x and y axis
void Rectangle::scale(double x_multiplier, double y_multiplier) {
	double t_width = width;
	double t_height = height;
	width = t_width * x_multiplier;
	height = t_height * y_multiplier;
	update();
}

// Overload the << operator to output the rectangle's toString method
std::ostream& operator<<(std::ostream& out, Rectangle& rectangle) {
	out << rectangle.toString();
	return out;
}