// shape.h
// This file contains the declaration of the Shape class
// The Shape class is the base class for all shapes and contains the common properties and methods
// for all shapes such as origin, area, perimeter, and points.
// The class also includes pure virtual methods that must be implemented by derived classes
// to complete the functionality of the class.
//
// Properties:
// - area: double, the area of the shape
// - perimeter: double, the perimeter of the shape
// - origin: Point, the origin of the shape
// - is_circular: bool, whether the shape is circular or not
// - points: std::vector<Point*>, the points that make up the shape
//
// Methods:
// - Shape(): default constructor
// - ~Shape(): destructor
// - addPoint(Point point): pure virtual method, adds a point to the shape
// - getPoints(): pure virtual method, returns the points that make up the shape
// - calculateArea(): pure virtual method, calculates the area of the shape
// - calculatePerimeter(): pure virtual method, calculates the perimeter of the shape
// - calculatePoints(): pure virtual method, calculates the points that make up the shape
// - toString(): pure virtual method, returns a string representation of the shape
// - update(): protected method, updates the area, perimeter and points of the shape

#pragma once
#include <iostream>
#include <vector>
#include "point.h"

class Shape {

private:
	double area;
	double perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
protected:
	void update();
public:
	Shape();
	~Shape();
	virtual void addPoint(Point point) = 0;
	virtual const std::vector<Point*>& getPoints() const = 0;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	virtual std::string toString() = 0;
};