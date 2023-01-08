#pragma once
#include <iostream>

class Point {
private:
    float x;
    float y;
public:
    Point();
    Point(float x, float y);
    std::pair<float, float> getPoint() const;
    void setPoint(float x, float y);
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
    Point operator*(float multiplier) const {
        return Point(x * multiplier, y * multiplier);
    }
};