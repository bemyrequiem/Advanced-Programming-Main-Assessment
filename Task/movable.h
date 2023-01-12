#pragma once
#include <iostream>
#include <vector>
#include "point.h"

class Movable {
public:
	virtual void move(double x_translation , double y_translation) = 0;
	virtual void scale(double multiplier) = 0;
	virtual void scale(double x_multiplier, double y_multiplier) = 0;
};