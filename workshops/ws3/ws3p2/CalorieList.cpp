#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "CalorieList.h"
using namespace std;

namespace sdds {

	void CalorieList::setEmpty() {
		items = nullptr;
		noOfItems = 0;
		itemsAdded = 0;
	}

	bool CalorieList::isValid() const {
		bool done = false;
		int i;
		if (items != nullptr && itemsAdded == noOfItems) {
			done = true;
			for (i = 0; i < noOfItems; i++) {
				done = done && items[i].isValid();
			}
		}
		return done;
	}

	int CalorieList::totalCals() const {
		int i;
		int totalOfCalories = 0;
		for (i = 0; i < noOfItems; i++) {
			totalOfCalories += items[i].calories();
		}
		return totalOfCalories;
	}

	void CalorieList::title() const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "| " << left << setw(50) << setfill(' ') << " Daily Calorie Consumption" << " |" << endl;
		}
		else {
			cout << "| " << left << setw(50) << "Invalid Calorie Consumption list" << " |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer() const {
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {
			cout << "| " << right << setw(28) << "Total Calories for today:";
			cout << right << setw(9) << totalCals() << " | ";
			cout << right << setw(12) << setfill(' ') << " |" << endl;
		}
		else {
			cout << "| " << left << setw(50) << setfill(' ') << "    Invalid Calorie Consumption list" << " |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}

	void CalorieList::init(int size) {
		if (size <= 0) {
			setEmpty();
		}
		else {
			noOfItems = size;
			itemsAdded = 0;
			items = new Food[noOfItems];
			for (int i = 0; i < noOfItems; i++) {
				items[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* itemName, int calories, int when) {
		bool done = false;
		if (itemsAdded < noOfItems) {
			items[itemsAdded].set(itemName, calories, when);
			itemsAdded++;
			done = true;
		}
		return done;
	}

	void CalorieList::display() const {
		int i;
		title();
		for (i = 0; i < noOfItems; i++) {
			items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] items;
		items = nullptr;
	}

}