#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "shape.h"
#include "movable.h"

class Square : public Shape, public Movable {
private:
	float area;
	float perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
	float side;
public:
	Square();
	Square(float side);
	Square(float x, float y, float side);
	void initialisePoints();
	const std::vector<Point*>& getPoints() const;
	void addPoint(Point& point) override;
	void calculateArea() override;
	void calculatePerimeter() override;
	std::string toString() override;
	void calculatePoints() override;
	void move(float x_translation, float y_translation) override;
	void scale(float multiplier) override;
	void scale(float x_multiplier, float y_multiplier) override;
	friend std::ostream& operator<<(std::ostream& out, Square& square);
};