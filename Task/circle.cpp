#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "circle.h"

const int pi = 3.1415927;

Circle::Circle() {
	origin = (Point(0, 0));
	radius = 0;
	area = 0;
	perimeter = 0;
	is_circular = true;
	initialisePoints();
	update();
}

Circle::Circle(int radius) {
	origin = (Point(0, 0));
	this->radius = radius;
	area = 0;
	perimeter = 0;
	is_circular = true;
	initialisePoints();
	update();
}

Circle::Circle(int x, int y, int radius) {
	origin = (Point(x, y));
	this->radius = radius;
	area = 0;
	perimeter = 0;
	is_circular = true;
	initialisePoints();
	update();
}

void Circle::initialisePoints() {
	int min_x = origin.getPoint().first;
	int min_y = origin.getPoint().second;
	int max_x = origin.getPoint().first + 2 * radius;
	int max_y = origin.getPoint().second + 2 * radius;

	addPoint(origin);
	Point corner2(max_x, min_y);
	addPoint(corner2);
}

const std::vector<Point*>& Circle::getPoints() const {
	return points;
}

void Circle::addPoint(Point& point) {
	points.push_back(&point);
}

void Circle::calculateArea() {
	area = pi * radius * radius;
}

void Circle::calculatePerimeter() {
	perimeter = 2 * pi * radius;
}

void Circle::calculatePoints() {
	
	int min_x = origin.getPoint().first;
	int min_y = origin.getPoint().second;
	int max_x = origin.getPoint().first + 2 * radius;
	int max_y = origin.getPoint().second + 2 * radius;

	points[1]->setPoint(max_x, max_y);
}

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

void Circle::move(int x_translation, int y_translation) {
	Point translation(x_translation, y_translation);
	origin = origin + translation;
	update();
}

void Circle::scale(int multiplier) {
	radius = radius * multiplier;
	update();
}

void Circle::scale(int x_multiplier, int y_multiplier) {
	throw std::invalid_argument("Error: Square type can only be scaled equally");
}

std::ostream& operator<<(std::ostream& out, Circle& circle) {
	out << circle.toString();
	return out;
}