#pragma once
#include <iostream>
#include <vector>
#include "point.h"

class Shape {

private:
	
	int area;
	int perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
protected:
	void update();
public:
	Shape();
	~Shape();
	virtual void initialisePoints() = 0;
	virtual void addPoint(Point& point) = 0;
	virtual const std::vector<Point*>& getPoints() const = 0;
	virtual void calculateArea() = 0;
	virtual void calculatePerimeter() = 0;
	virtual void calculatePoints() = 0;
	virtual std::string toString() = 0;
};