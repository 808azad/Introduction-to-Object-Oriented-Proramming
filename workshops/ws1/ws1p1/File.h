#ifndef SDDS_FILE
#define SDDS_FILE

#include <iostream>
#include "ShoppingRec.h"

namespace sdds {

	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);

}


#endif // !SDDS_FILE

