#include <iostream>
#include <sstream>
#include "point.h"
#include "shape.h"
#include "movable.h"
#include "rectangle.h"

Rectangle::Rectangle() {
	origin = (Point(0, 0));
	width = 0;
	height = 0;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

Rectangle::Rectangle(int width, int height) {
	origin = (Point(0, 0));
	this->width = width;
	this->height = height;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

Rectangle::Rectangle(int x, int y, int width, int height) {
	origin = (Point(x, y));
	this->width = width;
	this->height = height;
	area = 0;
	perimeter = 0;
	is_circular = false;
	initialisePoints();
	update();
}

void Rectangle::initialisePoints() {
	int min_x = origin.getPoint().first;
	int min_y = origin.getPoint().second;
	int max_x = origin.getPoint().first + width;
	int max_y = origin.getPoint().second + height;

	addPoint(origin);
	Point corner2(max_x, min_y);
	addPoint(corner2);
	Point corner3(max_x, max_y);
	addPoint(corner3);
	Point corner4(min_x, max_y);
	addPoint(corner4);
}

const std::vector<Point*>& Rectangle::getPoints() const {
	return points;
}

void Rectangle::addPoint(Point& point) {
	points.push_back(&point);
}

void Rectangle::calculateArea() {
	area = width * height;
}

void Rectangle::calculatePerimeter() {
	perimeter = width * 2 + height * 2;
}

void Rectangle::calculatePoints() {
	int min_x = origin.getPoint().first;
	int min_y = origin.getPoint().second;
	int max_x = origin.getPoint().first + width;
	int max_y = origin.getPoint().second + height;

	points[1]->setPoint(max_x, min_y);
	points[2]->setPoint(max_x, max_y);
	points[3]->setPoint(min_x, max_y);
}

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

void Rectangle::move(int x_translation, int y_translation) {
	Point translation(x_translation, y_translation);
	origin = origin + translation;
	update();
}

void Rectangle::scale(int multiplier) {
	width = width * multiplier;
	height = height * multiplier;
	update();
}

void Rectangle::scale(int x_multiplier, int y_multiplier) {
	width = width * x_multiplier;
	height = height * y_multiplier;
	update();
}

std::ostream& operator<<(std::ostream& out, Rectangle& rectangle) {
	out << rectangle.toString();
	return out;
}