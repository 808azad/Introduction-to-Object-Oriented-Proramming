#ifndef SDDS_MARK_H
#define SDDS_MARK_H

#include <iostream>

namespace sdds {

	class Mark {
		int mark;
		/*char grade;
		double scale4Mark;*/
		void setEmpty();
	public:
		Mark();
		Mark(int newMark);
		operator bool() const;
		operator int() const;
		operator double() const;
		operator char() const;
		Mark& operator+=(int val);
		Mark& operator=(int val);
	};
	int operator+=(int& val, Mark& marks);

}

#endif // !SDDS_MARK_H
