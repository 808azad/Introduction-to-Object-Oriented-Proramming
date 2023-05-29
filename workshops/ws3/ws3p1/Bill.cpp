#include <iostream>
#include <iomanip>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {

	void Bill::setEmpty() {
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid() const {
		bool done = false;
		int i;
		if (m_title[0] != '\0' && m_items != nullptr) {
			for (i = 0; i < m_noOfItems; i++) {
				if (m_items[i].isValid()) {
					done = true;
				}
			}
		}
		return done;
	}

	double Bill::totalTax() const {
		int i;
		double sumOfTax = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			sumOfTax += m_items[i].tax();
		}
		return sumOfTax;
	}

	double Bill::totalPrice() const {
		int i;
		double sum = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			sum += m_items[i].price();
		}
		return sum;
	}

	void Bill::Title() const {
		cout << "+--------------------------------------+" << endl;
		if (isValid()) {
			cout << "| " << left << setw(36) << setfill(' ') << m_title << " |" << endl;
		}
		else {
			cout << "| " << left << setw(36) << setfill(' ') << "Invalid bill" << " |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer() const {
		if (isValid()) {
			cout << "|                Total Tax: " << right << setw(10) 
			<< fixed << setprecision(2) << totalTax() << " |" << endl;
			cout << "|              Total Price: " << right << setw(10)
			<< fixed << setprecision(2) << totalPrice() << " |" << endl;
			cout << "|          Total After Tax: " << right << setw(10)
			<< fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;
		}
		else {
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems) {
		if (title[0] == '\0' || noOfItems <= 0) {
			setEmpty();
		}
		else {
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (int i = 0; i < m_noOfItems; i++) {
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool done = false;
		if (m_itemsAdded < m_noOfItems) {
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded++;
			done = true;
		}
		return done;
	}

	void Bill::display() const {
		int i;
		Title();
		for (i = 0; i < m_noOfItems; i++) {
			 m_items[i].display();
		}
		footer();
	}

	void Bill::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}

}