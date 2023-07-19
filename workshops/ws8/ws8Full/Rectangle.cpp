#include <iomanip>
#include "Rectangle.h"
using namespace std;

namespace sdds {

	Rectangle::Rectangle() : LbShape() {
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* labelString, int width, int height) : LbShape(labelString) {
		if (width > 0 && height > 0) {
			if (height >= 3 && width >= strlen(label() + 2)) {
				m_width = width;
				m_height = height;
			}
			else {
				m_width = 0;
				m_height = 0;
			}
		}
	}

	void Rectangle::getSpecs(istream& is = cin) {
		LbShape::getSpecs(is);
		int width;
		int height;
		is >> width;
		is.ignore();
		is >> height;
		if (width > 0 && height > 0) {
			if (height >= 3 && width >= strlen(label() + 2)) {
				m_width = width;
				m_height = height;
			}
		}
		is.ignore(10000, '\n');
	}

	void Rectangle::draw(ostream& os = cout) const {
		if (m_width > 0 && m_height > 0 && label() != nullptr && label()[0] != '\0') {
			os << "+";
			for (int i = 0; i < (m_width - 2); i++) os << "-";
			os << "+" << endl;
			os << "|" << left << setw(m_width - 2) << setfill(' ') << label() << "|" << endl;
			for (int j = 0; j < (m_height - 3); j++) {
				os << "|" << left << setw(m_width - 2) << setfill(' ') << " " << "|" << endl;
			}
			os << "+";
			for (int i = 0; i < (m_width - 2); i++) os << "-";
			os << "+";
		}
	}


}