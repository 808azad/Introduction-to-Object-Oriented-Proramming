#include <iomanip>
#include "cstring.h"
#include "HtmlText.h"
using namespace std;

namespace sdds {

	HtmlText::HtmlText() : Text() {
		m_title = nullptr;
	}

	HtmlText::HtmlText(const char* filename) : Text(filename) {}

	HtmlText::HtmlText(const char* filename, const char* title) : Text(filename) {
		if (title != nullptr && title[0] != '\0') {
			m_title = new char[strLen(title) + 1];
			strCpy(m_title, title);
		}
		else {
			setToSafeState();
			m_title = nullptr;
		}
	}

	HtmlText::operator bool() const {
		return (m_title != nullptr && m_title[0] != '\0');
	}

	HtmlText::HtmlText(const HtmlText& html) : Text(html) {
		if (bool(html)) {
			m_title = new char[strLen(html.m_title) + 1];
			strCpy(m_title, html.m_title);
		}
	}

	HtmlText& HtmlText::operator=(const HtmlText& html) {
		if (this != &html) {
			if (bool(html)) {
				Text::operator=(html);
				if (m_title) {
					delete[] m_title;
					m_title = nullptr;
				}
				m_title = new char[strLen(html.m_title) + 1];
				strCpy(m_title, html.m_title);
			}
		}
		return *this;
	}

	HtmlText::~HtmlText() {
		delete[] m_title;
		m_title = nullptr;
	}

	void HtmlText::write(std::ostream& os) const {
		bool MS = false;
		os << "<html><head><title>";
		if (*this) {
			os << m_title;
		}
		else {
			os << "No Title";
		}
		os << "</title></head>\n<body>\n";
		if (*this) {
			os << "<h1>" << m_title << "</h1>\n";
		}
		for (int i = 0; (*this)[i]; i++) {
			switch ((*this)[i]) {
			case ' ':
				if (MS) {
					os << "&nbsp;";
				}
				else {
					MS = true;
					os << ' ';
				}
				break;
			case '<':
				os << "&lt;";
				MS = false;
				break;
			case '>':
				os << "&gt;";
				MS = false;
				break;
			case '\n':
				os << "<br />\n";
				MS = false;
				break;
			default:
				os << (*this)[i];
				MS = false;
				break;
			}
		}
		os << "</body>\n</html>";
	}

}

