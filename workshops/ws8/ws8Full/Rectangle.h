#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H

#include "LbShape.h"

namespace sdds {
	
	class Rectangle : public LbShape {
		int m_width{};
		int m_height{};
	public:
		Rectangle();
		Rectangle(const char* labelString, int width, int height);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};

}

#endif // !SDDS_RECTANGLE_H

