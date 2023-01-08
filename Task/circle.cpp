#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "circle.h"

const float pi = 3.1415927f;

Circle::Circle() {
	origin = (Point(0, 0));
	radius = 0;
	area = 0;
	perimeter = 0;
	is_circular = true;
	initialisePoints();
	update();
}

Circle::Circle(float radius) {
	origin = (Point(0, 0));
	this->radius = radius;
	area = 0;
	perimeter = 0;
	is_circular = true;
	initialisePoints();
	update();
}

Circle::Circle(float x, float y, float radius) {
	origin = (Point(x, y));
	this->radius = radius;
	area = 0;
	perimeter = 0;
	is_circular = true;
	initialisePoints();
	update();
}

void Circle::initialisePoints() {
	float min_x = origin.getPoint().first;
	float min_y = origin.getPoint().second;
	float max_x = origin.getPoint().first + 2 * radius;
	float max_y = origin.getPoint().second + 2 * radius;

	Point corner1(min_x, min_y);
	addPoint(corner1);
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
	float min_x = origin.getPoint().first;
	float min_y = origin.getPoint().second;
	float max_x = origin.getPoint().first + 2 * radius;
	float max_y = origin.getPoint().second + 2 * radius;

	points[0]->setPoint(min_x, min_y);
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

void Circle::move(float x_translation, float y_translation) {
	Point translation(x_translation, y_translation);
	origin = origin + translation;
	update();
}

void Circle::scale(float multiplier) {
	radius = radius * multiplier;
	update();
}

void Circle::scale(float x_multiplier, float y_multiplier) {
	throw std::invalid_argument("Error: Square type can only be scaled equally");
}

std::ostream& operator<<(std::ostream& out, Circle& circle) {
	out << circle.toString();
	return out;
}