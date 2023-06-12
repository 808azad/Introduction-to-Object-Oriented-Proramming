#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
using namespace std;

namespace sdds {

	class Label {
		const char* frame;
		char* labelContent;
	public:
		Label();
		Label(const char* frameArg);
		Label(const char* frameArg, const char* content);
		~Label();
		void readLabel();
		ostream& printLabel() const;
	};

}
#endif // !SDDS_LABEL_H

