#include "Mark.h"

namespace sdds {

	void Mark::setEmpty() {
		mark = -1;
	}

	Mark::Mark() {
		mark = 0;
	}

	Mark::Mark(int newMark) {
		if (newMark >= 0 && newMark <= 100) {
			mark = newMark;
		}
		else{
			setEmpty();
		}
	}

	Mark::operator bool() const {
		return mark >= 0 && mark <= 100;
	}

	Mark::operator int() const {
		return *this ? mark : 0;
	}

	Mark& Mark::operator+=(int val) {
		if (*this) {
			mark += val;
			if (mark < 0 || mark > 100) {
				setEmpty();
			}
		}
		return *this;
	}

	Mark& Mark::operator=(int val) {
		if (!(*this) || (*this)) {
			mark = val;
		}
		else {
			setEmpty();
		}
		return *this;
	}

	Mark::operator double() const {
		double scale = 0.0;
		if (mark >= 0 && mark < 50) {
			scale = 0.0;
		}
		else if (mark >= 50 && mark < 60) {
			scale = 1.0;
		}
		else if (mark >= 60 && mark < 70) {
			scale = 2.0;
		}
		else if (mark >= 70 && mark < 80) {
			scale = 3.0;
		}
		else if (mark >= 80 && mark <= 100) {
			scale = 4.0;
		}
		return scale;
	}

	Mark::operator char() const {
		char letterGrade = 'X';
		if (mark >= 0 && mark < 50) {
			letterGrade = 'F';
		}
		else if (mark >= 50 && mark < 60) {
			letterGrade = 'D';
		}
		else if (mark >= 60 && mark < 70) {
			letterGrade = 'C';
		}
		else if (mark >= 70 && mark < 80) {
			letterGrade = 'B';
		}
		else if (mark >= 80 && mark <= 100) {
			letterGrade = 'A';
		}
		return letterGrade;
	}

	int operator+=(int& val, const Mark& marks) {
		if (marks.operator bool()) {
			val += int(marks);
		}
		return val;
	}
}
