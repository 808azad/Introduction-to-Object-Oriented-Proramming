#include <fstream>
#include "Text.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   
    int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
    }

    void Text::setToSafeState() {
        if (m_filename) {
            delete[] m_filename;
        }
        m_filename = nullptr;
        if (m_content) {
            delete[] m_content;
        }
        m_content = nullptr;
    }

    Text::Text() {
        setToSafeState();
    }

    Text::Text(const char* filename) {
        if (filename != nullptr && filename[0] != '\0') {
            m_filename = new char[strLen(filename) + 1];
            strCpy(m_filename, filename);
            read();
        }
        else {
            setToSafeState();
        }
    }

    Text::operator bool() const {
        return (m_filename != nullptr && m_filename[0] != '\0' && m_content != nullptr && m_content[0] != '\0');
    }

    const char& Text::operator[](int index) const {
        char defaultValue = '\0';
        int len = strLen(m_content);
        return (m_content && index >= 0 && index < len) ? m_content[index] : defaultValue;
    }

    Text::Text(const Text& text) {
        if (bool(text)) {
            m_filename = new char[strLen(text.m_filename) + 1];
            strCpy(m_filename, text.m_filename);
            m_content = new char[strLen(text.m_content) + 1];
            strCpy(m_content, text.m_content);
        }
    }

    Text& Text::operator=(const Text& text) {
        if (this != &text) {
            if (bool(text)) {
                if (m_filename) {
                    delete[] m_filename;
                    m_filename = nullptr;
                }
                m_filename = new char[strLen(text.m_filename) + 1];
                strCpy(m_filename, text.m_filename);
                if (m_content) {
                    delete[] m_content;
                    m_content = nullptr;
                }
                m_content = new char[strLen(text.m_content) + 1];
                strCpy(m_content, text.m_content);
            }
        }
        return *this;
    }

    void Text::read() {
        int fileSize = getFileLength();
        if (fileSize > 0) {
            ifstream file(m_filename, ios::binary);
            if (file.is_open()) {
                m_content = new char[fileSize + 1];
                file.read(m_content, fileSize);
                m_content[fileSize] = '\0';
                file.close();
            }
            else {
                setToSafeState();
            }
        }
        else{
            setToSafeState();
        }
    }

    Text::~Text() {
        setToSafeState();
    }

    void Text::write(ostream& os = cout) const {
        if (m_content) os << m_content;
    }

    ostream& operator<<(ostream& os, const Text& text) {
        text.write(os);
        return os;
    }

}