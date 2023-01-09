#pragma once
#include <iostream>

class Point {
private:
    int x;
    int y;
public:
    Point();
    Point(int x, int y);
    std::pair<int, int> getPoint() const;
    void setPoint(int x, int y);
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
    Point operator*(int multiplier) const {
        return Point(x * multiplier, y * multiplier);
    }
};