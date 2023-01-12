// square.h
// This file contains the declaration of the Square class
// The Square class is a derived class of the Shape class and represents a square shape.
// It contains properties and methods specific to a square such as side length.
//
// Properties:
// - area: double, the area of the square
// - perimeter: double, the perimeter of the square
// - origin: Point, the origin of the square
// - is_circular: bool, whether the square is circular or not
// - points: std::vector<Point*>, the points that make up the square
// - side: double, the side length of the square
//
// Methods:
// - Square(): default constructor
// - Square(double side): constructor, sets side length of the square
// - Square(double x, double y, double side): constructor, sets the origin and side length of the square
// - getPoints(): returns the points that make up the square
// - addPoint(Point point): adds a point to the square
// - calculateArea(): calculates the area of the square
// - calculatePerimeter(): calculates the perimeter of the square
// - calculatePoints(): calculates the points that make up the square
// - toString(): returns a string representation of the square
// - move(double x_translation, double y_translation): moves the square by x and y translation
// - scale(double multiplier): scales the square by a multiplier
// - scale(double x_multiplier, double y_multiplier): scales the square by x and y multipliers
// - operator<<(std::ostream& out, Square& square): overloads the output operator

#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "shape.h"
#include "movable.h"

class Square : public Shape, public Movable {
private:
	double area;
	double perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
	double side;
public:
	Square();
	Square(double side);
	Square(double x, double y, double side);
	const std::vector<Point*>& getPoints() const;
	void addPoint(Point point) override;
	void calculateArea() override;
	void calculatePerimeter() override;
	std::string toString() override;
	void calculatePoints() override;
	void move(double x_translation, double y_translation) override;
	void scale(double multiplier) override;
	void scale(double x_multiplier, double y_multiplier) override;
	friend std::ostream& operator<<(std::ostream& out, Square& square);
};