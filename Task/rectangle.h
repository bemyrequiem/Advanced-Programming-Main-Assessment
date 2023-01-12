// rectangle.h
// This file contains the declaration of the Rectangle class, which inherits from the Shape class
// The Rectangle class contains properties and methods specific to rectangles such as width and height.
// It also overrides the pure virtual methods from the Shape class to provide the functionality for rectangles.
//
// Properties:
// - area: double, the area of the rectangle
// - perimeter: double, the perimeter of the rectangle
// - origin: Point, the origin of the rectangle
// - is_circular: bool, whether the rectangle is circular or not
// - points: std::vector<Point*>, the points that make up the rectangle
// - width: double, the width of the rectangle
// - height: double, the height of the rectangle
//
// Methods:
// - Rectangle(): default constructor
// - Rectangle(double width, double height): constructor with width and height arguments
// - Rectangle(double x, double y, double width, double height): constructor with origin, width and height arguments
// - getPoints(): returns the points that make up the rectangle
// - addPoint(Point point): adds a point to the rectangle
// - calculateArea(): calculates the area of the rectangle
// - calculatePerimeter(): calculates the perimeter of the rectangle
// - calculatePoints(): calculates the points that make up the rectangle
// - toString(): returns a string representation of the rectangle
// - move(double x_translation, double y_translation): moves the rectangle by x and y translation
// - scale(double multiplier): scales the rectangle by a multiplier
// - scale(double x_multiplier, double y_multiplier): scales the rectangle by x and y multipliers
// - friend std::ostream& operator<<(std::ostream& out, Rectangle& rectangle): overloading the output operator

#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "shape.h"
#include "movable.h"

class Rectangle : public Shape, public Movable {
private:
	double area;
	double perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
	double width;
	double height;
public:
	Rectangle();
	Rectangle(double width, double height);
	Rectangle(double x, double y, double width, double height);
	const std::vector<Point*>& getPoints() const;
	void addPoint(Point point) override;
	void calculateArea() override;
	void calculatePerimeter() override;
	std::string toString() override;
	void calculatePoints() override;
	void move(double x_translation, double y_translation) override;
	void scale(double multiplier) override;
	void scale(double x_multiplier, double y_multiplier) override;
	friend std::ostream& operator<<(std::ostream& out, Rectangle& rectangle);
};