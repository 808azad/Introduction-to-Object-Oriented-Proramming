#ifndef SDDS_SHOPPINGLIST
#define SDDS_SHOPPINGLIST

#include <iostream>

namespace sdds {
	
	const int MAX_NO_OF_RECS = 15;

	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif // !SDDS_SHOPPINGLIST

