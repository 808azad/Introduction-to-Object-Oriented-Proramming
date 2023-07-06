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
        if (m_textLines) { delete[] m_textLines; }
        m_textLines = nullptr;
        if (m_filename) { delete[] m_filename; }
        m_filename = nullptr;
        m_noOfLines = 0;
    }

    bool TextFile::IsValid() const {
        return (m_pageSize > 0 && m_noOfLines > 0 && m_textLines != nullptr && m_filename != nullptr);
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {
        if (!isCopy) {
            if (m_filename) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
        }
        else {
            if (m_filename) {
                delete[] m_filename;
                m_filename = nullptr;
            }
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, "C_");
            strCat(m_filename, fname);
        }
    }

    void TextFile::setNoOfLines() {
        ifstream file(m_filename);
        if (!file) cout << "Failed to open a file at step 1" << endl;
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
        if (!m_filename) {
            if (m_textLines) {
                delete[] m_textLines;
                m_textLines = nullptr;
            }
            ifstream file(m_filename);
            if (!file) cout << "Failed to open a file at step 2" << endl;
            else {
                m_textLines = new Line[m_noOfLines];
                string line;
                unsigned lineIndex = 0;
                while (getline(file, line)) {
                    m_textLines[lineIndex] = line.c_str();
                    lineIndex++;
                }
                m_noOfLines = lineIndex;
                file.close();
            }
        }
    }

    void TextFile::saveAs(const char* filename) const {
        if (!filename) {
            ofstream file(filename);
            if (!file) cout << "Failed to open a file at step 3" << endl;
            else {
                for (int i = 0; i < m_noOfLines; i++) {
                    file << m_textLines[i] << endl;
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
            setFilename(filename, true); //poxu cixsa bura bax
            setNoOfLines();
            loadText();
        }
    }

    TextFile::TextFile(const TextFile& txtFile) {
        m_pageSize = txtFile.m_pageSize;
        setEmpty();
        if (txtFile.IsValid()) { //poxu cixsa burada bax
            setFilename(txtFile.m_filename, true);
            saveAs(txtFile.m_filename);
            setNoOfLines();
            loadText();
        }
    }

    TextFile& TextFile::operator=(const TextFile& txtFile) {
        if (this != &txtFile) {
            if (IsValid() && txtFile.IsValid()) {
                if (m_textLines) {
                    delete[] m_textLines;
                    m_textLines = nullptr;
                }
                setFilename(txtFile.m_filename, true);
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
        if (IsValid()) {
            ostr << m_filename << endl;
            for (int i = 0; i < strLen(m_filename); i++) {
                ostr << '=';
            }
            ostr << endl;
            unsigned lines = 0;
            for (int j = 0; j < m_noOfLines; j++) {
                ostr << m_textLines[j] << endl;
                lines++;
                if (lines == m_pageSize) {
                    ostr << "Hit ENTER to continue...";
                    ostr.flush();
                    cin.ignore(numeric_limits <streamsize>::max(), '\n');
                    lines = 0;
                }
            }
        }
        return ostr;
    }

    istream& TextFile::getFile(istream& istr) {
        char* filename = nullptr;
        cin >> filename;
        setFilename(filename, true);
        setNoOfLines();
        loadText();
        return istr;
    }
    const char* TextFile::operator[](unsigned index) const {
        if (IsValid()) {
            index %= m_noOfLines;
        }
        return ((IsValid()) ? m_textLines[index] : nullptr);
    }

    TextFile::operator bool() const {
        bool res = false;
        if (IsValid()) res = true;
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