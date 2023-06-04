#ifndef SDDS_CALORIELIST_H
#define SDDS_CALORIELIST_H
#include "Food.h"

namespace sdds {

	class CalorieList {
		Food* items;
		int noOfItems;
		int itemsAdded;
		void setEmpty();
		bool isValid() const;
		int totalCals() const;
		void title() const;
		void footer() const;
	public:
		void init(int size);
		bool add(const char* itemName, int calories, int when);
		void display() const;
		void deallocate();
	};

}
#endif // !CALORIELIST_H
