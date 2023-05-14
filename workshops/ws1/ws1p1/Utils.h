#ifndef SDDS_UTILS
#define SDDS_UTILS

#include <iostream>

namespace sdds {
	void flushkeys();
	bool ValidYesResponse(char ch);
	bool yes();
	void readCstr(char cstr[], int len);
	int readInt(int min, int max);
}



#endif // !SDDS_UTILS

