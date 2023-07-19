#include "Line.h"
using namespace std;

namespace sdds {

	Line::Line() : LbShape(){
		m_length = 0;
	}

	Line::Line(const char* line, int lengthOfLine) : LbShape(line) {
		if (lengthOfLine > 0) m_length = lengthOfLine;
	}

	void Line::getSpecs(istream& is = cin) {
		LbShape::getSpecs(is);
		int length;
		is >> length;
		if (length > 0) m_length = length;
		is.ignore(10000, '\n');
	}

	void Line::draw(ostream& os = cout) const {
		if (m_length > 0 && LbShape::label() != nullptr) {
			os << label() << endl;
			for (int i = 0; i < m_length; i++) {
				os << '=';
			}
		}
	}

}