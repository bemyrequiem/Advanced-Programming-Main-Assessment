#include "shape.h"
#include "circle.h"
#include "rectangle.h"
#include "square.h"
#include "movable.h"

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

std::ostream& operator<<(std::ostream& out, Shape& shape) {
	out << shape.toString();
	return out;
}

int main() {
	Circle c(10, 10, 5);

	cout << c << endl;
}