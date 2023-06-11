#include <iostream>
#include <iomanip>
#include "Label.h"
#include "cstring.h"
using namespace std;

namespace sdds {

	Label::Label() {
		frame = "+-+|+-+|";
		labelContent = nullptr;
	}

	Label::Label(const char* frameArg) {
		frame = frameArg;
		labelContent = nullptr;
	}
	
	Label::Label(const char* frameArg, const char* content) {
		frame = frameArg;
		labelContent = nullptr;
		if (content != nullptr && content[0] != '\0') {
			labelContent = new char[strLen(content) + 1];
			strnCpy(labelContent, content, 70);
		}
	}
	const char* Label::getLabelContent() const {
		return labelContent;
	}

	Label::~Label() {
		delete[] labelContent;
		labelContent = nullptr;
	}

	void Label::readLabel() {
		char readContent[71];
		cin.getline(readContent, 71);
		if (labelContent) {
			delete[] labelContent;
			labelContent = nullptr;
		}
		labelContent = new char[strLen(readContent) + 1];
		strnCpy(labelContent, readContent, 70);
	}

	ostream& Label::printLabel() const {
		char content[71];
		content[0] = '\0';
		if (labelContent != nullptr) {
			cout << frame[0];
			for (int i = 0; i < strLen(labelContent) + 2; i++) {
				cout << frame[1];
			}
			cout << frame[2] << endl;
			for (int j = 0; j < 3; j++) {
				if (j != 1) {
					cout << left << setw(strLen(labelContent) + 3) << setfill(' ') << frame[3];
				}
				if (j == 1) {
					cout << frame[7];
				}
				if (content[0] == '\0' && j == 1) {
					strnCpy(content, labelContent, 70);
					cout << " " << content << " ";
				}
				cout << frame[7];
				cout << '\n';
			}
			cout << frame[6];
			for (int k = 0; k < strLen(labelContent) + 2; k++) {
				cout << frame[5];
			}
			cout << frame[4] << endl;
		}
		return cout;
	}
}