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

Square::Square(int side) {
	origin = (Point(0, 0));
	this->side = side;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

Square::Square(int x, int y, int side) {
	origin = (Point(x, y));
	this->side = side;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

void Square::initialisePoints() {
	int min_x = origin.getPoint().first;
	int min_y = origin.getPoint().second;
	int max_x = origin.getPoint().first + side;
	int max_y = origin.getPoint().second + side;

	addPoint(origin);
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
	int min_x = origin.getPoint().first;
	int min_y = origin.getPoint().second;
	int max_x = origin.getPoint().first + side;
	int max_y = origin.getPoint().second + side;

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

void Square::move(int x_translation, int y_translation) {
	Point translation(x_translation, y_translation);
	origin = origin + translation;
	update();
}

void Square::scale(int multiplier) {
	side = side * multiplier;
	update();
}

void Square::scale(int x_multiplier, int y_multiplier) {
	throw std::invalid_argument("Error: Square type can only be scaled equally");
}

std::ostream& operator<<(std::ostream& out, Square& square) {
	out << square.toString();
	return out;
}