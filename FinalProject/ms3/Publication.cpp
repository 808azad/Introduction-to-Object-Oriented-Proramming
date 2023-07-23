#include <iomanip>
#include "Publication.h"
using namespace std;

namespace sdds {

	Publication::Publication() : m_date() {
		m_title = nullptr;
		m_shelfiId[0] = '\0';
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

	}
}