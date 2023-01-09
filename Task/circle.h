#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "shape.h"
#include "movable.h"

class Circle : public Shape, public Movable {
private:
	int area;
	int perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
	int radius;
public:
	Circle();
	Circle(int radius);
	Circle(int x, int y, int radius);
	void initialisePoints();
	const std::vector<Point*>& getPoints() const;
	void addPoint(Point& point) override;
	void calculateArea() override;
	void calculatePerimeter() override;
	std::string toString() override;
	void calculatePoints() override;
	void move(int x_translation, int y_translation) override;
	void scale(int multiplier) override;
	void scale(int x_multiplier, int y_multiplier) override;
	friend std::ostream& operator<<(std::ostream& out, Circle& circle);
};