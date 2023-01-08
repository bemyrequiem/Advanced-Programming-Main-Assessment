#pragma once
#include <iostream>
#include <vector>
#include "point.h"

class Movable {
public:
	virtual void move(float x_translation , float y_translation) = 0;
	virtual void scale(float multiplier) = 0;
	virtual void scale(float x_multiplier, float y_multiplier) = 0;
};