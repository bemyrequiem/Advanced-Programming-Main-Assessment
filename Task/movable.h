#pragma once
#include <iostream>
#include <vector>
#include "point.h"

class Movable {
public:
	virtual void move(int x_translation , int y_translation) = 0;
	virtual void scale(int multiplier) = 0;
	virtual void scale(int x_multiplier, int y_multiplier) = 0;
};