#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "square.h"

Square::Square() {
	origin = (Point(0, 0));
	side = 0;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

Square::Square(float side) {
	origin = (Point(0, 0));
	this->side = side;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

Square::Square(float x, float y, float side) {
	origin = (Point(x, y));
	this->side = side;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

void Square::initialisePoints() {
	float min_x = origin.getPoint().first;
	float min_y = origin.getPoint().second;
	float max_x = origin.getPoint().first + side;
	float max_y = origin.getPoint().second + side;

	Point corner1(min_x, min_y);
	addPoint(corner1);
	Point corner2(max_x, min_y);
	addPoint(corner2);
	Point corner3(max_x, max_y);
	addPoint(corner3);
	Point corner4(min_x, max_y);
	addPoint(corner4);
}

const std::vector<Point*>& Square::getPoints() const {
	return points;
}

void Square::addPoint(Point& point) {
	points.push_back(&point);
}

void Square::calculateArea() {
	area = side * side;
}

void Square::calculatePerimeter() {
	perimeter = side * 4;
}

void Square::calculatePoints() {
	float min_x = origin.getPoint().first;
	float min_y = origin.getPoint().second;
	float max_x = origin.getPoint().first + side;
	float max_y = origin.getPoint().second + side;

	points[0]->setPoint(min_x, min_y);
	points[1]->setPoint(max_x, min_y);
	points[2]->setPoint(max_x, max_y);
	points[3]->setPoint(min_x, max_y);
}

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

void Square::move(float x_translation, float y_translation) {
	Point translation(x_translation, y_translation);
	origin = origin + translation;
	update();
}

void Square::scale(float multiplier) {
	side = side * multiplier;
	update();
}

void Square::scale(float x_multiplier, float y_multiplier) {
	throw std::invalid_argument("Error: Square type can only be scaled equally");
}

std::ostream& operator<<(std::ostream& out, Square& square) {
	out << square.toString();
	return out;
}