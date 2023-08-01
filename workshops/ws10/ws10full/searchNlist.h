#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H

#include "Collection.h"
using namespace std;

namespace sdds {
	
	//search function template
	//A reference to a Collection of templated objects(template type 1).The Collection is defined in Collection.h
	//An array of templated objects; the same type as the Collection type. (template type 1)
	//Number of elements in the array of objects
	//A key templated value to search for, in the array of objects. (template type 2)
	//The search function template returns a bool that is true only if at least one match to the key is found in the array of objects and false otherwise.
	//
	//The search function goes through all the elements of the array of objects and adds all the matches found to the Collection. (use the "==" operator to check for a match between the objects and the key)



   /* In order to make this template function work properly, first of all, a boolean variable with the value of "false" must be declared.
	* Then, in a loop that runs up to the number of element in the array, each element of the array of any type must be compared to a search value of any type
	* if there is at least one match, the element of the array is added to the Collection object of any type and boolean value is changed to "true"
	* At the end, the boolean value must be returned */
	template <typename T, typename Z>
	bool search(Collection<T>& obj, const T arr[], int noOfElements, const Z searchValue) {
		bool res = false;
		for (int i = 0; i < noOfElements; i++) {
			if (arr[i] == searchValue) {
				obj.add(arr[i]);
				res = true;
			}
		}
		return res;
	}


	//listArrayElements function template
  /*A const char* for a Title to be printed as the Title of the list.
	A constant array of templated objects(template type)
	The number of the elements of the array.
	This function first prints the Title and then goes to newline.
	Then it will print the row number and then insert each element of the array into cout with a newline attached.
	For example, if this function is called for the following array of integers.*/

	/* In order to make this template function work properly, first of all, a value of passed title argument must be checked for containing null pointer anb a null value.
	* if the title is valid, it will print it
	* Then, in a loop that runs up to the number of elements in the array of any type, the elements of the array must be displayed to the console one by one in a newline*/
	template <typename T>
	void listArrayElements(const char* title, const T arr[], int noOfElements) {
		if (title != nullptr && title[0] != '\0') {
			cout << title << endl;
		}
		for (int i = 0; i < noOfElements; i++) {
			cout << (i + 1) << ": " << arr[i] << endl;
		}
	}
}

#endif // !SDDS_SEARCHNLIST_H
