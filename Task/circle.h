// circle.h
// This file contains the declaration of the Circle class
// The Circle class is a derived class of the Shape class and represents a circle shape.
// It contains properties and methods specific to a circle such as radius.
//
// Properties:
// - area: double, the area of the circle
// - perimeter: double, the perimeter of the circle
// - origin: Point, the origin of the circle
// - is_circular: bool, whether the circle is circular or not
// - points: std::vector<Point*>, the points that make up the circle
// - radius: double, the radius of the circle
//
// Methods:
// - Circle(): default constructor
// - Circle(double radius): constructor, sets radius of the circle
// - Circle(double x, double y, double radius): constructor, sets the origin and radius of the circle
// - getPoints(): returns the points that make up the circle
// - addPoint(Point point): adds a point to the circle
// - calculateArea(): calculates the area of the circle
// - calculatePerimeter(): calculates the perimeter of the circle
// - calculatePoints(): calculates the points that make up the circle
// - toString(): returns a string representation of the circle
// - move(double x_translation, double y_translation): moves the circle by x and y translation
// - scale(double multiplier): scales the circle by a multiplier
// - scale(double x_multiplier, double y_multiplier): scales the circle by x and y multipliers
// - operator<<(std::ostream& out, Square& square): overloads the output operator

#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "shape.h"
#include "movable.h"

class Circle : public Shape, public Movable {
private:
	double area;
	double perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
	double radius;
public:
	Circle();
	Circle(double radius);
	Circle(double x, double y, double radius);
	const std::vector<Point*>& getPoints() const;
	void addPoint(Point point) override;
	void calculateArea() override;
	void calculatePerimeter() override;
	std::string toString() override;
	void calculatePoints() override;
	void move(double x_translation, double y_translation) override;
	void scale(double multiplier) override;
	void scale(double x_multiplier, double y_multiplier) override;
	friend std::ostream& operator<<(std::ostream& out, Circle& circle);
};