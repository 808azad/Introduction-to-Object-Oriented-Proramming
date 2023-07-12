#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstring>
#include "Menu.h"
#include "Utils.h"
using namespace std;

namespace sdds {

	void MenuItem::setEmpty() {
		m_content = nullptr;
	}

	MenuItem::MenuItem() {
		setEmpty();
	}

	MenuItem::MenuItem(const char* receivedItem) {
		if (receivedItem != nullptr && receivedItem[0] != '\0') {
			if (m_content) {
				delete[] m_content;
				m_content = nullptr;
			}
			m_content = new char[strlen(receivedItem) + 1];
			strcpy(m_content, receivedItem);
		}
		else {
			setEmpty();
		}
	}

	MenuItem::~MenuItem() {
		delete[] m_content;
		m_content = nullptr;
	}

	MenuItem::operator bool() const {
		return (m_content != nullptr && m_content[0] != '\0');
	}

	MenuItem::operator const char* () const {
		return m_content;
	}

	ostream& MenuItem::display(ostream& os) const {
		if (bool(*this)) {
			os << m_content;
		}
		return os;
	}

	Menu::Menu() {
		m_title = nullptr;
		m_count = 0;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			m_menuItems[i] = nullptr;
		}
	}

	Menu::Menu(const char* title) {
		m_title = nullptr;
		m_count = 0;
		for (unsigned int i = 0; i < MAX_MENU_ITEMS; i++) {
			m_menuItems[i] = nullptr;
		}
		if (title != nullptr && title[0] != '\0') {
			m_title = new MenuItem(title);
		}
	}

	Menu::~Menu() {
		delete m_title;
		m_title = nullptr;
		for (unsigned int i = 0; i < m_count; i++) {
			delete[] m_menuItems[i];
			m_menuItems[i] = nullptr;
		}
	}

	ostream& Menu::displayTitle()  {
		if (m_title != nullptr && m_title[0] != '\0') {
			m_title->display(cout);
			cout << ":" << endl;
		}
		return cout;
	}

	ostream& Menu::displayMenu() {
		displayTitle();
		for (unsigned int i = 0; i < m_count; i++) {
			cout << right << setw(2) << (i + 1) << "- "; 
			m_menuItems[i]->display(cout);
			cout << endl;
		}
		cout << right << setw(2) << 0 << "- Exit" << endl;
		cout << "> ";
		return cout;
	}

	unsigned int Menu::run() {
		displayMenu();
		int choice = readInt(0, m_count, "Invalid Selection, try again: ");
		return choice;
	}

	unsigned int Menu::operator~() {
		return run();
	}

	Menu& Menu::operator<<(const char* menuItemContent) {
		if (menuItemContent != nullptr && menuItemContent[0] != '\0' && m_count < MAX_MENU_ITEMS) {
			m_menuItems[m_count] = new MenuItem(menuItemContent);
		    m_count++;
		}
		return *this;
	}

	Menu::operator int() const {
		return m_count;
	}

	Menu::operator unsigned int() const {
		return unsigned(m_count);
	}

	 ostream& Menu::operator<<(ostream& os) {
		 m_title->display(os);
		 return os;
	 }

	Menu::operator bool() {
		return m_count > 0;
	}

	const char* Menu::operator[](unsigned int index) const {
		return m_menuItems[index % m_count]->m_content;
	}
		

}