#include <iostream>
#include "cstring.h"
#include "LabelMaker.h"
using namespace std;


namespace sdds {

	LabelMaker::LabelMaker(int noOfLabels) {
		labels = nullptr;
		labelNum = 0;
		if (noOfLabels > 0) {
			labelNum = noOfLabels;
			labels = new Label[labelNum];
		}
	}

	void LabelMaker::readLabels() {
		int i;
		if (labels && labelNum > 0) {
			cout << "Enter " << labelNum << " labels:" << endl;
			for (i = 0; i < labelNum; i++) {
				cout << "Enter label number " << i + 1 << endl;
				cout << "> ";
				labels[i].readLabel();
			}
		}
	}

	void LabelMaker::printLabels() {
		int j;
		if (labels && labelNum > 0) {
			for (j = 0; j < labelNum; j++) {
				labels[j].printLabel();
			}
		}
	}

	LabelMaker::~LabelMaker() {
		delete[] labels;
	}

}
