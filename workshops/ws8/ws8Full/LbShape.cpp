#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "LbShape.h"
using namespace std;

namespace sdds {

	LbShape::LbShape() {
		m_label = nullptr;
	}

	LbShape::LbShape(const char* label) {
		if (label != nullptr && label[0] != '\0') {
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}
	}

	LbShape::~LbShape() {
		if (m_label) {
			delete[] m_label;
			m_label = nullptr;
		}
	}
	const char* LbShape::label() const {
		return m_label;

	}

	void LbShape::getSpecs(istream& is = cin) {
		if (m_label) {
			delete[] m_label;
			m_label = nullptr;
		}
		char input[300];
		is.getline(input, 300, ',');
		if (input[0] != '\0') {
			m_label = new char[strlen(input) + 1];
			strcpy(m_label, input);
		}
	}

}