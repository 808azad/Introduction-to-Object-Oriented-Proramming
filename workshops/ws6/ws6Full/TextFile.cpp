#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {

    Line::operator const char* () const {
        return (const char*)m_value;
    }

    Line& Line::operator=(const char* lineValue) {
        if (m_value) delete[] m_value; m_value = nullptr;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }

    Line::~Line() {
        delete[] m_value;
    }

    void TextFile::setEmpty() {
        delete[] m_textLines; 
        m_textLines = nullptr;
        delete[] m_filename; 
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (isCopy) {
            m_filename = new char[strLen(fname) + 3];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
        else {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        ifstream file(m_filename);
        if (!m_filename || !file) {
            m_noOfLines = 0;
            delete[] m_filename;
            m_filename = nullptr;
        }
        else {
            char ch;
            bool isNewLine = true;
            while (file.get(ch)) {
                if (ch == '\n') {
                    m_noOfLines++;
                    isNewLine = true;
                }
                else {
                    isNewLine = false;
                }
            }
            if (!isNewLine) m_noOfLines++;
            file.close();
        }
        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText() {
        if (m_filename != nullptr) {
            ifstream file(m_filename);
            if (!file) {
                m_noOfLines = 0;
                delete[] m_filename;
                m_filename = nullptr;
            }
            else {
                setNoOfLines();
                m_textLines = new Line[m_noOfLines];
                string line;
                unsigned lineIndex = 0;
                while (getline(file, line)) {
                    m_textLines[lineIndex] = line.c_str();
                    lineIndex++;
                }
                file.close();
                m_noOfLines = lineIndex;
            }
        }
    }


    void TextFile::saveAs(const char* filename) const {
        if (!filename) {
            ofstream file(filename);
            if (file) {
               for (unsigned i = 0; i < m_noOfLines; i++) {
                   file << m_textLines[i];
               }
               file.close();
            }
        }
    }

    TextFile::TextFile(unsigned pageSize) {
        m_pageSize = pageSize;
        setEmpty();
    }

    TextFile::TextFile(const char* filename, unsigned pageSize) {
        m_pageSize = pageSize;
        setEmpty();
        if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& txtFile) {
        setEmpty();
        if (txtFile.m_noOfLines > 0) {
            m_pageSize = txtFile.m_pageSize;
            setFilename(txtFile.m_filename, true);
            saveAs(txtFile.m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& txtFile) {
        if (this != &txtFile) {
            if (m_noOfLines > 0 && txtFile.m_noOfLines > 0) {
                delete[] m_textLines;
                m_textLines = nullptr;
                setEmpty();
                setFilename(txtFile.m_filename);
                saveAs(txtFile.m_filename);
                setNoOfLines();
                loadText();
            }
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_textLines;
        delete[] m_filename;
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    ostream& TextFile::view(ostream& ostr) const {
        if (m_filename && m_noOfLines > 0) {
            ostr << m_filename << endl;
            for (int i = 0; i < strLen(m_filename); i++) {
                ostr << '=';
            }
            ostr << endl;
            for (unsigned j = 0; j < m_noOfLines; j++) {
                ostr << m_textLines[j] << endl;
                if ((j + 1) % m_pageSize == 0) {
                    if (j == 14) ostr << "Hit ENTER to continue..." << endl;
                    else ostr << "Hit ENTER to continue...";
                    ostr.flush();
                    cin.ignore();
                }
            }
        }
        return ostr;
    }

    istream& TextFile::getFile(istream& istr) {
        char filename[250];
        istr >> filename;
        setFilename(filename);
        setNoOfLines();
        loadText();
        return istr;
    }

    const char* TextFile::operator[](unsigned index) const {
        if (m_noOfLines == 0) {
            return nullptr;
        }
        index %= m_noOfLines;
        return m_textLines[index];
    }

    TextFile::operator bool() const {
        bool res = false;
        if (m_filename) res = true;
        return res;
    }

    const char* TextFile::name() const {
        return m_filename;
    }

    ostream& operator<<(ostream& ostr, const TextFile& text) {
        text.view(ostr);
        return ostr;
    }

    istream& operator>>(istream& istr, TextFile& text) {
        text.getFile(istr);
        return istr;
    }

}
