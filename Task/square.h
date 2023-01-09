#pragma once
#include <iostream>
#include <vector>
#include "point.h"
#include "shape.h"
#include "movable.h"

class Square : public Shape, public Movable {
private:
	
	int area;
	int perimeter;
	Point origin;
	bool is_circular;
	std::vector<Point*> points;
	int side;
public:
	Square();
	Square(int side);
	Square(int x, int y, int side);
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
	friend std::ostream& operator<<(std::ostream& out, Square& square);
};