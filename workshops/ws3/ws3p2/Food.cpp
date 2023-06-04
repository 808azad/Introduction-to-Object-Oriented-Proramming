#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Food.h"
using namespace std;

namespace sdds {

	void Food::setName(const char* name) {
		strnCpy(foodName, name, 30);
		foodName[30] = '\0';
	}

	void Food::setEmpty() {
		foodName[0] = '\0';
		noOfCalories = 0;
		consumptionTime = 0;
	}

	void Food::set(const char* name, int size, int time) {
		if (name == nullptr || (size <= 0 || size > 3000) || (time <= 0 || time > 4)) {
			setEmpty();
		}
		else {
			setName(name);
			noOfCalories = size;
			consumptionTime = time;
		}
	}

	int Food::calories() const {
		return noOfCalories;
	}

	int Food::consumption() const {
		int dayTime = 0;
		if (consumptionTime == 1) {
			dayTime = 1;
		}
		else if (consumptionTime == 2) {
			dayTime = 2;
		}
		else if (consumptionTime == 3) {
			dayTime = 3;
		}
		else if (consumptionTime == 4) {
			dayTime = 4;
		}
		return dayTime;
	}

	bool Food::isValid() const {
		bool done = false;
		if (foodName != nullptr && !(noOfCalories <= 0 || noOfCalories > 3000) && !(consumptionTime <= 0 || consumptionTime > 4)) {
			done = true;
		}
		return done;
	}

	void Food::display() const {
		if (isValid()) {
			cout << "| " << left << setw(30) << setfill('.') << foodName << " | ";
			cout << right << setw(4) << setfill(' ') << noOfCalories << " | ";
			if (consumptionTime == 1) {
				cout << left << setw(10) << setfill(' ') << "Breakfast";
			}
			else if (consumptionTime == 2) {
				cout << left << setw(10) << setfill(' ') << "Lunch";
			}
			else if (consumptionTime == 3) {
				cout << left << setw(10) << setfill(' ') << "Dinner";
			}
			else if (consumptionTime == 4){
				cout << left << setw(10) << setfill(' ') << "Snack";
			}
			cout << " |" << endl;;
		}
		else {
			cout << "| " << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx" << " | ";
			cout << "xxxx" << " | ";
			cout << "xxxxxxxxxx" << " |" << endl;
		}
	}

}