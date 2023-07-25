#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iomanip>
#include "Publication.h"
using namespace std;

namespace sdds {

	Publication::Publication() : m_date() {
		m_title = nullptr;
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
	}

	void Publication::set(int member_id) {
		if (member_id == 0 || member_id >= 10000) {
			m_membership = member_id;
		}
	}

	void Publication::setRef(int value) {
		if (value >= 0) m_libRef = value;
	}

	void Publication::resetDate(){
		m_date = Date();
	}

	char Publication::type() const {
		char p = 'P';
		return p;
	}

	bool Publication::onLoan() const {
		return m_membership > 0;
	}

	Date Publication::checkoutDate() const {
		return m_date;
	}

	bool Publication::operator==(const char* title) const {
		bool res = false;
		if (title != nullptr && title[0] != '\0') {
			if (strstr(m_title, title) != nullptr) res = true;
		}
		return res;
	}

	Publication::operator const char* () const {
		return m_title;
	}

	int Publication::getRef() const {
		return m_libRef;
	}

	bool Publication::conIO(ios& io) const {
		return (&io == &cin || &io == &cout);
	}

	ostream& Publication::write(ostream& os = cout) const {
		if (conIO(os)) {
			if (*this) {
				os << "| " << m_shelfId << " | ";
				os << left << setw(30) << setfill('.') << m_title;
				os << " | ";
				if (onLoan()) {
					os << m_membership;
				}
				else {
					os << " N/A ";
				}
				os << " | " << m_date << " | ";
			}
		}
		else {
			os << type() << '\t' << m_libRef << "\t" << m_title << "\t" << m_membership << "\t" << m_date;
		}
		return os;
	}

	istream& Publication::read(istream& istr) {
		char shelfId[SDDS_SHELF_ID_LEN + 1];
		char buffer[100];
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
		m_shelfId[0] = '\0';
		m_membership = 0;
		m_libRef = -1;
		resetDate();
		if (conIO(istr)) {
			cout << "Shelf No: ";
			istr.getline(shelfId, SDDS_SHELF_ID_LEN + 1);
			if (strlen(shelfId) != SDDS_SHELF_ID_LEN){
				istr.setstate(ios::failbit);
			}
			else {
				strncpy(m_shelfId, shelfId, SDDS_SHELF_ID_LEN);
				cout << "Title: ";
				istr.getline(buffer, 100);
				m_title = new char[strlen(buffer) + 1];
				strcpy(m_title, buffer);
				cout << "Date: ";
				m_date.read(istr);
			}
		}
		else {
			int libref;
			istr >> libref;
			setRef(libref);
			istr.ignore();
			istr.getline(shelfId, 5, '\t');
			for (int i = 0; i < strlen(shelfId); i++) {
				m_shelfId[i] = shelfId[i];
			}
			istr.getline(buffer, 100, '\t');
			m_title = new char[strlen(buffer) + 1];
			strcpy(m_title, buffer);
			int membership;
			istr >> membership;
			set(membership);
			istr.ignore();
			m_date.read(istr);
		}
		if (!bool(m_date)) {
			istr.setstate(ios::failbit);
		}

		return istr;
	}


	Publication::operator bool() const {
		return (m_title != nullptr && m_title[0] != '\0' && m_shelfId[0] != '\0' && bool(m_date));
	}

	Publication::Publication(const Publication& pbl) {
		if (bool(pbl)) {
			m_title = new char[strlen(pbl.m_title) + 1];
			strcpy(m_title, pbl.m_title);
			for (int i = 0; i < strlen(pbl.m_shelfId); i++) {
				m_shelfId[i] = pbl.m_shelfId[i];
			}
			set(pbl.m_membership);
			setRef(pbl.m_libRef);
			m_date = pbl.m_date;
		}
	}

	Publication& Publication::operator=(const Publication& pbl) {
		if (this != &pbl) {
			if (bool(pbl)) {
				if (m_title) {
					delete[] m_title;
					m_title = nullptr;
				}
				m_title = new char[strlen(pbl.m_title) + 1];
				strcpy(m_title, pbl.m_title);
				for (int i = 0; i < strlen(pbl.m_shelfId); i++) {
					m_shelfId[i] = pbl.m_shelfId[i];
				}
				set(pbl.m_membership);
				setRef(pbl.m_libRef);
				m_date = pbl.m_date;
			}
		}
		return *this;
	}

	Publication::~Publication() {
		if (m_title) {
			delete[] m_title;
			m_title = nullptr;
		}
	}
}