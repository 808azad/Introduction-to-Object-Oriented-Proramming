#include "Shape.h"
using namespace std;

namespace sdds {

	Shape::~Shape(){}

	ostream& operator<<(ostream& os, const Shape& shape) {
		shape.draw(os);
		return os;
	}

	istream& operator>>(istream& is, Shape& shape) {
		shape.getSpecs(is);
		return is;
	}

}