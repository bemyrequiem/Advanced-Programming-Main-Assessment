#pragma once
#include <iostream>

class Point {
private:
    double x;
    double y;
public:
    Point();
    Point(double x, double y);
    std::pair<double, double> getPoint() const;
    void setPoint(double x, double y);
    std::string toString();
    Point operator+(Point& other_point) const {
        return Point(x + other_point.getPoint().first, y + other_point.getPoint().second);
    }
    Point operator-(Point& other_point) const {
        return Point(x - other_point.getPoint().first, y - other_point.getPoint().second);
    }
    Point operator*(Point& other_point) const {
        return Point(x * other_point.getPoint().first, y * other_point.getPoint().second);
    }
    Point operator*(double multiplier) const {
        return Point(x * multiplier, y * multiplier);
    }
};