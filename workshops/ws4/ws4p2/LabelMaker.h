#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "Label.h"

namespace sdds {

	class LabelMaker {
		Label* labels;
		int labelNum;
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
	};
}


#endif // !SDDS_LABEL_H