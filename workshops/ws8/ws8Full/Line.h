#ifndef SDDS_LINE_H
#define SDDS_LINE_H

#include "LbShape.h"

namespace sdds {

	class Line : public LbShape {
		int m_length{};
	public:
		Line();
		Line(const char* line, int lengthOfLine);
		void getSpecs(std::istream& is);
		void draw(std::ostream& os) const;
	};

}


#endif // !SDDS_LINE_H
