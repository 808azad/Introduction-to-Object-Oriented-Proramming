#include <iostream>
#include "cstring.h"
#include "Item.h"
#include <iomanip>
using namespace std;
namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 20);
		m_itemName[20] = '\0';  
	}

	void Item::setEmpty() {
		m_itemName[0] = '\0';
		m_price = 0.0;
	}

	void Item::set(const char* name, double price, bool taxed) {
		if (price < 0 || name == nullptr) {
			setEmpty();
		} 
		else {
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price() const {
		return m_price;
	}

	double Item::tax() const {
		const double taxRate = 0.13;
		double amountOfTax = 0.0;
		if (m_taxed) {
			amountOfTax = m_price * taxRate;
		}
		return amountOfTax;
	}

	bool Item::isValid() const {
		bool done = false;
		if (m_price > 0.0 && m_itemName != nullptr) {
			done = true;
		}
		return done;
	}

	void Item::display() const {
		if (isValid()) {
			cout << "| " << left << setw(20) << setfill('.') << m_itemName << " | ";
			cout << right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price << " | ";
			cout << ((tax() > 0.0) ? "Yes" : "No ") << " |" << endl;
		}
		else {
			cout << "| " << "xxxxxxxxxxxxxxxxxxxx" << " | ";
			cout << "xxxxxxx" << " | ";
			cout << "xxx" << " |" << endl;
		}
	}

}